package com.android.launcher3.util;

import android.content.Context;
import android.content.pm.LauncherActivityInfo;
import android.content.pm.ShortcutInfo;
import android.os.UserHandle;

import com.android.launcher3.LauncherAppState;
import com.android.launcher3.LauncherModel;
import android.content.pm.LauncherApps;
import android.os.UserManager;
import com.android.launcher3.util.ComponentKey;

import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import com.android.launcher3.customization.IconDatabase;

public class AppReloader {
    private static AppReloader sInstance;

    public static synchronized AppReloader get(Context context) {
        if (sInstance == null) {
            sInstance = new AppReloader(context);
        }
        return sInstance;
    }

    private final Context mContext;
    private final LauncherModel mModel;
    private final UserManager mUsers;
    private final LauncherApps mApps;

    private AppReloader(Context context) {
        mContext = context;
        mModel = LauncherAppState.getInstance(context).getModel();
        mUsers = context.getSystemService(UserManager.class);
        mApps = context.getSystemService(LauncherApps.class);
    }

    public Set<ComponentKey> withIconPack(String iconPack) {
        Set<ComponentKey> reloadKeys = new HashSet<>();
        for (UserHandle user : mUsers.getUserProfiles()) {
            for (LauncherActivityInfo info : mApps.getActivityList(null, user)) {
                ComponentKey key = new ComponentKey(info.getComponentName(), info.getUser());
                if (IconDatabase.getByComponent(mContext, key).equals(iconPack)) {
                    reloadKeys.add(key);
                }
            }
        }
        return reloadKeys;
    }

    public void reload() {
        for (UserHandle user : mUsers.getUserProfiles()) {
            Set<String> pkgsSet = new HashSet<>();
            for (LauncherActivityInfo info : mApps.getActivityList(null, user)) {
                pkgsSet.add(info.getComponentName().getPackageName());
            }
            for (String pkg : pkgsSet) {
                reload(user, pkg);
            }
        }
    }

    public void reload(ComponentKey key) {
        reload(key.user, key.componentName.getPackageName());
    }

    public void reload(Collection<ComponentKey> keys) {
        for (ComponentKey key : keys) {
            reload(key);
        }
    }

    private void reload(UserHandle user, String pkg) {
        mModel.onPackageChanged(pkg, user);
    }
}
