/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.launcher3.util;

import android.content.ActivityNotFoundException;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.LauncherActivityInfo;
import android.content.pm.LauncherApps;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.content.pm.ResolveInfo;
import android.graphics.Rect;
import android.os.Bundle;
import android.os.Process;
import android.os.UserHandle;
import android.text.TextUtils;
import android.util.Log;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.android.launcher3.PendingAddItemInfo;
import com.android.launcher3.R;
import com.android.launcher3.Utilities;
import com.android.launcher3.model.data.AppInfo;
import com.android.launcher3.model.data.ItemInfo;
import com.android.launcher3.model.data.ItemInfoWithIcon;
import com.android.launcher3.model.data.LauncherAppWidgetInfo;
import com.android.launcher3.model.data.WorkspaceItemInfo;
import com.android.launcher3.uioverrides.ApiWrapper;

import java.net.URISyntaxException;
import java.util.List;
import java.util.Objects;

/**
 * Utility methods using package manager
 */
public class PackageManagerHelper {

    private static final String TAG = "PackageManagerHelper";

    @NonNull
    private final Context mContext;

    @NonNull
    private final PackageManager mPm;

    @NonNull
    private final LauncherApps mLauncherApps;

    public PackageManagerHelper(@NonNull final Context context) {
        mContext = context;
        mPm = context.getPackageManager();
        mLauncherApps = Objects.requireNonNull(context.getSystemService(LauncherApps.class));
    }

    /**
     * Returns true if the app can possibly be on the SDCard. This is just a workaround and doesn't
     * guarantee that the app is on SD card.
     */
    public boolean isAppOnSdcard(@NonNull final String packageName,
            @NonNull final UserHandle user) {
        final ApplicationInfo info = getApplicationInfo(
                packageName, user, PackageManager.MATCH_UNINSTALLED_PACKAGES);
        return info != null && (info.flags & ApplicationInfo.FLAG_EXTERNAL_STORAGE) != 0;
    }

    /**
     * Returns whether the target app is suspended for a given user as per
     * {@link android.app.admin.DevicePolicyManager#isPackageSuspended}.
     */
    public boolean isAppSuspended(@NonNull final String packageName,
            @NonNull final UserHandle user) {
        final ApplicationInfo info = getApplicationInfo(packageName, user, 0);
        return info != null && isAppSuspended(info);
    }

    /**
     * Returns whether the target app is installed for a given user
     */
    public boolean isAppInstalled(@NonNull final String packageName,
            @NonNull final UserHandle user) {
        final ApplicationInfo info = getApplicationInfo(packageName, user, 0);
        return info != null;
    }

    /**
     * Returns whether the target app is in archived state
     */
    @SuppressWarnings("NewApi")
    public boolean isAppArchived(@NonNull final String packageName) {
        final ApplicationInfo info;
        try {
            info = mPm.getPackageInfo(packageName,
                    PackageManager.PackageInfoFlags.of(
                            PackageManager.MATCH_ARCHIVED_PACKAGES)).applicationInfo;
            return info.isArchived;
        } catch (NameNotFoundException e) {
            Log.e(TAG, "Failed to get applicationInfo for package: " + packageName, e);
            return false;
        }
    }

    /**
     * Returns the application info for the provided package or null
     */
    @Nullable
    public ApplicationInfo getApplicationInfo(@NonNull final String packageName,
            @NonNull final UserHandle user, final int flags) {
        try {
            ApplicationInfo info = mLauncherApps.getApplicationInfo(packageName, flags, user);
            return !isPackageInstalledOrArchived(info) || !info.enabled ? null : info;
        } catch (PackageManager.NameNotFoundException e) {
            return null;
        }
    }

    @Nullable
    public Intent getAppLaunchIntent(@Nullable final String pkg, @NonNull final UserHandle user) {
        List<LauncherActivityInfo> activities = mLauncherApps.getActivityList(pkg, user);
        return activities.isEmpty() ? null :
                AppInfo.makeLaunchIntent(activities.get(0));
    }

    /**
     * Returns whether an application is suspended as per
     * {@link android.app.admin.DevicePolicyManager#isPackageSuspended}.
     */
    public static boolean isAppSuspended(ApplicationInfo info) {
        return (info.flags & ApplicationInfo.FLAG_SUSPENDED) != 0;
    }

    /**
     * Creates a new market search intent.
     */
    public static Intent getMarketSearchIntent(Context context, String query) {
        try {
            Intent intent = Intent.parseUri(context.getString(R.string.market_search_intent), 0);
            if (!TextUtils.isEmpty(query)) {
                intent.setData(
                        intent.getData().buildUpon().appendQueryParameter("q", query).build());
            }
            return intent;
        } catch (URISyntaxException e) {
            throw new RuntimeException(e);
        }
    }

    /**
     * Starts the details activity for {@code info}
     */
    public void startDetailsActivityForInfo(ItemInfo info, Rect sourceBounds, Bundle opts) {
        if (info instanceof ItemInfoWithIcon
                && (((ItemInfoWithIcon) info).runtimeStatusFlags
                    & ItemInfoWithIcon.FLAG_INSTALL_SESSION_ACTIVE) != 0) {
            ItemInfoWithIcon appInfo = (ItemInfoWithIcon) info;
            mContext.startActivity(ApiWrapper.getAppMarketActivityIntent(mContext,
                    appInfo.getTargetComponent().getPackageName(), Process.myUserHandle()));
            return;
        }
        ComponentName componentName = null;
        if (info instanceof AppInfo) {
            componentName = ((AppInfo) info).componentName;
        } else if (info instanceof WorkspaceItemInfo) {
            componentName = info.getTargetComponent();
        } else if (info instanceof PendingAddItemInfo) {
            componentName = ((PendingAddItemInfo) info).componentName;
        } else if (info instanceof LauncherAppWidgetInfo) {
            componentName = ((LauncherAppWidgetInfo) info).providerName;
        }
        if (componentName != null) {
            try {
                mLauncherApps.startAppDetailsActivity(componentName, info.user, sourceBounds, opts);
            } catch (SecurityException | ActivityNotFoundException e) {
                Toast.makeText(mContext, R.string.activity_not_found, Toast.LENGTH_SHORT).show();
                Log.e(TAG, "Unable to launch settings", e);
            }
        }
    }

    public static boolean isSystemApp(@NonNull final Context context, String pkgName) {
        return isSystemApp(context, null, pkgName);
    }

    public static boolean isSystemApp(@NonNull final Context context, Intent intent) {
        return isSystemApp(context, intent, null);
    }

    public static boolean isSystemApp(@NonNull final Context context, Intent intent, String pkgName) {
        PackageManager pm = context.getPackageManager();
        String packageName = null;
        // If the intent is not null, let's get the package name from the intent.
        if (intent != null) {
            ComponentName cn = intent.getComponent();
            if (cn == null) {
                ResolveInfo info = pm.resolveActivity(intent, PackageManager.MATCH_DEFAULT_ONLY);
                if ((info != null) && (info.activityInfo != null)) {
                    packageName = info.activityInfo.packageName;
                }
            } else {
                packageName = cn.getPackageName();
            }
        }
        // Otherwise we have the package name passed from the method.
        else {
            packageName = pkgName;
        }
        // Check if the provided package is a system app.
        if (packageName != null) {
            try {
                PackageInfo info = pm.getPackageInfo(packageName, 0);
                return (info != null) && (info.applicationInfo != null) &&
                        ((info.applicationInfo.flags & ApplicationInfo.FLAG_SYSTEM) != 0);
            } catch (NameNotFoundException e) {
                return false;
            }
        } else {
            return false;
        }
    }

    /**
     * Returns true if the intent is a valid launch intent for a launcher activity of an app.
     * This is used to identify shortcuts which are different from the ones exposed by the
     * applications' manifest file.
     *
     * @param launchIntent The intent that will be launched when the shortcut is clicked.
     */
    public static boolean isLauncherAppTarget(Intent launchIntent) {
        if (launchIntent != null
                && Intent.ACTION_MAIN.equals(launchIntent.getAction())
                && launchIntent.getComponent() != null
                && launchIntent.getCategories() != null
                && launchIntent.getCategories().size() == 1
                && launchIntent.hasCategory(Intent.CATEGORY_LAUNCHER)
                && TextUtils.isEmpty(launchIntent.getDataString())) {
            // An app target can either have no extra or have ItemInfo.EXTRA_PROFILE.
            Bundle extras = launchIntent.getExtras();
            return extras == null || extras.keySet().isEmpty();
        }
        return false;
    }

    /**
     * Returns true if Launcher has the permission to access shortcuts.
     * @see LauncherApps#hasShortcutHostPermission()
     */
    public static boolean hasShortcutsPermission(Context context) {
        try {
            return context.getSystemService(LauncherApps.class).hasShortcutHostPermission();
        } catch (SecurityException | IllegalStateException e) {
            Log.e(TAG, "Failed to make shortcut manager call", e);
        }
        return false;
    }

    /** Returns the incremental download progress for the given shortcut's app. */
    public static int getLoadingProgress(LauncherActivityInfo info) {
        if (Utilities.ATLEAST_S) {
            return (int) (100 * info.getLoadingProgress());
        }
        return 100;
    }

    /** Returns true in case app is installed on the device or in archived state. */
    @SuppressWarnings("NewApi")
    private boolean isPackageInstalledOrArchived(ApplicationInfo info) {
        return (info.flags & ApplicationInfo.FLAG_INSTALLED) != 0 || (
                Utilities.enableSupportForArchiving() && info.isArchived);
    }
}
