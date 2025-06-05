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

package com.android.launcher3.dragndrop;

import android.annotation.TargetApi;
import android.appwidget.AppWidgetManager;
import android.appwidget.AppWidgetProviderInfo;
import android.content.pm.LauncherApps.PinItemRequest;
import android.os.Build;
import android.os.Bundle;
import android.os.Parcel;
import android.os.Parcelable;

import com.android.launcher3.Launcher;
import com.android.launcher3.model.data.ItemInfo;
import com.android.launcher3.widget.WidgetAddFlowHandler;

/**
 * Extension of WidgetAddFlowHandler to handle pin item request behavior.
 *
 * No config activity is shown even if it is defined in widget config. And a callback is sent when
 * the widget is bound.
 */
@TargetApi(Build.VERSION_CODES.O)
public class PinWidgetFlowHandler extends WidgetAddFlowHandler implements Parcelable {

    private final PinItemRequest mRequest;

    public PinWidgetFlowHandler(AppWidgetProviderInfo providerInfo, PinItemRequest request) {
        super(providerInfo);
        mRequest = request;
    }

    protected PinWidgetFlowHandler(Parcel parcel) {
        super(parcel);
        mRequest = PinItemRequest.CREATOR.createFromParcel(parcel);
    }

    @Override
    public void writeToParcel(Parcel parcel, int i) {
        super.writeToParcel(parcel, i);
        mRequest.writeToParcel(parcel, i);
    }

    @Override
    public boolean startConfigActivity(Launcher launcher, int appWidgetId, ItemInfo info,
            int requestCode) {
        Bundle extras = new Bundle();
        extras.putInt(AppWidgetManager.EXTRA_APPWIDGET_ID, appWidgetId);
        mRequest.accept(extras);
        return false;
    }

    @Override
    public boolean needsConfigure() {
        return false;
    }

    public static final Parcelable.Creator<PinWidgetFlowHandler> CREATOR =
            new Parcelable.Creator<PinWidgetFlowHandler>() {
                public PinWidgetFlowHandler createFromParcel(Parcel source) {
                    return new PinWidgetFlowHandler(source);
                }

                public PinWidgetFlowHandler[] newArray(int size) {
                    return new PinWidgetFlowHandler[size];
                }
            };
}
