/*
 * Copyright (C) 2008 The Android Open Source Project
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

package com.android.launcher3;

import android.view.View;

import com.android.launcher3.DropTarget.DragObject;

/**
 * Interface defining an object that can originate a drag.
 */
public interface DragSource {

    /**
     * A callback made back to the source after an item from this source has been dropped on a
     * DropTarget.
     */
    void onDropCompleted(View target, DragObject d, boolean success);
}
