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
package com.android.launcher3.views;

import android.view.View;

/**
 * A view that has an icon, label, and notification dot.
 */
public interface IconLabelDotView {
    void setIconVisible(boolean visible);
    void setForceHideDot(boolean hide);

    /**
     * Sets the visibility of icon and dot of the view
     */
    static void setIconAndDotVisible(View view, boolean visible) {
        if (view instanceof IconLabelDotView) {
            ((IconLabelDotView) view).setIconVisible(visible);
            ((IconLabelDotView) view).setForceHideDot(!visible);
        } else {
            view.setVisibility(visible ? View.VISIBLE : View.INVISIBLE);
        }
    }
}
