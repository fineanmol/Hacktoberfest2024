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
package com.android.launcher3.model;

import android.os.Process;
import android.os.UserHandle;
import android.os.UserManager;
import android.util.LongSparseArray;
import android.util.SparseBooleanArray;

import com.android.launcher3.pm.UserCache;

/**
 * Utility class to manager store and user manager state at any particular time
 */
public class UserManagerState {

    public final LongSparseArray<UserHandle> allUsers = new LongSparseArray<>();

    private final LongSparseArray<Boolean> mQuietUsersSerialNoMap = new LongSparseArray<>();
    private final SparseBooleanArray mQuietUsersHashCodeMap = new SparseBooleanArray();

    /**
     * Initialises the state values for all users
     */
    public void init(UserCache userCache, UserManager userManager) {
        for (UserHandle user : userCache.getUserProfiles()) {
            long serialNo = userCache.getSerialNumberForUser(user);
            boolean isUserQuiet = userManager.isQuietModeEnabled(user);
            allUsers.put(serialNo, user);
            mQuietUsersHashCodeMap.put(user.hashCode(), isUserQuiet);
            mQuietUsersSerialNoMap.put(serialNo, isUserQuiet);
        }
    }

    /**
     * Returns true if quiet mode is enabled for the provided user
     */
    public boolean isUserQuiet(long serialNo) {
        return mQuietUsersSerialNoMap.get(serialNo);
    }

    /**
     * Returns true if quiet mode is enabled for the provided user
     */
    public boolean isUserQuiet(UserHandle user) {
        return mQuietUsersHashCodeMap.get(user.hashCode());
    }

    /**
     * Returns true if all managed profiles have quiet mode enabled.
     */
    public boolean isAllProfilesQuietModeEnabled() {
        // Because the parent user is included, there will always be at least one user returned
        // by getUserProfiles and tracked by allUsers, even if there are no managed profiles.
        final int numProfilesIncludingParent = allUsers.size();
        if (numProfilesIncludingParent <= 1) {
            // There are no managed profiles, only the parent user, so we can return early.
            return false;
        }
        for (int i = 0; i < numProfilesIncludingParent; i++) {
            if (Process.myUserHandle().equals(allUsers.valueAt(i))) {
                // Skip the parent user.
                continue;
            }
            long serialNo = allUsers.keyAt(i);
            if (!isUserQuiet(serialNo)) {
                return false;
            }
        }
        // Quiet mode is on for all users.
        return true;
    }

    public boolean hasMultipleProfiles() {
        final int numProfiles = allUsers.size() - 1; // not including the parent
        return numProfiles > 1;
    }
}
