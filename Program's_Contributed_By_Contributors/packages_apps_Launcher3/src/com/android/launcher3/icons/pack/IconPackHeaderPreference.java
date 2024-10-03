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
import android.content.Intent;
import android.content.pm.LauncherApps;
import android.content.pm.PackageManager;
import android.content.res.Resources;
import android.view.View;
import android.widget.ImageView;
import android.util.AttributeSet;
import android.util.Log;

import androidx.core.content.res.TypedArrayUtils;
import androidx.preference.CheckBoxPreference;
import androidx.preference.PreferenceViewHolder;

import com.android.launcher3.R;
import com.android.launcher3.icons.IconProvider;


public class IconPackHeaderPreference extends RadioHeaderPreference {
    private static final String TAG = "IconPackHeaderPreference";
    private static final int PREVIEW_ICON_NUM = 8;
    // This value has been selected as an average of usual "device profile-computed" values
    private static final int PREVIEW_ICON_DPI = 500;

    private final Context context;
    private ImageView[] icons = null;

    public IconPackHeaderPreference(Context context) {
        this(context, null);
    }

    public IconPackHeaderPreference(Context context, AttributeSet attrs) {
        this(context, attrs, TypedArrayUtils.getAttr(context,
                androidx.preference.R.attr.preferenceStyle,
                android.R.attr.preferenceStyle));
    }

    public IconPackHeaderPreference(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
        this.context = context;

        setLayoutResource(R.layout.preference_widget_icons_preview);
    }

    @Override
    public void onBindViewHolder(PreferenceViewHolder holder) {
        final ImageView[] imageViews = {
            (ImageView) holder.findViewById(R.id.pref_icon_a),
            (ImageView) holder.findViewById(R.id.pref_icon_b),
            (ImageView) holder.findViewById(R.id.pref_icon_c),
            (ImageView) holder.findViewById(R.id.pref_icon_d),
            (ImageView) holder.findViewById(R.id.pref_icon_e),
            (ImageView) holder.findViewById(R.id.pref_icon_f),
            (ImageView) holder.findViewById(R.id.pref_icon_g),
            (ImageView) holder.findViewById(R.id.pref_icon_h)
        };
        this.icons = imageViews;
        onRadioElementSelected(null);
    }

    @Override
    public void onDetached() {
        this.icons = null;
        super.onDetached();
    }

    @Override
    public void onRadioElementSelected(String key) {
        if (icons == null || icons.length == 0) {
            return;
        }

        final IconProvider iconProvider = IconProvider.INSTANCE.get(context);
        final PackageManager pm = context.getPackageManager();
        final LauncherApps launcherApps = context.getSystemService(LauncherApps.class);
        new GetLaunchableInfoTask(pm, launcherApps, PREVIEW_ICON_NUM, (aiList) -> {
            for (int i = 0; i < icons.length; i++) {
                icons[i].setImageDrawable(iconProvider.getIcon(
                         aiList.get(i), PREVIEW_ICON_DPI, null));
            }
        }).execute();
    }
}
