/*
 * Copyright (C) 2018 The Android Open Source Project
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
package com.android.launcher3.icons;

import android.content.ComponentName;
import android.content.Context;
import android.content.pm.LauncherActivityInfo;
import android.os.UserHandle;

import androidx.annotation.NonNull;

import com.android.launcher3.LauncherAppState;
import com.android.launcher3.R;
import com.android.launcher3.icons.BaseIconFactory.IconOptions;
import com.android.launcher3.icons.cache.CachingLogic;
import com.android.launcher3.util.ResourceBasedOverride;
import com.android.launcher3.util.Themes;

/**
 * Caching logic for LauncherActivityInfo.
 */
public class LauncherActivityCachingLogic
        implements CachingLogic<LauncherActivityInfo>, ResourceBasedOverride {

    /**
     * Creates and returns a new instance
     */
    public static LauncherActivityCachingLogic newInstance(Context context) {
        return Overrides.getObject(LauncherActivityCachingLogic.class, context,
                R.string.launcher_activity_logic_class);
    }

    @NonNull
    @Override
    public ComponentName getComponent(@NonNull LauncherActivityInfo object) {
        return object.getComponentName();
    }

    @NonNull
    @Override
    public UserHandle getUser(@NonNull LauncherActivityInfo object) {
        return object.getUser();
    }

    @NonNull
    @Override
    public CharSequence getLabel(@NonNull LauncherActivityInfo object) {
        return object.getLabel();
    }

    @NonNull
    @Override
    public BitmapInfo loadIcon(@NonNull Context context, @NonNull LauncherActivityInfo object) {
        try (LauncherIcons li = LauncherIcons.obtain(context)) {
	    final String customThemedIconPack = Themes.getThemedIconPack(context);
            return li.createBadgedIconBitmap(LauncherAppState.getInstance(context)
                            .getIconProvider().getIcon(object, li.mFillResIconDpi, customThemedIconPack),
                    new IconOptions().setUser(object.getUser()));
        }
    }
}
