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
package com.android.launcher3.allapps;

import static android.view.View.INVISIBLE;
import static android.view.View.VISIBLE;

import android.view.View;

import com.android.systemui.plugins.AllAppsRow;

/**
 * Wrapper over an {@link AllAppsRow} plugin with {@link FloatingHeaderRow} interface so that
 * it can be easily added in {@link FloatingHeaderView}.
 */
public class PluginHeaderRow implements FloatingHeaderRow {

    private final AllAppsRow mPlugin;
    final View mView;

    PluginHeaderRow(AllAppsRow plugin, FloatingHeaderView parent) {
        mPlugin = plugin;
        mView = mPlugin.setup(parent);
    }

    @Override
    public void setup(FloatingHeaderView parent, FloatingHeaderRow[] allRows,
            boolean tabsHidden) { }

    @Override
    public int getExpectedHeight() {
        return mPlugin.getExpectedHeight();
    }

    @Override
    public boolean shouldDraw() {
        return true;
    }

    @Override
    public boolean hasVisibleContent() {
        return true;
    }

    @Override
    public void setVerticalScroll(int scroll, boolean isScrolledOut) {
        mView.setVisibility(isScrolledOut ? INVISIBLE : VISIBLE);
        if (!isScrolledOut) {
            mView.setTranslationY(scroll);
        }
    }

    @Override
    public Class<PluginHeaderRow> getTypeClass() {
        return PluginHeaderRow.class;
    }

    @Override
    public View getFocusedChild() {
        return null;
    }
}