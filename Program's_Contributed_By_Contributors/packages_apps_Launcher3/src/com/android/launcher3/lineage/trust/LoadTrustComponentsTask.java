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

import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.PackageInfoFlags;
import android.graphics.drawable.Drawable;
import android.os.AsyncTask;
import android.os.Build;

import androidx.annotation.NonNull;

import com.android.internal.util.everest.EverestUtils;
import com.android.launcher3.lineage.trust.db.TrustComponent;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class LoadTrustComponentsTask extends AsyncTask<Void, Integer, List<TrustComponent>> {
    @NonNull
    private AppLockHelper mAppLockHelper;

    @NonNull
    private PackageManager mPackageManager;

    @NonNull
    private Callback mCallback;

    @NonNull
    private Context mContext;

    LoadTrustComponentsTask(@NonNull AppLockHelper appLockHelper,
            @NonNull PackageManager packageManager,
            @NonNull Callback callback,
            @NonNull Context context) {
        mAppLockHelper = appLockHelper;
        mPackageManager = packageManager;
        mCallback = callback;
        mContext = context;
    }

    @Override
    protected List<TrustComponent> doInBackground(Void... voids) {
        List<TrustComponent> list = new ArrayList<>();

        List<PackageInfo> apps = mPackageManager.getInstalledPackages(
                    PackageInfoFlags.of(Long.valueOf(PackageManager.MATCH_ALL)));

        int numPackages = apps.size();
        List<String> launchablePackages = BlissUtils.launchablePackages(mContext);
        List<String> whiteListedPackages = Arrays.asList(mContext.getResources().getStringArray(
                com.android.internal.R.array.config_appLockAllowedSystemApps));

        for (int i = 0; i < numPackages; i++) {
            PackageInfo app = apps.get(i);
            try {
                String pkgName = app.packageName;
                if (!app.applicationInfo.isSystemApp() || launchablePackages.contains(pkgName) ||
                        whiteListedPackages.contains(pkgName)) {
                    String label = mPackageManager.getApplicationLabel(
                            mPackageManager.getApplicationInfo(pkgName,
                                    PackageManager.GET_META_DATA)).toString();
                    Drawable icon = app.applicationInfo.loadIcon(mPackageManager);
                    boolean isHidden = mAppLockHelper.isPackageHidden(pkgName);
                    boolean isProtected = mAppLockHelper.isPackageProtected(pkgName);

                    list.add(new TrustComponent(pkgName, icon, label, isHidden, isProtected));
                }

                publishProgress(Math.round(i * 100f / numPackages));
            } catch (PackageManager.NameNotFoundException ignored) {
            }
        }

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            Collections.sort(list, (a, b) -> a.getLabel().compareTo(b.getLabel()));
        }

        return list;
    }

    @Override
    protected void onProgressUpdate(Integer... values) {
        if (values.length > 0) {
            mCallback.onLoadListProgress(values[0]);
        }
    }

    @Override
    protected void onPostExecute(List<TrustComponent> trustComponents) {
        mCallback.onLoadCompleted(trustComponents);
    }

    interface Callback {
        void onLoadListProgress(int progress);
        void onLoadCompleted(List<TrustComponent> result);
    }
}
