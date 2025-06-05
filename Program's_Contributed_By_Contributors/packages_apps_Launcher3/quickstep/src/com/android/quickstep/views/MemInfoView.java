/*
 * Copyright (C) 2022 Project Kaleidoscope
 *               2023-2024 the risingOS Android Project
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

package com.android.quickstep.views;

import static com.android.launcher3.util.NavigationMode.TWO_BUTTONS;
import static com.android.launcher3.util.NavigationMode.THREE_BUTTONS;

import android.app.ActivityManager;
import android.content.Context;
import android.content.Intent;
import android.os.Debug;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.Looper;
import android.text.format.Formatter;
import android.util.AttributeSet;
import android.util.FloatProperty;
import android.view.Gravity;
import android.view.View;
import android.widget.FrameLayout.LayoutParams;
import android.widget.TextView;

import com.android.internal.util.MemInfoReader;

import com.android.settingslib.utils.ThreadUtils;

import com.android.launcher3.anim.AlphaUpdateListener;
import com.android.launcher3.DeviceProfile;
import com.android.launcher3.util.MultiValueAlpha;
import com.android.launcher3.util.NavigationMode;
import com.android.launcher3.R;
import com.android.launcher3.Utilities;

import java.lang.Runnable;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.List;

import com.google.common.util.concurrent.ListenableFuture;

public class MemInfoView extends TextView {

    // When to show GB instead of MB
    private static final int UNIT_CONVERT_THRESHOLD = 1024; /* MiB */

    private static final BigDecimal GB2MB = new BigDecimal(1024);

    private static final int ALPHA_STATE_CTRL = 0;
    public static final int ALPHA_FS_PROGRESS = 1;

    public static final FloatProperty<MemInfoView> STATE_CTRL_ALPHA =
            new FloatProperty<MemInfoView>("state control alpha") {
                @Override
                public Float get(MemInfoView view) {
                    return view.getAlpha(ALPHA_STATE_CTRL);
                }

                @Override
                public void setValue(MemInfoView view, float v) {
                    view.setAlpha(ALPHA_STATE_CTRL, v);
                }
            };

    private DeviceProfile mDp;
    private MultiValueAlpha mAlpha;
    private ActivityManager mActivityManager;

    private final Object mLock = new Object();
    private Handler mHandler;
    private HandlerThread mHandlerThread;

    private String mMemInfoText;

    private ActivityManager.MemoryInfo memInfo;
    private MemInfoReader mMemInfoReader;
    private ListenableFuture<?> mFuture;

    private Context mContext;

    String mTotalResult;

    public MemInfoView(Context context, AttributeSet attrs) {
        super(context, attrs);

        mContext = context;
        mAlpha = new MultiValueAlpha(this, 2);
        mAlpha.setUpdateVisibility(true);
        mActivityManager = (ActivityManager) context.getSystemService(Context.ACTIVITY_SERVICE);
        // make sure updates won't block the UI thread
        mHandlerThread = new HandlerThread("MemInfoThread");
        mHandlerThread.start();
        mHandler = new Handler(mHandlerThread.getLooper());
        memInfo = new ActivityManager.MemoryInfo();
        mMemInfoReader = new MemInfoReader();
        mTotalResult = formatTotalMemory();

        mMemInfoText = context.getResources().getString(R.string.meminfo_text);
        setListener(context);
    }

    /* Hijack this method to detect visibility rather than
     * onVisibilityChanged() because the the latter one can be
     * influenced by more factors, leading to unstable behavior. */
    @Override
    public void setVisibility(int visibility) {
        if (visibility == VISIBLE) {
            boolean showMeminfo = Utilities.isShowMeminfo(getContext());
            if (!showMeminfo) visibility = GONE;
        }

        super.setVisibility(visibility);

        if (visibility == VISIBLE)
            startMemoryMonitoring();
        else
            stopMemoryMonitoring();
    }

    public void setDp(DeviceProfile dp) {
        mDp = dp;
    }

    public void setAlpha(int alphaType, float alpha) {
        mAlpha.get(alphaType).setValue(alpha);
    }

    public float getAlpha(int alphaType) {
        return mAlpha.get(alphaType).getValue();
    }

    public void updateVerticalMargin(NavigationMode mode) {
        LayoutParams lp = (LayoutParams)getLayoutParams();
        int bottomMargin;

        if (!mDp.isTaskbarPresent && ((mode == THREE_BUTTONS) || (mode == TWO_BUTTONS)))
            bottomMargin = mDp.memInfoMarginThreeButtonPx;
        else if (mDp.isTaskbarPresent && !((mode == THREE_BUTTONS) || (mode == TWO_BUTTONS)))
            bottomMargin = mDp.memInfoMarginTransientTaskbarPx;
        else
            bottomMargin = mDp.memInfoMarginGesturePx;

        lp.setMargins(lp.leftMargin, lp.topMargin, lp.rightMargin, bottomMargin);
        lp.gravity = Gravity.CENTER_HORIZONTAL | Gravity.BOTTOM;
    }

    private String formatTotalMemory() {
        mActivityManager.getMemoryInfo(memInfo);
        double totalMemoryGB = memInfo.totalMem / (1024.0 * 1024.0 * 1024.0);
        int roundedMemoryGB = roundToNearestKnownRamSize(totalMemoryGB);
        return roundedMemoryGB + " GB";
    }

    private int roundToNearestKnownRamSize(double memoryGB) {
        int[] knownSizes = {1, 2, 3, 4, 6, 8, 10, 12, 16, 32, 48, 64};
        if (memoryGB <= 0) return 1;
        for (int size : knownSizes) {
            if (memoryGB <= size) return size;
        }
        return knownSizes[knownSizes.length - 1];
    }

    public void setListener(Context context) {
        setOnClickListener(view -> {
            Intent intent = new Intent(Intent.ACTION_MAIN);
            intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TASK);
            intent.setClassName("com.android.settings", "com.android.settings.Settings$DevRunningServicesActivity");
            context.startActivity(intent);
        });
    }

    private long getTotalBackgroundMemory() {
        long totalBackgroundMemory = 0;
        List<ActivityManager.RunningAppProcessInfo> runningProcesses = mActivityManager.getRunningAppProcesses();
        if (runningProcesses != null) {
            int[] pids = new int[runningProcesses.size()];
            for (int i = 0; i < runningProcesses.size(); i++) {
                pids[i] = runningProcesses.get(i).pid;
            }
            Debug.MemoryInfo[] memoryInfos = mActivityManager.getProcessMemoryInfo(pids);
            for (int i = 0; i < memoryInfos.length; i++) {
                ActivityManager.RunningAppProcessInfo info = runningProcesses.get(i);
                if (info.importance == ActivityManager.RunningAppProcessInfo.IMPORTANCE_BACKGROUND) {
                    long memorySize = memoryInfos[i].getTotalPss() * 1024L;
                    totalBackgroundMemory += memorySize;
                }
            }
        }
        return totalBackgroundMemory;
    }

    private void startMemoryMonitoring() {
        mFuture = ThreadUtils.postOnBackgroundThread(mWorker);
    }

    private void stopMemoryMonitoring() {
        if (mFuture != null && !mFuture.isCancelled()) {
            mFuture.cancel(true);
        }
        mFuture = null;
        if (mHandler != null) {
            mHandler.removeCallbacksAndMessages(null);
        }
    }

    private final Runnable mWorker = new Runnable() {
        @Override
        public void run() {
            synchronized (mLock) {
                mMemInfoReader.readMemInfo();
                long freeMemory = mMemInfoReader.getFreeSize() + mMemInfoReader.getCachedSize() + getTotalBackgroundMemory();  
                String availResult = Formatter.formatShortFileSize(mContext, freeMemory);
                String text = String.format(mMemInfoText, availResult, mTotalResult);
                ThreadUtils.postOnMainThread(() -> {
                    setText(text);
                    setTextColor(0xFFFFFFFF);
                });
                mHandler.postDelayed(this, 1000);
            }
        }
    };
}
