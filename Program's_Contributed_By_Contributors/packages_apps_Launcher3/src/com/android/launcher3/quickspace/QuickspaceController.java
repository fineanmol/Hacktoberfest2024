/*
 * Copyright (C) 2018 CypherOS
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

import android.annotation.NonNull;
import android.content.Context;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.Icon;
import android.media.AudioManager;
import android.media.MediaMetadata;
import android.media.session.MediaController;
import android.media.session.MediaSession;
import android.media.session.MediaSessionManager;
import android.media.session.PlaybackState;
import android.os.Handler;
import android.service.notification.StatusBarNotification;
import android.text.TextUtils;
import android.util.Log;

import com.android.internal.util.everest.OmniJawsClient;

import com.android.launcher3.R;
import com.android.launcher3.Utilities;
import com.android.launcher3.notification.NotificationKeyData;
import com.android.launcher3.notification.NotificationListener;
import com.android.launcher3.util.PackageUserKey;

import java.util.ArrayList;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;
import java.util.List;

public class QuickspaceController implements NotificationListener.NotificationsChangedListener, OmniJawsClient.OmniJawsObserver {

    public final ArrayList<OnDataListener> mListeners = new ArrayList();
    private static final String SETTING_WEATHER_LOCKSCREEN_UNIT = "weather_lockscreen_unit";
    private static final boolean DEBUG = false;
    private static final String TAG = "Launcher3:QuickspaceController";

    private final Context mContext;
    private final Handler mHandler;
    private QuickEventsController mEventsController;
    private OmniJawsClient mWeatherClient;
    private OmniJawsClient.WeatherInfo mWeatherInfo;
    private Drawable mConditionImage;

    private boolean mUseImperialUnit;

    private AudioManager mAudioManager;
    private MediaController mController;
    private MediaMetadata mMediaMetadata;
    private String mLastTrackTitle = null;

    private ExecutorService executorService = Executors.newSingleThreadExecutor();

    public interface OnDataListener {
        void onDataUpdated();
    }

    private final MediaController.Callback mMediaCallback = new MediaController.Callback() {
        @Override
        public void onPlaybackStateChanged(@NonNull PlaybackState state) {
            updateMediaController();
        }
        @Override
        public void onMetadataChanged(MediaMetadata metadata) {
            super.onMetadataChanged(metadata);
            mMediaMetadata = metadata;
            updateMediaController();
        }
    };

    public QuickspaceController(Context context) {
        mContext = context;
        mHandler = new Handler();
        mEventsController = new QuickEventsController(context);
        mWeatherClient = new OmniJawsClient(context);
        mAudioManager = (AudioManager) context.getSystemService(Context.AUDIO_SERVICE);
        updateMediaController();
    }

    private void addWeatherProvider() {
        if (!Utilities.isQuickspaceWeather(mContext)) return;
        mWeatherClient.addObserver(this);
        queryAndUpdateWeather();
    }

    public void addListener(OnDataListener listener) {
        mListeners.add(listener);
        addWeatherProvider();
        listener.onDataUpdated();
    }

    public void removeListener(OnDataListener listener) {
        if (mWeatherClient != null) {
            mWeatherClient.removeObserver(this);
        }
        mListeners.remove(listener);
    }

    public boolean isQuickEvent() {
        return mEventsController.isQuickEvent();
    }

    public QuickEventsController getEventController() {
        return mEventsController;
    }

    public boolean isWeatherAvailable() {
        return mWeatherClient != null && mWeatherClient.isOmniJawsEnabled();
    }

    public Drawable getWeatherIcon() {
        return mConditionImage;
    }

    public String getWeatherTemp() {
        boolean shouldShowCity = Utilities.QuickSpaceShowCity(mContext);
        boolean showWeatherText = Utilities.QuickSpaceShowWeatherText(mContext);
        if (mWeatherInfo != null) {
            String formattedCondition = mWeatherInfo.condition;
            if (formattedCondition.toLowerCase().contains("clouds")) {
                formattedCondition = mContext.getResources().getString(R.string.quick_event_weather_clouds);
            } else if (formattedCondition.toLowerCase().contains("rain")) {
                formattedCondition = mContext.getResources().getString(R.string.quick_event_weather_rain);
            } else if (formattedCondition.toLowerCase().contains("clear")) {
                formattedCondition = mContext.getResources().getString(R.string.quick_event_weather_clear);
            } else if (formattedCondition.toLowerCase().contains("storm")) {
                formattedCondition = mContext.getResources().getString(R.string.quick_event_weather_storm);
            } else if (formattedCondition.toLowerCase().contains("snow")) {
                formattedCondition = mContext.getResources().getString(R.string.quick_event_weather_snow);
            } else if (formattedCondition.toLowerCase().contains("wind")) {
                formattedCondition = mContext.getResources().getString(R.string.quick_event_weather_wind);
            } else if (formattedCondition.toLowerCase().contains("mist")) {
                formattedCondition = mContext.getResources().getString(R.string.quick_event_weather_mist);
            }
            String weatherTemp = (shouldShowCity ? mWeatherInfo.city : "") + " " + mWeatherInfo.temp +
                    mWeatherInfo.tempUnits  + (showWeatherText ? " · "  + formattedCondition : "");
            return weatherTemp;
        }
        return null;
    }

    public void updateMediaInfo() {
        boolean isPlaying = isMediaControllerAvailable() 
            && PlaybackState.STATE_PLAYING == getMediaControllerPlaybackState(mController);
        String trackArtist = mMediaMetadata != null ? mMediaMetadata.getString(MediaMetadata.METADATA_KEY_ARTIST) : "";
        String trackTitle = mMediaMetadata != null ? mMediaMetadata.getString(MediaMetadata.METADATA_KEY_TITLE) : "";
        if (mEventsController != null && Utilities.isQuickspaceNowPlaying(mContext)) {
            mEventsController.setMediaInfo(trackTitle, trackArtist, isPlaying);
            mEventsController.updateQuickEvents();
            notifyListeners();
        }
    }

    private int getMediaControllerPlaybackState(MediaController controller) {
        if (controller != null) {
            final PlaybackState playbackState = controller.getPlaybackState();
            if (playbackState != null) {
                return playbackState.getState();
            }
        }
        return PlaybackState.STATE_NONE;
    }

    @Override
    public void onNotificationPosted(PackageUserKey postedPackageUserKey,
                                     NotificationKeyData notificationKey) {
        updateMediaController();
    }

    @Override
    public void onNotificationRemoved(PackageUserKey removedPackageUserKey,
                                      NotificationKeyData notificationKey) {
        updateMediaController();
    }

    @Override
    public void onNotificationFullRefresh(List<StatusBarNotification> activeNotifications) {
        updateMediaController();
    }

    public void onPause() {
        if (mEventsController != null) mEventsController.onPause();
    }

    public void onResume() {
        if (mEventsController != null) {
            updateMediaController();
            mEventsController.onResume();
            notifyListeners();
        }
    }

    @Override
    public void weatherUpdated() {
        queryAndUpdateWeather();
    }

    @Override
    public void weatherError(int errorReason) {
        Log.d(TAG, "weatherError " + errorReason);
        if (errorReason == OmniJawsClient.EXTRA_ERROR_DISABLED) {
            mWeatherInfo = null;
            notifyListeners();
        }
    }

    @Override
    public void updateSettings() {
        Log.i(TAG, "updateSettings");
        queryAndUpdateWeather();
    }

    private void queryAndUpdateWeather() {
        executorService.execute(new Runnable() {
            @Override
            public void run() {
                try {
                    mWeatherClient.queryWeather();
                    mWeatherInfo = mWeatherClient.getWeatherInfo();
                    if (mWeatherInfo != null) {
                        mConditionImage = mWeatherClient.getWeatherConditionImage(mWeatherInfo.conditionCode);
                    }
                    notifyListeners();
                } catch(Exception e) {
                    // Do nothing
                }
            }
        });
    }

    public void notifyListeners() {
        mHandler.post(new Runnable() {
            @Override
            public void run() {
                for (OnDataListener list : mListeners) {
                    list.onDataUpdated();
                }
            }
        });
    }

    private boolean isMediaControllerAvailable() {
        final MediaController mediaController = getActiveLocalMediaController();
        return mediaController != null && !TextUtils.isEmpty(mediaController.getPackageName());
    }

    private MediaController getActiveLocalMediaController() {
        MediaSessionManager mediaSessionManager =
                mContext.getSystemService(MediaSessionManager.class);
        MediaController localController = null;
        final List<String> remoteMediaSessionLists = new ArrayList<>();
        for (MediaController controller : mediaSessionManager.getActiveSessions(null)) {
            final MediaController.PlaybackInfo pi = controller.getPlaybackInfo();
            if (pi == null) {
                continue;
            }
            final PlaybackState playbackState = controller.getPlaybackState();
            if (playbackState == null) {
                continue;
            }
            if (playbackState.getState() != PlaybackState.STATE_PLAYING) {
                continue;
            }
            if (pi.getPlaybackType() == MediaController.PlaybackInfo.PLAYBACK_TYPE_REMOTE) {
                if (localController != null
                        && TextUtils.equals(
                                localController.getPackageName(), controller.getPackageName())) {
                    localController = null;
                }
                if (!remoteMediaSessionLists.contains(controller.getPackageName())) {
                    remoteMediaSessionLists.add(controller.getPackageName());
                }
                continue;
            }
            if (pi.getPlaybackType() == MediaController.PlaybackInfo.PLAYBACK_TYPE_LOCAL) {
                if (localController == null
                        && !remoteMediaSessionLists.contains(controller.getPackageName())) {
                    localController = controller;
                }
            }
        }
        return localController;
    }
    
    private void updateMediaController() {
        MediaController localController = getActiveLocalMediaController();
        if (localController != null && !sameSessions(mController, localController)) {
            if (mController != null) {
                mController.unregisterCallback(mMediaCallback);
                mController = null;
            }
            mController = localController;
            mController.registerCallback(mMediaCallback);
        }
        mMediaMetadata = isMediaControllerAvailable() ? mController.getMetadata() : null;
        updateMediaInfo();
    }
    
    private boolean sameSessions(MediaController a, MediaController b) {
        if (a == b) {
            return true;
        }
        if (a == null) {
            return false;
        }
        return a.controlsSameSession(b);
    }
}
