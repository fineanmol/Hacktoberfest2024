package com.android.launcher3.icons.pack;

import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.os.Handler;
import android.util.Log;

import static com.android.launcher3.util.Executors.MODEL_EXECUTOR;

import com.android.launcher3.LauncherModel;
import com.android.launcher3.util.ComponentKey;

import org.xmlpull.v1.XmlPullParserException;

import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import com.android.launcher3.customization.IconDatabase;
import com.android.launcher3.util.AppReloader;

public class IconPackManager extends BroadcastReceiver {
    private static final String TAG = "IconPackManager";

    private static final String[] ICON_INTENT_ACTIONS = new String[] {
            "com.fede.launcher.THEME_ICONPACK",
            "com.anddoes.launcher.THEME",
            "com.novalauncher.THEME",
            "com.teslacoilsw.launcher.THEME",
            "com.gau.go.launcherex.theme",
            "org.adw.launcher.THEMES",
            "net.oneplus.launcher.icons.ACTION_PICK_ICON",
            "org.adw.launcher.icons.ACTION_PICK_ICON"
    };

    private static final Intent[] ICON_INTENTS = new Intent[ICON_INTENT_ACTIONS.length];
    private static IconPackManager sInstance;

    static {
        for (int i = 0; i < ICON_INTENT_ACTIONS.length; i++) {
            ICON_INTENTS[i] = new Intent(ICON_INTENT_ACTIONS[i]);
        }
    }

    public static synchronized IconPackManager get(Context context) {
        if (sInstance == null) {
            sInstance = new IconPackManager(context);
        }
        return sInstance;
    }

    private final Context mContext;
    private final Map<String, IconPack> mProviders = new HashMap<>();
    private final Handler mHandler = new Handler(MODEL_EXECUTOR.getLooper());

    private IconPackManager(Context context) {
        mContext = context;
        reloadProviders();

        IntentFilter filter = new IntentFilter();
        filter.addDataScheme("package");
        filter.addAction(Intent.ACTION_PACKAGE_ADDED);
        filter.addAction(Intent.ACTION_PACKAGE_CHANGED);
        filter.addAction(Intent.ACTION_PACKAGE_REPLACED);
        filter.addAction(Intent.ACTION_PACKAGE_FULLY_REMOVED);

        // Called when any app has been installed, enabled, disabled, updated or deleted.
        context.getApplicationContext().registerReceiver(this, filter, null, mHandler);
    }

    @Override
    public void onReceive(Context context, Intent intent) {
        if (intent.getData() != null) {
            String pkg = intent.getData().getEncodedSchemeSpecificPart();
            if (pkg != null) {
                Log.d(TAG, "Received intent action " + intent.getAction() + " for " + pkg);
                AppReloader appReloader = AppReloader.get(mContext);

                // Create a list of apps that are using the changed package icon pack,
                // either through the global setting or with an override.
                Set<ComponentKey> updateKeys = appReloader.withIconPack(pkg);

                // Remove the changed package from the providers to reload the application info.
                mProviders.remove(pkg);

                // This can reset the global preference, so do this after creating the list.
                reloadProviders();

                // Ensure all icons are up-to-date after this icon pack change.
                // Calendar and clock information will automatically be reloaded by this call.
                appReloader.reload(updateKeys);
            }
        }
    }

    private void reloadProviders() {
        PackageManager pm = mContext.getPackageManager();
        Set<ResolveInfo> info = new HashSet<>();
        for (Intent intent : ICON_INTENTS) {
            info.addAll(pm.queryIntentActivities(intent, PackageManager.GET_META_DATA));
        }

        // Remove unavailable packs
        for (String packageName : mProviders.keySet().toArray(new String[0])) {
            boolean foundPackageName = false;
            for (ResolveInfo ri : info) {
                if (ri.activityInfo.packageName.equals(packageName)) {
                    foundPackageName = true;
                    break;
                }
            }
            if (!foundPackageName) {
                mProviders.remove(packageName);
            }
        }

        // Add new packs
        for (ResolveInfo ri : info) {
            String packageName = ri.activityInfo.packageName;
            if (!mProviders.containsKey(packageName)) {
                ApplicationInfo ai = ri.activityInfo.applicationInfo;
                CharSequence label = ai.loadLabel(pm);
                mProviders.put(packageName, new IconPack(ai, label));
            }
        }

        String global = IconDatabase.getGlobal(mContext);
        if (!global.isEmpty() && !mProviders.containsKey(global)) {
            // The global icon pack has been removed, so reset it.
            // This constraint ensures that the global icon pack is always available,
            // even if the launcher did not receive the uninstall intent.
            Log.e(TAG, "Resetting global icon pack because provider " + global + " was removed");
            IconDatabase.resetGlobal(mContext);
        }
    }

    public Map<String, CharSequence> getProviderNames() {
        Map<String, CharSequence> providerTitles = new HashMap<>();
        for (Map.Entry<String, IconPack> pack : mProviders.entrySet()) {
            providerTitles.put(pack.getKey(), pack.getValue().getTitle());
        }
        return providerTitles;
    }

    public boolean packContainsActivity(String packPackage, ComponentName componentName) {
        try {
            IconPack pack = mProviders.get(packPackage);
            IconPack.Data data = pack.getData(mContext.getPackageManager());
            return data.drawables.containsKey(componentName);
        } catch (PackageManager.NameNotFoundException | XmlPullParserException | IOException ignored) {
            return false;
        }
    }

    /**
     * Creates a resolver that can load the icon once.
     * This resolver should not be stored, as the resolution strategy could change when
     * the selected icon pack in use is uninstalled or updated.
     * @param key Component for which an icon should be extracted.
     * @return Resolver that loads the icon, or null if there is no resolution strategy.
     */
    public IconResolver resolve(ComponentKey key) {
        String packPackage = IconDatabase.getByComponent(mContext, key);
        if (mProviders.containsKey(packPackage)) {
            // The icon provider package is available.
            try {
                IconPack pack = mProviders.get(packPackage);
                IconPack.Data data = pack.getData(mContext.getPackageManager());
                if (data.drawables.containsKey(key.componentName)) {
                    int drawableId = pack.getDrawableId(mContext.getPackageManager(), key.componentName);
                    if (drawableId != 0) {
                        return new IconResolverExternal(mContext.getPackageManager(), pack.getAi(),
                                drawableId,
                                data.calendarPrefix.get(key.componentName),
                                data.clockMetadata.get(drawableId));
                    }
                }
                if (data.hasMasking()) {
                    return new IconResolverMasked(mContext, data, pack.getAi(), key.hashCode());
                }
            } catch (PackageManager.NameNotFoundException | XmlPullParserException | IOException ignored) {
            }
        } else if (!packPackage.isEmpty()) {
            // The provider is not available, save for next time.
            IconDatabase.resetForComponent(mContext, key);
        }
        return null;
    }
}
