/*
 * Copyright (C) 2016-2024 crDroid Android Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.android.launcher3.settings.preferences;

import android.annotation.ColorInt;
import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.PorterDuff;
import androidx.core.content.res.TypedArrayUtils;
import androidx.preference.*;
import android.util.AttributeSet;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewParent;
import android.widget.ImageView;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import com.android.launcher3.R;

public class CustomSeekBarPreference extends Preference implements SeekBar.OnSeekBarChangeListener {
    protected final String TAG = getClass().getName();
    private static final String SETTINGS_NS = "http://schemas.android.com/apk/res/com.android.settings";
    protected static final String ANDROIDNS = "http://schemas.android.com/apk/res/android";

    protected int mInterval = 1;
    protected boolean mShowSign = false;
    protected String mUnits = "";
    protected boolean mContinuousUpdates = false;

    protected int mMinValue = 0;
    protected int mMaxValue = 100;
    protected boolean mDefaultValueExists = false;
    protected int mDefaultValue;
    protected boolean mDefaultValueTextExists = false;
    protected String mDefaultValueText;

    protected int mValue;

    protected TextView mValueTextView;
    protected ImageView mResetImageView;
    protected ImageView mMinusImageView;
    protected ImageView mPlusImageView;
    protected SeekBar mSeekBar;

    protected boolean mTrackingTouch = false;
    protected int mTrackingValue;

    public CustomSeekBarPreference(Context context, AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);

        TypedArray a = context.obtainStyledAttributes(attrs, R.styleable.CustomSeekBarPreference);
        int layoutResId;
        try {
            layoutResId = a.getResourceId(R.styleable.CustomSeekBarPreference_customlayout, R.layout.preference_custom_seekbar_middle);

            mShowSign = a.getBoolean(R.styleable.CustomSeekBarPreference_showSign, mShowSign);
            String units = a.getString(R.styleable.CustomSeekBarPreference_units);
            if (units != null)
                mUnits = " " + units;
            mContinuousUpdates = a.getBoolean(R.styleable.CustomSeekBarPreference_continuousUpdates, mContinuousUpdates);
            String defaultValueText = a.getString(R.styleable.CustomSeekBarPreference_defaultValueText);
            mDefaultValueTextExists = defaultValueText != null && !defaultValueText.isEmpty();
            if (mDefaultValueTextExists) {
                mDefaultValueText = defaultValueText;
            }
        } finally {
            a.recycle();
        }

        try {
            String newInterval = attrs.getAttributeValue(SETTINGS_NS, "interval");
            if (newInterval != null)
                mInterval = Integer.parseInt(newInterval);
        } catch (Exception e) {
            Log.e(TAG, "Invalid interval value", e);
        }
        mMinValue = attrs.getAttributeIntValue(SETTINGS_NS, "min", mMinValue);
        mMaxValue = attrs.getAttributeIntValue(ANDROIDNS, "max", mMaxValue);
        if (mMaxValue < mMinValue)
            mMaxValue = mMinValue;
        String defaultValue = attrs.getAttributeValue(ANDROIDNS, "defaultValue");
        mDefaultValueExists = defaultValue != null && !defaultValue.isEmpty();
        if (mDefaultValueExists) {
            mDefaultValue = getLimitedValue(Integer.parseInt(defaultValue));
            mValue = mDefaultValue;
        } else {
            mValue = mMinValue;
        }

        mSeekBar = new SeekBar(context, attrs);
        setLayoutResource(layoutResId);
    }

    public CustomSeekBarPreference(Context context, AttributeSet attrs, int defStyleAttr) {
        this(context, attrs, defStyleAttr, 0);
    }

    public CustomSeekBarPreference(Context context, AttributeSet attrs) {
        this(context, attrs, TypedArrayUtils.getAttr(context,
                androidx.preference.R.attr.preferenceStyle,
                android.R.attr.preferenceStyle));
    }

    public CustomSeekBarPreference(Context context) {
        this(context, null);
    }

    @Override
    public void onDependencyChanged(Preference dependency, boolean disableDependent) {
        super.onDependencyChanged(dependency, disableDependent);
        this.setShouldDisableView(true);
        if (mSeekBar != null)
            mSeekBar.setEnabled(!disableDependent);
        if (mResetImageView != null)
            mResetImageView.setEnabled(!disableDependent);
        if (mPlusImageView != null)
            mPlusImageView.setEnabled(!disableDependent);
        if (mMinusImageView != null)
            mMinusImageView.setEnabled(!disableDependent);
    }

    @Override
    public void onBindViewHolder(PreferenceViewHolder holder) {
        super.onBindViewHolder(holder);
        try
        {
            // move our seekbar to the new view we've been given
            ViewParent oldContainer = mSeekBar.getParent();
            ViewGroup newContainer = (ViewGroup) holder.findViewById(R.id.seekbar);
            if (oldContainer != newContainer) {
                // remove the seekbar from the old view
                if (oldContainer != null) {
                    ((ViewGroup) oldContainer).removeView(mSeekBar);
                }
                // remove the existing seekbar (there may not be one) and add ours
                newContainer.removeAllViews();
                newContainer.addView(mSeekBar, ViewGroup.LayoutParams.FILL_PARENT,
                        ViewGroup.LayoutParams.WRAP_CONTENT);
            }
        } catch (Exception ex) {
            Log.e(TAG, "Error binding view: " + ex.toString());
        }

        mSeekBar.setMax(getSeekValue(mMaxValue));
        mSeekBar.setProgress(getSeekValue(mValue));
        mSeekBar.setEnabled(isEnabled());

        mValueTextView = (TextView) holder.findViewById(R.id.value);
        mResetImageView = (ImageView) holder.findViewById(R.id.reset);
        mMinusImageView = (ImageView) holder.findViewById(R.id.minus);
        mPlusImageView = (ImageView) holder.findViewById(R.id.plus);

        updateValueViews();

        mSeekBar.setOnSeekBarChangeListener(this);
        mResetImageView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(getContext(), getContext().getString(R.string.custom_seekbar_default_value_to_set, getTextValue(mDefaultValue)),
                        Toast.LENGTH_LONG).show();
            }
        });
        mResetImageView.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View view) {
                setValue(mDefaultValue, true);
                return true;
            }
        });
        mMinusImageView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setValue(mValue - mInterval, true);
            }
        });
        mMinusImageView.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View view) {
                setValue(mMaxValue - mMinValue > mInterval * 2 && mMaxValue + mMinValue < mValue * 2 ? Math.floorDiv(mMaxValue + mMinValue, 2) : mMinValue, true);
                return true;
            }
        });
        mPlusImageView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setValue(mValue + mInterval, true);
            }
        });
        mPlusImageView.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View view) {
                setValue(mMaxValue - mMinValue > mInterval * 2 && mMaxValue + mMinValue > mValue * 2 ? -1 * Math.floorDiv(-1 * (mMaxValue + mMinValue), 2) : mMaxValue, true);
                return true;
            }
        });
    }

    protected int getLimitedValue(int v) {
        return v < mMinValue ? mMinValue : (v > mMaxValue ? mMaxValue : v);
    }

    protected int getSeekValue(int v) {
        return 0 - Math.floorDiv(mMinValue - v, mInterval);
    }

    protected String getTextValue(int v) {
        if (mDefaultValueTextExists && mDefaultValueExists && v == mDefaultValue) {
            return mDefaultValueText;
        }
        return (mShowSign && v > 0 ? "+" : "") + String.valueOf(v) + mUnits;
    }

    protected void updateValueViews() {
        if (mValueTextView != null) {
            if (!mTrackingTouch || mContinuousUpdates) {
                if (mDefaultValueTextExists && mDefaultValueExists && mValue == mDefaultValue) {
                    mValueTextView.setText(mDefaultValueText + " (" +
                        getContext().getString(R.string.custom_seekbar_default_value) + ")");
                } else {
                    mValueTextView.setText(getContext().getString(R.string.custom_seekbar_value, getTextValue(mValue)) +
                        (mDefaultValueExists && mValue == mDefaultValue ? " (" +
                        getContext().getString(R.string.custom_seekbar_default_value) + ")" : ""));
                }
            } else {
                if (mDefaultValueTextExists && mDefaultValueExists && mTrackingValue == mDefaultValue) {
                    mValueTextView.setText("[" + mDefaultValueText + "]");
                } else {
                    mValueTextView.setText(getContext().getString(R.string.custom_seekbar_value, "[" + getTextValue(mTrackingValue) + "]"));
                }
            }
        }
        if (mResetImageView != null) {
            if (!mDefaultValueExists || mValue == mDefaultValue || mTrackingTouch)
                mResetImageView.setVisibility(View.INVISIBLE);
            else
                mResetImageView.setVisibility(View.VISIBLE);
        }
        if (mMinusImageView != null) {
            if (mValue == mMinValue || mTrackingTouch) {
                mMinusImageView.setClickable(false);
                mMinusImageView.setColorFilter(getColorAttrDefaultColor(getContext(), android.R.attr.textColorTertiary),
                    PorterDuff.Mode.SRC_IN);
            } else {
                mMinusImageView.setClickable(true);
                mMinusImageView.clearColorFilter();
            }
        }
        if (mPlusImageView != null) {
            if (mValue == mMaxValue || mTrackingTouch) {
                mPlusImageView.setClickable(false);
                mPlusImageView.setColorFilter(getColorAttrDefaultColor(getContext(), android.R.attr.textColorTertiary),
                    PorterDuff.Mode.SRC_IN);
            } else {
                mPlusImageView.setClickable(true);
                mPlusImageView.clearColorFilter();
            }
        }
    }

    @ColorInt
    public static int getColorAttrDefaultColor(Context context, int attr) {
        return getColorAttrDefaultColor(context, attr, 0);
    }

    /**
     * Get color styled attribute {@code attr}, default to {@code defValue} if not found.
     */
    @ColorInt
    public static int getColorAttrDefaultColor(Context context, int attr, @ColorInt int defValue) {
        TypedArray ta = context.obtainStyledAttributes(new int[]{attr});
        @ColorInt int colorAccent = ta.getColor(0, defValue);
        ta.recycle();
        return colorAccent;
    }

    protected void changeValue(int newValue) {
        // for subclasses
    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
        int newValue = getLimitedValue(mMinValue + (progress * mInterval));
        if (mTrackingTouch && !mContinuousUpdates) {
            mTrackingValue = newValue;
            updateValueViews();
        } else if (mValue != newValue) {
            // change rejected, revert to the previous value
            if (!callChangeListener(newValue)) {
                mSeekBar.setProgress(getSeekValue(mValue));
                return;
            }
            // change accepted, store it
            changeValue(newValue);
            persistInt(newValue);

            mValue = newValue;
            updateValueViews();
        }
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {
        mTrackingValue = mValue;
        mTrackingTouch = true;
    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {
        mTrackingTouch = false;
        if (!mContinuousUpdates)
            onProgressChanged(mSeekBar, getSeekValue(mTrackingValue), false);
        notifyChanged();
    }

    @Override
    protected void onSetInitialValue(boolean restoreValue, Object defaultValue) {
        if (restoreValue)
            mValue = getPersistedInt(mValue);
    }

    @Override
    public void setDefaultValue(Object defaultValue) {
        if (defaultValue instanceof Integer)
            setDefaultValue((Integer) defaultValue, mSeekBar != null);
        else
            setDefaultValue(defaultValue == null ? (String) null : defaultValue.toString(), mSeekBar != null);
    }

    public void setDefaultValue(int newValue, boolean update) {
        newValue = getLimitedValue(newValue);
        if (!mDefaultValueExists || mDefaultValue != newValue) {
            mDefaultValueExists = true;
            mDefaultValue = newValue;
            if (update)
                updateValueViews();
        }
    }

    public void setDefaultValue(String newValue, boolean update) {
        if (mDefaultValueExists && (newValue == null || newValue.isEmpty())) {
            mDefaultValueExists = false;
            if (update)
                updateValueViews();
        } else if (newValue != null && !newValue.isEmpty()) {
            setDefaultValue(Integer.parseInt(newValue), update);
        }
    }

    public void setValue(int newValue) {
        mValue = getLimitedValue(newValue);
        if (mSeekBar != null) mSeekBar.setProgress(getSeekValue(mValue));
    }

    public void setValue(int newValue, boolean update) {
        newValue = getLimitedValue(newValue);
        if (mValue != newValue) {
            if (update)
                mSeekBar.setProgress(getSeekValue(newValue));
            else
                mValue = newValue;
        }
    }

    public int getValue() {
        return mValue;
    }

    public void refresh(int newValue) {
        // this will ...
        setValue(newValue, mSeekBar != null);
    }
}
