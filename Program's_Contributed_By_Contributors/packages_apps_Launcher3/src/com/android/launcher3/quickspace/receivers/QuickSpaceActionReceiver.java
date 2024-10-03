/*
 * Copyright (C) 2018-2023 crDroid Android Project
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
package com.android.launcher3.quickspace.receivers;

import android.content.ActivityNotFoundException;
import android.content.ComponentName;
import android.content.ContentUris;
import android.content.Context;
import android.content.Intent;
import android.content.pm.LauncherApps;
import android.net.Uri;
import android.os.Process;
import android.os.UserHandle;
import android.provider.CalendarContract;
import android.view.View;
import android.view.View.OnClickListener;

import com.android.launcher3.Launcher;
import com.android.launcher3.LauncherAppState;
import com.android.launcher3.R;
import com.android.launcher3.Utilities;

public class QuickSpaceActionReceiver {

    private static Context mContext;
    private final LauncherApps mLauncherApps;

    public OnClickListener mCalendarClickListener;
    public OnClickListener mWeatherClickListener;

    public QuickSpaceActionReceiver(Context context) {
        mContext = context;
        mLauncherApps = context.getSystemService(LauncherApps.class);

        mCalendarClickListener = new OnClickListener() {
            @Override
            public void onClick(View view) {
                openGoogleCalendar(view);
            }
        };

        mWeatherClickListener = new OnClickListener() {
            @Override
            public void onClick(View view) {
                openGoogleWeather(view);
            }
        };
    }

    private void openGoogleCalendar(View view) {
        final Uri content_URI = CalendarContract.CONTENT_URI;
        final Uri.Builder appendPath = content_URI.buildUpon().appendPath("time");
        ContentUris.appendId(appendPath, System.currentTimeMillis());
        final Intent addFlags = new Intent(Intent.ACTION_VIEW)
                .setData(appendPath.build())
                .addFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_RESET_TASK_IF_NEEDED);
        try {
            Launcher.getLauncher(mContext).startActivitySafely(view, addFlags, null);
        } catch (ActivityNotFoundException ex) {
            mLauncherApps.startAppDetailsActivity(new ComponentName("com.google.android.googlequicksearchbox", ""), Process.myUserHandle(), null, null);
        }
    }

    private void openGoogleWeather(View view) {
        Intent intent = new Intent("android.intent.action.VIEW");
        intent.setData(Uri.parse("dynact://velour/weather/ProxyActivity"));
        intent.setComponent(new ComponentName("com.google.android.googlequicksearchbox", "com.google.android.apps.gsa.velour.DynamicActivityTrampoline"));
        try {
            Launcher.getLauncher(mContext).startActivitySafely(view, intent, null);
        } catch (ActivityNotFoundException ex) {
            mLauncherApps.startAppDetailsActivity(new ComponentName("com.google.android.googlequicksearchbox",
                    "com.google.android.apps.gsa.velour.DynamicActivityTrampoline"), Process.myUserHandle(), null, null);
        }
    }

    public OnClickListener getCalendarAction() {
        return mCalendarClickListener;
    }

    public OnClickListener getWeatherAction() {
        return mWeatherClickListener;
    }
}
