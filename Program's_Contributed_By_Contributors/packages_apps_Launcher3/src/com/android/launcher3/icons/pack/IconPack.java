package com.android.launcher3.icons.pack;

import android.content.ComponentName;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.res.Resources;
import android.util.SparseArray;

import org.xmlpull.v1.XmlPullParserException;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Class that handles the metadata and data of any icon pack.
 */
class IconPack {
    private final ApplicationInfo mAi;
    private final CharSequence mPackageLabel;
    private Data mData;
    private Resources mRes;

    IconPack(ApplicationInfo ai, CharSequence label) {
        mAi = ai;
        mPackageLabel = label;
    }

    ApplicationInfo getAi() {
        return mAi;
    }

    String getPackage() {
        return mAi.packageName;
    }

    CharSequence getTitle() {
        return mPackageLabel;
    }

    Data getData(PackageManager pm)
            throws PackageManager.NameNotFoundException, XmlPullParserException, IOException {
        if (mData == null) {
            mData = IconPackParser.parsePackage(pm, getResources(pm), getPackage());
        }
        return mData;
    }

    int getDrawableId(PackageManager pm, ComponentName name)
            throws PackageManager.NameNotFoundException, IOException, XmlPullParserException {
        Data data = getData(pm);
        Resources res = getResources(pm);
        String pkg = getPackage();
        return res.getIdentifier(data.drawables.get(name), "drawable", pkg);
    }

    private Resources getResources(PackageManager pm) throws PackageManager.NameNotFoundException {
        if (mRes == null) {
            mRes = pm.getResourcesForApplication(getPackage());
        }
        return mRes;
    }

    static class Data {
        final Map<ComponentName, String> drawables = new HashMap<>();
        final Map<ComponentName, String> calendarPrefix = new HashMap<>();
        final SparseArray<Clock> clockMetadata = new SparseArray<>();
        final List<Integer> iconBacks = new ArrayList<>();
        final List<Integer> iconMasks = new ArrayList<>();
        final List<Integer> iconUpons = new ArrayList<>();
        float scale = 1f;

        boolean hasMasking() {
            return !iconBacks.isEmpty() || !iconMasks.isEmpty() || !iconUpons.isEmpty();
        }
    }

    static class Clock {
        final int hourLayerIndex;
        final int minuteLayerIndex;
        final int secondLayerIndex;
        final int defaultHour;
        final int defaultMinute;
        final int defaultSecond;

        Clock(int hourLayerIndex, int minuteLayerIndex, int secondLayerIndex,
              int defaultHour, int defaultMinute, int defaultSecond) {
            this.hourLayerIndex = hourLayerIndex;
            this.minuteLayerIndex = minuteLayerIndex;
            this.secondLayerIndex = secondLayerIndex;
            this.defaultHour = defaultHour;
            this.defaultMinute = defaultMinute;
            this.defaultSecond = defaultSecond;
        }
    }
}
