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

import android.content.Context;
import android.os.Bundle;

import androidx.preference.Preference;
import androidx.preference.PreferenceFragment;
import androidx.preference.PreferenceManager;
import androidx.preference.PreferenceScreen;

import com.android.settingslib.widget.SelectorWithWidgetPreference;

import java.util.List;

public abstract class RadioSettingsFragment extends PreferenceFragment implements
        Preference.OnPreferenceClickListener {
    private SelectorWithWidgetPreference selectedPreference = null;
    private RadioHeaderPreference headerPref = null;

    protected abstract List<SelectorWithWidgetPreference> getPreferences(Context context);

    @Override
    public void onCreatePreferences(Bundle savedInstanceState, String rootKey) {
        final PreferenceManager prefManager = getPreferenceManager();
        final Context context = prefManager.getContext();
        final PreferenceScreen screen = prefManager.createPreferenceScreen(context);

        headerPref = getHeader(context);
        if (headerPref != null) {
            screen.addPreference(headerPref);
        }

        loadPreferences(context, screen, null);
        setPreferenceScreen(screen);
    }

    @Override
    public boolean onPreferenceClick(Preference preference) {
        if (preference instanceof SelectorWithWidgetPreference) {
            onSelected(preference.getKey());

            if (selectedPreference != null) {
                selectedPreference.setChecked(false);
            }
            selectedPreference = (SelectorWithWidgetPreference) preference;
            selectedPreference.setChecked(true);
            return true;
        } else {
            return false;
        }
    }

    @Override
    public void onDestroyView() {
        selectedPreference = null;
        headerPref = null;
        super.onDestroyView();
    }

    protected RadioHeaderPreference getHeader(Context context) {
        return null;
    }

    protected final void setSelectedPreference(SelectorWithWidgetPreference preference) {
        selectedPreference = preference;
    }

    protected void onSelected(String key) {
        if (headerPref != null) {
            headerPref.onRadioElementSelected(key);
        }
    }

    protected void reloadPreferences() {
        final PreferenceScreen screen = getPreferenceScreen();
        if (screen == null) {
            return;
        }

        // Save current key for later
        final String currentKey = selectedPreference == null ?
                null : selectedPreference.getKey();
        selectedPreference = null;

        // Reload header contents
        if (headerPref != null) {
            headerPref.onRadioElementSelected(currentKey);
        }

        // Remove radio preferences (backwards so we don't mess up indices)
        final int numPreferences = screen.getPreferenceCount();
        for (int i = numPreferences - 1; i >= 0; i--) {
            final Preference p = screen.getPreference(i);
            if (p instanceof SelectorWithWidgetPreference) {
                screen.removePreference(p);
            }
        }

        // Add radio preferences
        final PreferenceManager prefManager = getPreferenceManager();
        final Context context = prefManager.getContext();
        loadPreferences(context, screen, currentKey);
    }

    private void loadPreferences(Context context, PreferenceScreen screen,
            String currentKey) {
        boolean hasSetNewCurrent = false;

        final List<SelectorWithWidgetPreference> prefs = getPreferences(context);
        for (final SelectorWithWidgetPreference p : prefs) {
            if (currentKey != null && currentKey.equals(p.getKey())) {
                p.setChecked(true);
                selectedPreference = p;
                hasSetNewCurrent = true;
            }
            p.setOnPreferenceClickListener(this);
            screen.addPreference(p);
        }

        if (!hasSetNewCurrent && currentKey != null && !prefs.isEmpty()) {
            // Old "current" preference was removed, fallback to 
            // the first candidate
            selectedPreference = prefs.get(0);
            selectedPreference.setChecked(true);
            onPreferenceClick(selectedPreference);
        }
    }
}
