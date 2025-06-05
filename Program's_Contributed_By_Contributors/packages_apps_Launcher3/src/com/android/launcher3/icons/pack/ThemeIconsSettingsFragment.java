/*
 * Copyright (C) 2020 Shift GmbH
 * Copyright (C) 2023 The risingOS Android Project
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
package com.android.launcher3.icons.pack;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.content.pm.PackageInfo;
import android.content.pm.ResolveInfo;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.preference.Preference;

import com.android.launcher3.R;

import com.android.launcher3.customization.IconDatabase;

import com.android.settingslib.widget.SelectorWithWidgetPreference;

import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;

public final class ThemeIconsSettingsFragment extends RadioSettingsFragment {
    private static final IntentFilter PKG_UPDATE_INTENT = new IntentFilter();
    private List<SelectorWithWidgetPreference> preferencesList = new ArrayList<>();
    
    static {
        PKG_UPDATE_INTENT.addAction(Intent.ACTION_PACKAGE_INSTALL);
        PKG_UPDATE_INTENT.addAction(Intent.ACTION_PACKAGE_ADDED);
        PKG_UPDATE_INTENT.addAction(Intent.ACTION_PACKAGE_CHANGED);
        PKG_UPDATE_INTENT.addAction(Intent.ACTION_PACKAGE_REMOVED);
        PKG_UPDATE_INTENT.addDataScheme("package");
    }

    private BroadcastReceiver broadCastReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            reloadPreferences();
        }
    };

    @Override
    public void onResume() {
        super.onResume();
        reloadPreferences();
        getActivity().registerReceiver(broadCastReceiver, PKG_UPDATE_INTENT);
    }

    @Override
    public void onPause() {
        super.onPause();
        getActivity().unregisterReceiver(broadCastReceiver);
    }

    @Override
    protected List<SelectorWithWidgetPreference> getPreferences(Context context) {
        final String currentIconPack = IconDatabase.getGlobalThemeIcons(context);
        final String disableThemeIcons = context.getString(R.string.themed_icon_pack_disabled);
        final List<SelectorWithWidgetPreference> prefsList = new ArrayList<>();
        final Set<IconPackInfo> iconPacks = getAvailableIconPacks(context);

        for (final IconPackInfo entry : iconPacks) {
            final boolean isDisabled = currentIconPack == null && entry.pkgName.equals("disabled");
            final boolean isCurrent = currentIconPack != null && entry.pkgName != null && currentIconPack.equals(entry.pkgName);
            final SelectorWithWidgetPreference pref = buildPreference(context,
                     isDisabled ? "disabled" : entry.pkgName, isDisabled ? disableThemeIcons : entry.label, isDisabled ? isDisabled : isCurrent);
            prefsList.add(pref);

            if (isCurrent) {
                setSelectedPreference(pref);
            }
        }
        
        preferencesList = prefsList;

        return prefsList;
    }

    @Override
    public void onSelected(String key) {
        for (SelectorWithWidgetPreference pref : getPreferencesList()) {
            if (!pref.getKey().equals(key)) {
                pref.setChecked(false);
            }
        }

        IconDatabase.setGlobalThemedIcons(getActivity(), key);
        super.onSelected(key);
    }


    @Override
    protected IconPackHeaderPreference getHeader(Context context) {
        return null;
    }

    private List<SelectorWithWidgetPreference> getPreferencesList() {
        return preferencesList;
    }

    private Set<IconPackInfo> getAvailableIconPacks(Context context) {
        final PackageManager pm = context.getPackageManager();
        final Set<IconPackInfo> availablePacks = new LinkedHashSet<>();

        // Add 3rd party Themed icons
        List<PackageInfo> allInstalledPackages = pm.getInstalledPackages(0);
        final String disableThemeIcons = context.getString(R.string.themed_icon_pack_disabled);
        final String defaultThemeIcons = context.getString(R.string.icon_pack_default_label);
        availablePacks.add(new IconPackInfo("disabled", disableThemeIcons));
        for (PackageInfo packageInfo : allInstalledPackages) {
            if (!packageInfo.packageName.equals("com.android.launcher3")) {
                if (hasIconResourceMap(pm, packageInfo)) {
                    final boolean isDefault = packageInfo.packageName.contains("com.android.launcher3")
                        || packageInfo.packageName.contains("com.plus.android.overlay.launcher3");
                    String appLabel = isDefault ? defaultThemeIcons : (String) packageInfo.applicationInfo.loadLabel(pm);
                    String appName = packageInfo.packageName;
                    availablePacks.add(new IconPackInfo(
                                appName, appLabel));
                }
            }
        }

        return availablePacks;
    }

    private boolean hasIconResourceMap(PackageManager pm, PackageInfo packageInfo) {
        Resources res;
        try {
            res = pm.getResourcesForApplication(packageInfo.applicationInfo);
        } catch (PackageManager.NameNotFoundException e) {
            return false;
        }

        int resID = res.getIdentifier(
                "grayscale_icon_map",
                "xml",
                packageInfo.packageName
        );
        return resID != 0;
    }

    private SelectorWithWidgetPreference buildPreference(Context context, String pkgName,
            String label, boolean isChecked) {
        final SelectorWithWidgetPreference pref = new SelectorWithWidgetPreference(context);
        pref.setKey(pkgName);
        pref.setTitle(label);
        pref.setPersistent(false);
        pref.setChecked(isChecked);
        if (pkgName != null) {
            Intent intent = context.getPackageManager().getLaunchIntentForPackage(pkgName);
            if (intent != null) {
                pref.setExtraWidgetOnClickListener((v) -> {
                    context.startActivity(intent);
                });
            }
        }
        return pref;
    }

    private static class IconPackInfo {
        final String pkgName;
        final String label;

        IconPackInfo(String pkgName, String label) {
            this.pkgName = pkgName;
            this.label = label;
        }

        @Override
        public int hashCode() {
            return pkgName.hashCode();
        }

        @Override
        public boolean equals(Object other) {
            if (other == null) return false;
            if (!(other instanceof IconPackInfo)) return false;
            return pkgName.equals(((IconPackInfo) other).pkgName);
        }
    }
}
