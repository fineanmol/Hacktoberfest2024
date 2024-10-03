package com.android.launcher3.customization;

import android.content.Context;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;

import com.android.launcher3.BuildConfig;
import com.android.launcher3.LauncherPrefs;
import com.android.launcher3.R;
import com.android.launcher3.util.ComponentKey;

public class IconDatabase {

    private static final String PREF_FILE_NAME = BuildConfig.APPLICATION_ID + ".ICON_DATABASE";
    public static final String KEY_THEMED_ICON_PACK = "themed_icon_pack";
    public static final String KEY_ICON_PACK = "pref_icon_pack";
    public static final String VALUE_DEFAULT = "";

    public static String getGlobal(Context context) {
        return LauncherPrefs.getPrefs(context).getString(KEY_ICON_PACK, VALUE_DEFAULT);
    }
    
    public static String getGlobalThemeIcons(Context context) {
        return LauncherPrefs.getPrefs(context).getString(KEY_THEMED_ICON_PACK, null);
    }

    public static String getGlobalLabel(Context context) {
        final String defaultLabel = context.getString(R.string.icon_pack_default_label);
        final String pkgName = getGlobal(context);
        if (VALUE_DEFAULT.equals(pkgName)) {
            return defaultLabel;
        }

        final PackageManager pm = context.getPackageManager();
        try {
            final ApplicationInfo ai = pm.getApplicationInfo(pkgName, 0);
            return (String) pm.getApplicationLabel(ai);
        } catch (PackageManager.NameNotFoundException e) {
            return defaultLabel;
        }
    }

    public static String getGlobalLabelThemedIcons(Context context) {
        final String disabledLabel = context.getString(R.string.themed_icon_pack_disabled);
        final String defaultLabel = context.getString(R.string.icon_pack_default_label);
        final String pkgName = getGlobalThemeIcons(context);
        if (pkgName == null || pkgName.equals("disabled")) {
            return disabledLabel;
        }
        
        if (pkgName.trim().toLowerCase().contains("com.android.launcher3")
            || pkgName.trim().toLowerCase().contains("com.plus.android.overlay.launcher3")) {
            return defaultLabel;
        }

        final PackageManager pm = context.getPackageManager();
        try {
            final ApplicationInfo ai = pm.getApplicationInfo(pkgName, 0);
            return (String) pm.getApplicationLabel(ai);
        } catch (PackageManager.NameNotFoundException e) {
            return disabledLabel;
        }
    }

    public static void setGlobalThemedIcons(Context context, String value) {
        SharedPreferences.Editor editor = LauncherPrefs.getPrefs(context).edit();
        editor.putString(KEY_THEMED_ICON_PACK, null);
        if (!value.equals("disabled")) {
            editor.putString(KEY_THEMED_ICON_PACK, value);
        }
        editor.apply();
    }

    public static void setGlobal(Context context, String value) {
        LauncherPrefs.getPrefs(context).edit().putString(KEY_ICON_PACK, value).apply();
    }

    public static void resetGlobal(Context context) {
        LauncherPrefs.getPrefs(context).edit().remove(KEY_ICON_PACK).apply();
    }

    public static String getByComponent(Context context, ComponentKey key) {
        return getIconPackPrefs(context).getString(key.toString(), getGlobal(context));
    }

    public static void setForComponent(Context context, ComponentKey key, String value) {
        getIconPackPrefs(context).edit().putString(key.toString(), value).apply();
    }

    public static void resetForComponent(Context context, ComponentKey key) {
        getIconPackPrefs(context).edit().remove(key.toString()).apply();
    }

    private static SharedPreferences getIconPackPrefs(Context context) {
        return context.getSharedPreferences(PREF_FILE_NAME, Context.MODE_PRIVATE);
    }
}
