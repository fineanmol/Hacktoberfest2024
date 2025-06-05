/*
 * Copyright (C) 2018-2023 crDroid Android Project
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
package com.android.launcher3.quickspace;

import android.animation.LayoutTransition;
import android.animation.ValueAnimator;
import android.animation.ValueAnimator.AnimatorUpdateListener;
import android.content.ActivityNotFoundException;
import android.content.ComponentName;
import android.content.Context;
import android.content.pm.PackageManager;
import android.content.res.ColorStateList;
import android.text.TextUtils.TruncateAt;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.TextView;

import com.android.launcher3.BubbleTextView;
import com.android.launcher3.model.data.ItemInfo;
import com.android.launcher3.R;
import com.android.launcher3.Utilities;
import com.android.launcher3.util.Themes;

import com.android.launcher3.quickspace.QuickspaceController.OnDataListener;
import com.android.launcher3.quickspace.receivers.QuickSpaceActionReceiver;
import com.android.launcher3.quickspace.views.DateTextView;

public class QuickSpaceView extends FrameLayout implements AnimatorUpdateListener, OnDataListener {

    private static final String TAG = "Launcher3:QuickSpaceView";
    private static final boolean DEBUG = false;

    public final ColorStateList mColorStateList;
    public BubbleTextView mBubbleTextView;
    public final int mQuickspaceBackgroundRes;

    public ViewGroup mQuickspaceContent;
    public ImageView mEventSubIcon;
    public ImageView mNowPlayingIcon;
    public TextView mEventTitleSub;
    public TextView mEventTitleSubColored;
    public TextView mGreetingsExt;
    public TextView mGreetingsExtClock;
    public ViewGroup mWeatherContentSub;
    public ImageView mWeatherIconSub;
    public TextView mWeatherTempSub;
    public TextView mEventTitle;

    public boolean mIsQuickEvent;
    public boolean mFinishedInflate;
    public boolean mWeatherAvailable;
    public boolean mAttached;

    private QuickSpaceActionReceiver mActionReceiver;
    public QuickspaceController mController;

    public QuickSpaceView(Context context, AttributeSet set) {
        super(context, set);
        mActionReceiver = new QuickSpaceActionReceiver(context);
        mController = new QuickspaceController(context);
        mColorStateList = ColorStateList.valueOf(Themes.getAttrColor(getContext(), R.attr.workspaceTextColor));
        mQuickspaceBackgroundRes = R.drawable.bg_quickspace;
        setClipChildren(false);
    }

    @Override
    public void onDataUpdated() {
        boolean altUI = Utilities.useAlternativeQuickspaceUI(getContext());
        mController.getEventController().initQuickEvents();
        mIsQuickEvent = mController.isQuickEvent();
        if (mEventTitle == null || (altUI && mGreetingsExt == null)) {
            prepareLayout(altUI);
        }
        mWeatherAvailable = mController.isWeatherAvailable() && 
                mController.getEventController().isDeviceIntroCompleted();
        loadDoubleLine(altUI);
    }

    private final void loadDoubleLine(boolean useAlternativeQuickspaceUI) {
        setBackgroundResource(mQuickspaceBackgroundRes);
        mEventTitle.setText(mController.getEventController().getTitle());
        if (useAlternativeQuickspaceUI) {
            String greetingsExt = mController.getEventController().getGreetings();
            if (greetingsExt != null && !greetingsExt.isEmpty()) {
                mGreetingsExt.setVisibility(View.VISIBLE);
                mGreetingsExt.setText(greetingsExt);
                mGreetingsExt.setEllipsize(TruncateAt.END);
                mGreetingsExt.setOnClickListener(mController.getEventController().getAction());
            } else {
                mGreetingsExt.setVisibility(View.GONE);
            }
            String greetingsExtClock = mController.getEventController().getClockExt();
            if (greetingsExtClock != null && !greetingsExtClock.isEmpty()) {
                mGreetingsExtClock.setVisibility(View.VISIBLE);
                mGreetingsExtClock.setText(greetingsExtClock);
                mGreetingsExtClock.setOnClickListener(mController.getEventController().getAction());
            } else {
                mGreetingsExtClock.setVisibility(View.GONE);
            }
        }
        if (mIsQuickEvent && (Utilities.isQuickspacePersonalityEnabled(getContext()) ||
                        mController.getEventController().isNowPlaying())) {
            mEventTitle.setEllipsize(TruncateAt.MARQUEE);
            mEventTitle.setMarqueeRepeatLimit(3);
            mEventTitle.setSelected(true);
            mEventTitle.setOnClickListener(mController.getEventController().getAction());
            mEventTitleSub.setVisibility(View.VISIBLE);
            mEventTitleSub.setText(mController.getEventController().getActionTitle());
            mEventTitleSub.setEllipsize(TruncateAt.MARQUEE);
            mEventTitleSub.setMarqueeRepeatLimit(3);
            mEventTitleSub.setSelected(true);
            mEventTitleSub.setOnClickListener(mController.getEventController().getAction());
            if (useAlternativeQuickspaceUI) {
                if (mController.getEventController().isNowPlaying()) {
                    mEventSubIcon.setVisibility(View.GONE);
                    mEventTitleSubColored.setVisibility(View.VISIBLE);
                    mNowPlayingIcon.setVisibility(View.VISIBLE);
                    mNowPlayingIcon.setOnClickListener(mController.getEventController().getAction());
                    mEventTitleSubColored.setText(getContext().getString(R.string.qe_now_playing_by));
                    mEventTitleSubColored.setOnClickListener(mController.getEventController().getAction());
                } else {
                    setEventSubIcon();
                    mEventTitleSubColored.setText("");
                    mEventTitleSubColored.setVisibility(View.GONE);
                    mNowPlayingIcon.setVisibility(View.GONE);
                }
            } else {
                setEventSubIcon();
            }
        } else {
            mEventTitleSub.setVisibility(View.GONE);
            mEventSubIcon.setVisibility(View.GONE);
            if (useAlternativeQuickspaceUI) {
                mEventTitleSubColored.setVisibility(View.GONE);
                mNowPlayingIcon.setVisibility(View.GONE);
            }
        }
        bindWeather(mWeatherContentSub, mWeatherTempSub, mWeatherIconSub);
    }

    private void setEventSubIcon() {
        int icon = mController.getEventController().getActionIcon();
        if (icon > 0) {
            mEventSubIcon.setVisibility(View.VISIBLE);
            mEventSubIcon.setImageTintList(mColorStateList);
            mEventSubIcon.setImageResource(mController.getEventController().getActionIcon());
            mEventSubIcon.setOnClickListener(mController.getEventController().getAction());
        } else {
            mEventSubIcon.setVisibility(View.GONE);
        }
    }

    private final void bindWeather(View container, TextView title, ImageView icon) {
        if (!mWeatherAvailable || mController.getEventController().isNowPlaying()) {
            container.setVisibility(View.GONE);
            return;
        }
        String weatherTemp = mController.getWeatherTemp();
        if (weatherTemp == null || weatherTemp.isEmpty()) {
            container.setVisibility(View.GONE);
            return;
        }
        boolean hasGoogleApp = isPackageEnabled("com.google.android.googlequicksearchbox", getContext());
        container.setVisibility(View.VISIBLE);
        container.setOnClickListener(hasGoogleApp ? mActionReceiver.getWeatherAction() : null);
        title.setText(weatherTemp);
        icon.setImageDrawable(mController.getWeatherIcon());
    }

    private final void loadViews() {
        mEventTitle = (TextView) findViewById(R.id.quick_event_title);
        mEventTitleSub = (TextView) findViewById(R.id.quick_event_title_sub);
        mEventTitleSubColored = (TextView) findViewById(R.id.quick_event_title_sub_colored);
        mNowPlayingIcon = (ImageView) findViewById(R.id.now_playing_icon_sub);
        mEventSubIcon = (ImageView) findViewById(R.id.quick_event_icon_sub);
        mWeatherIconSub = (ImageView) findViewById(R.id.quick_event_weather_icon);
        mQuickspaceContent = (ViewGroup) findViewById(R.id.quickspace_content);
        mWeatherContentSub = (ViewGroup) findViewById(R.id.quick_event_weather_content);
        mWeatherTempSub = (TextView) findViewById(R.id.quick_event_weather_temp);
        if (Utilities.useAlternativeQuickspaceUI(getContext())) {
            mGreetingsExtClock = (TextView) findViewById(R.id.extended_greetings_clock);
            mGreetingsExt = (TextView) findViewById(R.id.extended_greetings);
        }
    }

    private void prepareLayout(boolean useAlternativeQuickspaceUI) {
        int indexOfChild = indexOfChild(mQuickspaceContent);
        removeView(mQuickspaceContent);
        if (useAlternativeQuickspaceUI) {
            addView(LayoutInflater.from(getContext()).inflate(R.layout.quickspace_alternate_double, this, false), indexOfChild);
        } else {
            addView(LayoutInflater.from(getContext()).inflate(R.layout.quickspace_doubleline, this, false), indexOfChild);
        }

        loadViews();
        getQuickSpaceView();
    }

    private void getQuickSpaceView() {
        if (mQuickspaceContent.getVisibility() != View.VISIBLE) {
        	mQuickspaceContent.setVisibility(View.VISIBLE);
            mQuickspaceContent.setAlpha(0.0f);
            mQuickspaceContent.animate().setDuration(200).alpha(1.0f);
        }
    }

    @Override
    public void onAnimationUpdate(ValueAnimator valueAnimator) {
        invalidate();
    }

    @Override
    public void onAttachedToWindow() {
        super.onAttachedToWindow();
        if (mAttached)
            return;

        mAttached = true;
        if (mController != null && mFinishedInflate) {
            mController.addListener(this);
        }
    }

    @Override
    public void onDetachedFromWindow() {
        super.onDetachedFromWindow();
        if (!mAttached)
            return;

        mAttached = false;
        if (mController != null) {
            mController.removeListener(this);
        }
    }

    public boolean isPackageEnabled(String pkgName, Context context) {
        try {
            return context.getPackageManager().getApplicationInfo(pkgName, 0).enabled;
        } catch (PackageManager.NameNotFoundException e) {
            return false;
        }
    }

    @Override
    public void onFinishInflate() {
        super.onFinishInflate();
        loadViews();
        mFinishedInflate = true;
        mBubbleTextView = findViewById(R.id.dummyBubbleTextView);
        mBubbleTextView.setTag(new ItemInfo() {
            @Override
            public ComponentName getTargetComponent() {
                return new ComponentName(getContext(), "");
            }
        });
        mBubbleTextView.setContentDescription("");
        if (isAttachedToWindow()) {
            if (mController != null) {
                mController.addListener(this);
            }
        }
    }

    @Override
    public void onLayout(boolean b, int n, int n2, int n3, int n4) {
        super.onLayout(b, n, n2, n3, n4);
    }

    public void onPause() {
        mController.onPause();
    }

    public void onResume() {
        mController.onResume();
    }

    public void setPadding(int n, int n2, int n3, int n4) {
        super.setPadding(0, 0, 0, 0);
    }

}
