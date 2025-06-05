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

package com.android.launcher3;

import static com.android.launcher3.util.DisplayController.CHANGE_ROTATION;

import android.content.Context;
import android.content.res.Configuration;
import android.os.Bundle;
import android.view.ActionMode;
import android.view.View;

import androidx.annotation.MainThread;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.android.launcher3.model.data.ItemInfo;
import com.android.launcher3.touch.ItemClickHandler;
import com.android.launcher3.util.ActivityOptionsWrapper;
import com.android.launcher3.util.DisplayController;
import com.android.launcher3.util.DisplayController.DisplayInfoChangeListener;
import com.android.launcher3.util.DisplayController.Info;
import com.android.launcher3.util.OnColorHintListener;
import com.android.launcher3.util.Themes;
import com.android.launcher3.util.WallpaperColorHints;
import com.android.launcher3.util.WindowBounds;

/**
 * Extension of BaseActivity allowing support for drag-n-drop
 */
@SuppressWarnings("NewApi")
public abstract class BaseDraggingActivity extends BaseActivity
        implements OnColorHintListener, DisplayInfoChangeListener {

    // When starting an action mode, setting this tag will cause the action mode to be cancelled
    // automatically when user interacts with the launcher.
    public static final Object AUTO_CANCEL_ACTION_MODE = new Object();

    private ActionMode mCurrentActionMode;

    private int mThemeRes = R.style.AppTheme;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        DisplayController.INSTANCE.get(this).addChangeListener(this);

        // Update theme
        WallpaperColorHints.get(this).registerOnColorHintsChangedListener(this);
        int themeRes = Themes.getActivityThemeRes(this);
        if (themeRes != mThemeRes) {
            mThemeRes = themeRes;
            setTheme(themeRes);
        }
    }

    @MainThread
    @Override
    public void onColorHintsChanged(int colorHints) {
        updateTheme();
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        updateTheme();
    }

    private void updateTheme() {
        if (mThemeRes != Themes.getActivityThemeRes(this)) {
            recreate();
        }
    }

    @Override
    public void onActionModeStarted(ActionMode mode) {
        super.onActionModeStarted(mode);
        mCurrentActionMode = mode;
    }

    @Override
    public void onActionModeFinished(ActionMode mode) {
        super.onActionModeFinished(mode);
        mCurrentActionMode = null;
    }

    protected boolean isInAutoCancelActionMode() {
        return mCurrentActionMode != null && AUTO_CANCEL_ACTION_MODE == mCurrentActionMode.getTag();
    }

    @Override
    public boolean finishAutoCancelActionMode() {
        if (isInAutoCancelActionMode()) {
            mCurrentActionMode.finish();
            return true;
        }
        return false;
    }

    public abstract <T extends View> T getOverviewPanel();

    public abstract View getRootView();

    public void returnToHomescreen() {
        // no-op
    }

    @Override
    @NonNull
    public ActivityOptionsWrapper getActivityLaunchOptions(View v, @Nullable ItemInfo item) {
        ActivityOptionsWrapper wrapper = super.getActivityLaunchOptions(v, item);
        addEventCallback(EVENT_RESUMED, wrapper.onEndCallback::executeAllAndDestroy);
        return wrapper;
    }

    @Override
    public ActivityOptionsWrapper makeDefaultActivityOptions(int splashScreenStyle) {
        ActivityOptionsWrapper wrapper = super.makeDefaultActivityOptions(splashScreenStyle);
        addEventCallback(EVENT_RESUMED, wrapper.onEndCallback::executeAllAndDestroy);
        return wrapper;
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        DisplayController.INSTANCE.get(this).removeChangeListener(this);
        WallpaperColorHints.get(this).unregisterOnColorsChangedListener(this);
    }

    protected void onDeviceProfileInitiated() {
        if (mDeviceProfile.isVerticalBarLayout()) {
            mDeviceProfile.updateIsSeascape(this);
        }
    }

    @Override
    public void onDisplayInfoChanged(Context context, Info info, int flags) {
        if ((flags & CHANGE_ROTATION) != 0 && mDeviceProfile.updateIsSeascape(this)) {
            reapplyUi();
        }
    }

    @Override
    public View.OnClickListener getItemOnClickListener() {
        return ItemClickHandler.INSTANCE;
    }

    protected abstract void reapplyUi();

    protected WindowBounds getMultiWindowDisplaySize() {
        return WindowBounds.fromWindowMetrics(getWindowManager().getCurrentWindowMetrics());
    }

    @Override
    public boolean isAppBlockedForSafeMode() {
        return LauncherAppState.getInstance(this).isSafeModeEnabled();
    }
}
