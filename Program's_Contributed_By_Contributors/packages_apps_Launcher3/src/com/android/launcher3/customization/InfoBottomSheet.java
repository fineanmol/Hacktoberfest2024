package com.android.launcher3.customization;

import android.app.ActivityOptions;
import android.app.Fragment;
import android.app.FragmentManager;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import androidx.preference.Preference;
import androidx.preference.PreferenceFragment;
import androidx.recyclerview.widget.RecyclerView;
import android.graphics.Rect;

import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.android.launcher3.BaseDraggingActivity;
import com.android.launcher3.model.data.ItemInfo;
import com.android.launcher3.Launcher;
import com.android.launcher3.QuickstepTransitionManager;
import com.android.launcher3.R;
import com.android.launcher3.util.ActivityOptionsWrapper;
import com.android.launcher3.util.ComponentKey;
import com.android.launcher3.widget.WidgetsBottomSheet;
import com.android.launcher3.util.PackageManagerHelper;

import com.android.launcher3.settings.preference.IconPackPrefSetter;
import com.android.launcher3.settings.preference.ReloadingListPreference;
import com.android.launcher3.util.AppReloader;

import static com.android.launcher3.util.Executors.MAIN_EXECUTOR;
import static com.android.launcher3.util.Executors.THREAD_POOL_EXECUTOR;

public class InfoBottomSheet extends WidgetsBottomSheet {
    private final FragmentManager mFragmentManager;
    protected static Rect mSourceBounds;
    protected static Context mTarget;

    public InfoBottomSheet(Context context) {
        this(context, null);
    }

    public InfoBottomSheet(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public InfoBottomSheet(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        mFragmentManager = Launcher.getLauncher(context).getFragmentManager();
    }

    public void configureBottomSheet(Rect sourceBounds, Context target) {
        mSourceBounds = sourceBounds;
        mTarget = target;
    }

    @Override
    public void populateAndShow(ItemInfo itemInfo) {
        super.populateAndShow(itemInfo);
        TextView title = findViewById(R.id.title);
        title.setText(itemInfo.title);

        PrefsFragment fragment =
                (PrefsFragment) mFragmentManager.findFragmentById(R.id.sheet_prefs);
        fragment.loadForApp(itemInfo);
    }

    @Override
    public void onDetachedFromWindow() {
        Fragment pf = mFragmentManager.findFragmentById(R.id.sheet_prefs);
        if (pf != null) {
            mFragmentManager.beginTransaction()
                    .remove(pf)
                    .commitAllowingStateLoss();
        }
        super.onDetachedFromWindow();
    }

    @Override
    public void onWidgetsBound() {
    }

    public static class PrefsFragment extends PreferenceFragment
            implements Preference.OnPreferenceChangeListener, Preference.OnPreferenceClickListener {
        private static final String KEY_ICON_PACK = "pref_app_info_icon_pack";
        private static final String KEY_SOURCE = "pref_app_info_source";
        private static final String KEY_LAST_UPDATE = "pref_app_info_last_update";
        private static final String KEY_VERSION = "pref_app_info_version";
        private static final String KEY_MORE = "pref_app_info_more";

        private Context mContext;

        private ItemInfo mItemInfo;

        private ComponentName mComponent;
        private ComponentKey mKey;
        private QuickstepTransitionManager mAppTransitionManager;

        @Override
        public void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            mContext = getActivity();
            mAppTransitionManager = new QuickstepTransitionManager(mContext);
            mAppTransitionManager.registerRemoteAnimations();
            mAppTransitionManager.registerRemoteTransitions();
        }

        private QuickstepTransitionManager getAppTransitionManager() {
            return mAppTransitionManager;
        }

        public ActivityOptionsWrapper getActivityLaunchOptions(View v) {
            return mAppTransitionManager.getActivityLaunchOptions(v);
        }

        @Override
        public void onDestroy() {
            mAppTransitionManager.onActivityDestroyed();
            super.onDestroy();
        }

        @Override
        public void onCreatePreferences(Bundle savedInstanceState, String rootKey) {
            addPreferencesFromResource(R.xml.app_info_preferences);
        }

        @Override
        public RecyclerView onCreateRecyclerView(LayoutInflater inflater, ViewGroup parent,
                                                 Bundle savedInstanceState) {
            RecyclerView view = super.onCreateRecyclerView(inflater, parent, savedInstanceState);
            view.setOverScrollMode(View.OVER_SCROLL_NEVER);
            return view;
        }

        public void loadForApp(ItemInfo itemInfo) {
            mComponent = itemInfo.getTargetComponent();
            mItemInfo = itemInfo;
            mKey = new ComponentKey(mComponent, itemInfo.user);

            ReloadingListPreference icons = (ReloadingListPreference) findPreference(KEY_ICON_PACK);
            icons.setValue(IconDatabase.getByComponent(mContext, mKey));
            icons.setOnReloadListener(ctx -> new IconPackPrefSetter(ctx, mComponent));
            icons.setOnPreferenceChangeListener(this);

            THREAD_POOL_EXECUTOR.execute(() -> {
                MetadataExtractor extractor = new MetadataExtractor(mContext, mComponent);

                CharSequence source = extractor.getSource();
                CharSequence lastUpdate = extractor.getLastUpdate();
                CharSequence version = mContext.getString(
                        R.string.app_info_version_value,
                        extractor.getVersionName(),
                        extractor.getVersionCode());
                Intent marketIntent = extractor.getMarketIntent();

                MAIN_EXECUTOR.execute(() -> {
                    Preference sourcePref = findPreference(KEY_SOURCE);
                    Preference lastUpdatePref = findPreference(KEY_LAST_UPDATE);
                    Preference versionPref = findPreference(KEY_VERSION);
                    Preference morePref = findPreference(KEY_MORE);

                    sourcePref.setSummary(source);
                    lastUpdatePref.setSummary(lastUpdate);
                    versionPref.setSummary(version);
                    morePref.setOnPreferenceClickListener(this);

                    if (marketIntent != null) {
                        sourcePref.setOnPreferenceClickListener(
                                pref -> tryStartActivity(marketIntent));
                    }
                });
            });
        }

        private boolean tryStartActivity(Intent intent) {
            Launcher launcher = Launcher.getLauncher(mContext);
            Bundle opts = getAppTransitionManager()
                    .getActivityLaunchOptions(getView())
                    .toBundle();
            try {
                launcher.startActivity(intent, opts);
            } catch (Exception ignored) {
            }
            return false;
        }

        @Override
        public boolean onPreferenceChange(Preference preference, Object newValue) {
            if (newValue.equals(IconDatabase.getGlobal(mContext))) {
                IconDatabase.resetForComponent(mContext, mKey);
            } else {
                IconDatabase.setForComponent(mContext, mKey, (String) newValue);
            }
            AppReloader.get(mContext).reload(mKey);
            return true;
        }

        private void onMoreClick() {
            new PackageManagerHelper(InfoBottomSheet.mTarget).startDetailsActivityForInfo(
                        mItemInfo, InfoBottomSheet.mSourceBounds, ActivityOptions.makeBasic().toBundle());
        }

        @Override
        public boolean onPreferenceClick(Preference preference) {
            onMoreClick();
            return true;
        }
    }

    @Override
    protected boolean hasSeenEducationTip() {
        return true;
    }
}
