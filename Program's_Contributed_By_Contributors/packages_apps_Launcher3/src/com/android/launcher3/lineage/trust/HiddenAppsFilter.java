/*
 * Copyright (C) 2019 The LineageOS Project
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
package com.android.launcher3.lineage.trust;

import android.content.ComponentName;
import android.content.Context;

import com.android.launcher3.AppFilter;

import androidx.annotation.NonNull;

@SuppressWarnings("unused")
public class HiddenAppsFilter extends AppFilter {

    @NonNull
    private AppLockHelper mAppLockHelper;

    public HiddenAppsFilter(Context context) {
        super(context);

        mAppLockHelper = AppLockHelper.getInstance(context);
    }

    @Override
    public boolean shouldShowApp(ComponentName app) {
        return !mAppLockHelper.isPackageHidden(app.getPackageName()) && super.shouldShowApp(app);
    }
}
