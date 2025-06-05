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

package com.android.launcher3.util;

import android.os.Looper;
import android.os.MessageQueue;

/**
 * Utility class to block execution until the UI looper is idle.
 */
public class LooperIdleLock implements MessageQueue.IdleHandler {

    private final Object mLock;

    private boolean mIsLocked;
    private Looper mLooper;

    public LooperIdleLock(Object lock, Looper looper) {
        mLock = lock;
        mLooper = looper;
        mIsLocked = true;
        looper.getQueue().addIdleHandler(this);
    }

    @Override
    public boolean queueIdle() {
        synchronized (mLock) {
            mIsLocked = false;
            mLock.notify();
        }
        // Manually remove from the list in case we're calling this outside of the idle callbacks
        // (this is Ok in the normal flow as well because MessageQueue makes a copy of all handlers
        // before calling back)
        mLooper.getQueue().removeIdleHandler(this);
        return false;
    }

    public boolean awaitLocked(long ms) {
        if (mIsLocked) {
            try {
                // Just in case mFlushingWorkerThread changes but we aren't woken up,
                // wait no longer than 1sec at a time
                mLock.wait(ms);
            } catch (InterruptedException ex) {
                // Ignore
            }
        }
        return mIsLocked;
    }
}
