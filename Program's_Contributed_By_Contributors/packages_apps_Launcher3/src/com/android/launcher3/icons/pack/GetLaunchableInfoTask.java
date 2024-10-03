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
package com.android.launcher3.icons.pack;

import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.pm.ApplicationInfo;
import android.content.pm.LauncherActivityInfo;
import android.content.pm.LauncherApps;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.os.AsyncTask;
import android.os.Build;
import android.os.Process;
import android.os.UserHandle;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

final class GetLaunchableInfoTask extends AsyncTask<Void, Void, List<LauncherActivityInfo>> {

    private final PackageManager pm;
    private final LauncherApps launcherApps;
    private final int limit;
    private final Callback callback;

    GetLaunchableInfoTask(PackageManager pm,
                          LauncherApps launcherApps,
                          int limit,
                          Callback callback) {
        this.pm = pm;
        this.launcherApps = launcherApps;
        this.limit = limit;
        this.callback = callback;
    }

    @Override
    protected List<LauncherActivityInfo> doInBackground(Void... voids) {
        if (Build.VERSION.SDK_INT < Build.VERSION_CODES.O) {
            // This should never happen
            return new ArrayList<>();
        }

        final UserHandle ua = Process.myUserHandle();
        final Intent mainIntent = new Intent(Intent.ACTION_MAIN, null)
                .addCategory(Intent.CATEGORY_LAUNCHER);
        return pm.queryIntentActivities(mainIntent, 0)
            .parallelStream()
            .sorted(new ResolveInfo.DisplayNameComparator(pm))
            .limit(limit)
            .map((ri) -> {
                final ActivityInfo ai = ri.activityInfo;
                final Intent i = new Intent();
                i.setClassName(ai.applicationInfo.packageName, ai.name);
                return launcherApps.resolveActivity(i, ua);
            })
            .collect(Collectors.toList());
    }

    @Override
    protected void onPostExecute(List<LauncherActivityInfo> list) {
        callback.onLoadCompleted(list);
    }

    interface Callback {
        void onLoadCompleted(List<LauncherActivityInfo> result);
    }
}
