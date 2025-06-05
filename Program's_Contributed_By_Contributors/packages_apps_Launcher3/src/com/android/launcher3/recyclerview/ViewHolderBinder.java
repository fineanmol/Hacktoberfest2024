/*
 * Copyright (C) 2021 The Android Open Source Project
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
package com.android.launcher3.recyclerview;

import android.view.ViewGroup;

import androidx.annotation.IntDef;
import androidx.recyclerview.widget.RecyclerView.ViewHolder;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.util.List;

/**
 * Creates and populates views with data
 *
 * @param <T> A data model which is used to populate the {@link ViewHolder}.
 * @param <V> A subclass of {@link ViewHolder} which holds references to views.
 */
public interface ViewHolderBinder<T, V extends ViewHolder> {

    int POSITION_DEFAULT = 0;
    int POSITION_FIRST = 1 << 0;
    int POSITION_LAST = 1 << 1;

    @Retention(RetentionPolicy.SOURCE)
    @IntDef(value = {POSITION_DEFAULT, POSITION_FIRST, POSITION_LAST}, flag = true)
    @interface ListPosition {}

    /**
     * Creates a new view, and attach it to the parent {@link ViewGroup}. Then, populates UI
     * references in a {@link ViewHolder}.
     */
    V newViewHolder(ViewGroup parent);

    /** Populate UI references in {@link ViewHolder} with data. */
    void bindViewHolder(V viewHolder, T data, @ListPosition int position, List<Object> payloads);

    /**
     * Called when the view is recycled. Views are recycled in batches once they are sufficiently
     * far off screen that it is unlikely the user will scroll back to them soon. Optionally
     * override this to free expensive resources.
     */
    default void unbindViewHolder(V viewHolder) {}
}
