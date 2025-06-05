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

package com.android.launcher3.tapl;

import androidx.test.uiautomator.UiObject2;

import com.android.launcher3.testing.shared.TestProtocol;

/**
 * Menu item in an app icon menu.
 */
public abstract class AppIconMenuItem extends Launchable {

    AppIconMenuItem(LauncherInstrumentation launcher, UiObject2 shortcut) {
        super(launcher, shortcut);
    }

    /**
     * Returns the visible text of the menu item.
     */
    public String getText() {
        return mObject.getText();
    }

    @Override
    protected void addExpectedEventsForLongClick() {
    }

    @Override
    protected void waitForLongPressConfirmation() {
        mLauncher.waitForLauncherObject("drop_target_bar");
    }

    @Override
    protected void expectActivityStartEvents() {
        mLauncher.expectEvent(TestProtocol.SEQUENCE_MAIN, LauncherInstrumentation.EVENT_START);
    }

    @Override
    protected String launchableType() {
        return "app icon menu item";
    }
}
