/*
 * Copyright (C) 2019 The Android Open Source Project
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
package com.android.launcher3.util;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.PatternMatcher;
import android.text.TextUtils;

import androidx.annotation.Nullable;

import java.util.function.Consumer;

public class SimpleBroadcastReceiver extends BroadcastReceiver {

    private final Consumer<Intent> mIntentConsumer;

    public SimpleBroadcastReceiver(Consumer<Intent> intentConsumer) {
        mIntentConsumer = intentConsumer;
    }

    @Override
    public void onReceive(Context context, Intent intent) {
        mIntentConsumer.accept(intent);
    }

    /**
     * Helper method to register multiple actions
     */
    public void register(Context context, String... actions) {
        context.registerReceiver(this, getFilter(actions));
    }

    public void register(Context context, int flags, String... actions) {
        context.registerReceiver(this, getFilter(actions), flags);
    }

    /**
     * Helper method to register multiple actions associated with a paction
     */
    public void registerPkgActions(Context context, @Nullable String pkg, String... actions) {
        context.registerReceiver(this, getPackageFilter(pkg, actions));
    }

    /**
     * Creates an intent filter to listen for actions with a specific package in the data field.
     */
    public static IntentFilter getPackageFilter(String pkg, String... actions) {
        IntentFilter filter = getFilter(actions);
        filter.addDataScheme("package");
        if (!TextUtils.isEmpty(pkg)) {
            filter.addDataSchemeSpecificPart(pkg, PatternMatcher.PATTERN_LITERAL);
        }
        return filter;
    }

    private static IntentFilter getFilter(String... actions) {
        IntentFilter filter = new IntentFilter();
        for (String action : actions) {
            filter.addAction(action);
        }
        return filter;
    }

    /**
     * Unregisters the receiver ignoring any errors
     */
    public void unregisterReceiverSafely(Context context) {
        try {
            context.unregisterReceiver(this);
        } catch (IllegalArgumentException e) {
            // It was probably never registered or already unregistered. Ignore.
        }
    }
}
