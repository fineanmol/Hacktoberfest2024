/*
 * Copyright (C) 2017 The Android Open Source Project
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
package com.android.launcher3.search;

/**
 * An interface for handling search.
 *
 * @param <T> Search Result type
 */
public interface SearchAlgorithm<T> {

    /**
     * Performs search and sends the result to {@link SearchCallback}.
     */
    void doSearch(String query, SearchCallback<T> callback);

    /**
     * Performs search with {@code query} and the {@code suggestedQueries}/
     */
    default void doSearch(String query, String[] suggestedQueries, SearchCallback<T> callback) {
        doSearch(query, callback);
    }

    /**
     * Cancels any active request.
     */
    void cancel(boolean interruptActiveRequests);

    /**
     * Cleans up after search is no longer needed.
     */
    default void destroy() {};
}
