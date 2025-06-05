package com.android.launcher3.settings.preference;

import android.content.Context;
import android.content.Intent;
import android.util.AttributeSet;
import android.widget.Toast;
import com.android.launcher3.R;
import com.android.launcher3.Utilities;

import androidx.preference.Preference;

public class RestartPreference extends Preference {


    public RestartPreference(
            Context context, AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
    }

    public RestartPreference(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    public RestartPreference(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public RestartPreference(Context context) {
        super(context);
    }
    
    @Override
    protected void onClick() {
        super.onClick();
        Toast.makeText(getContext(), R.string.restarting_launcher, Toast.LENGTH_SHORT).show();
        Utilities.restart(getContext());
    }
}
