/*
 * Copyright (C) 2020 Shift GmbH
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

public final class IconPackSettingsFragment extends RadioSettingsFragment {
    private static final IntentFilter PKG_UPDATE_INTENT = new IntentFilter();

    private static final String[] ICON_INTENT_ACTIONS = new String[] {
            "com.fede.launcher.THEME_ICONPACK",
            "com.anddoes.launcher.THEME",
            "com.novalauncher.THEME",
            "com.teslacoilsw.launcher.THEME",
            "com.gau.go.launcherex.theme",
            "org.adw.launcher.THEMES",
            "org.adw.launcher.icons.ACTION_PICK_ICON",
            "net.oneplus.launcher.icons.ACTION_PICK_ICON",
    };

    private static final Intent[] ICON_INTENTS = new Intent[ICON_INTENT_ACTIONS.length];

    static {
        for (int i = 0; i < ICON_INTENT_ACTIONS.length; i++) {
            ICON_INTENTS[i] = new Intent(ICON_INTENT_ACTIONS[i]);
        }
    }
    
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
        final String currentIconPack = IconDatabase.getGlobal(context);
        final List<SelectorWithWidgetPreference> prefsList = new ArrayList<>();
        final Set<IconPackInfo> iconPacks = getAvailableIconPacks(context);

        for (final IconPackInfo entry : iconPacks) {
            final boolean isCurrent = currentIconPack.equals(entry.pkgName);
            final SelectorWithWidgetPreference pref = buildPreference(context,
                    entry.pkgName, entry.label, isCurrent);
            prefsList.add(pref);

            if (isCurrent) {
                setSelectedPreference(pref);
            }
        }

        return prefsList;
    }

    @Override
    public void onSelected(String key) {
        IconDatabase.setGlobal(getActivity(), key);
        super.onSelected(key);
    }

    @Override
    protected IconPackHeaderPreference getHeader(Context context) {
        return new IconPackHeaderPreference(context);
    }

    private Set<IconPackInfo> getAvailableIconPacks(Context context) {
        final PackageManager pm = context.getPackageManager();
        final Set<IconPackInfo> availablePacks = new LinkedHashSet<>();
        final List<ResolveInfo> eligiblePacks = new ArrayList<>();
        for (Intent intent : ICON_INTENTS) {
            eligiblePacks.addAll(pm.queryIntentActivities(intent, PackageManager.GET_META_DATA));
        }

        // Add default
        final String defaultLabel = context.getString(R.string.icon_pack_default_label);
        availablePacks.add(new IconPackInfo(IconDatabase.VALUE_DEFAULT, defaultLabel));
        // Add user-installed packs that do not have themed icons
        for (final ResolveInfo r : eligiblePacks) {
            if (!hasThemedIconResourceMap(pm, r.activityInfo.packageName)) {
                availablePacks.add(new IconPackInfo(
                        r.activityInfo.packageName, (String) r.loadLabel(pm)));
            }
        }
        return availablePacks;
    }

    private boolean hasThemedIconResourceMap(PackageManager pm, String packageName) {
        try {
            PackageInfo packageInfo = pm.getPackageInfo(packageName, PackageManager.GET_META_DATA);
            Resources res = pm.getResourcesForApplication(packageInfo.applicationInfo);
            int resID = res.getIdentifier("grayscale_icon_map", "xml", packageName);
            return resID != 0;
        } catch (PackageManager.NameNotFoundException | Resources.NotFoundException e) {
            return false;
        }
    }

    private SelectorWithWidgetPreference buildPreference(Context context, String pkgName,
            String label, boolean isChecked) {
        final SelectorWithWidgetPreference pref = new SelectorWithWidgetPreference(context);
        pref.setKey(pkgName);
        pref.setTitle(label);
        pref.setPersistent(false);
        pref.setChecked(isChecked);
        if (!pkgName.equals(IconDatabase.VALUE_DEFAULT)) {
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
