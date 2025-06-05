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

import com.android.launcher3.tapl.LauncherInstrumentation.ContainerType;

/**
 * Overview pane.
 */
public class Overview extends BaseOverview {

    Overview(LauncherInstrumentation launcher) {
        super(launcher);
    }

    @Override
    protected ContainerType getContainerType() {
        return ContainerType.OVERVIEW;
    }

    @Override
    public void dismissAllTasks() {
        super.dismissAllTasks();
        try (LauncherInstrumentation.Closable c1 = mLauncher.addContextLayer(
                "dismissed all tasks")) {
            new Workspace(mLauncher);
        }
    }
}
