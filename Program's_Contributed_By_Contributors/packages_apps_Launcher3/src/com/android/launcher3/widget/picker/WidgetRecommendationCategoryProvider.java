/*
 * Copyright (C) 2024 The Android Open Source Project
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

package com.android.launcher3.widget.picker;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.util.Log;

import androidx.annotation.WorkerThread;

import com.android.launcher3.R;
import com.android.launcher3.model.WidgetItem;
import com.android.launcher3.util.Preconditions;
import com.android.launcher3.util.ResourceBasedOverride;

/**
 * A {@link ResourceBasedOverride} that categorizes widget recommendations.
 *
 * <p>Override the {@code widget_recommendation_category_provider_class} resource to provide your
 * own implementation. Method {@code getWidgetRecommendationCategory} is called per widget to get
 * the category.</p>
 */
public class WidgetRecommendationCategoryProvider implements ResourceBasedOverride {
    private static final String TAG = "WidgetRecommendationCategoryProvider";

    /**
     * Retrieve instance of this object that can be overridden in runtime based on the build
     * variant of the application.
     */
    public static WidgetRecommendationCategoryProvider newInstance(Context context) {
        Preconditions.assertWorkerThread();
        return Overrides.getObject(
                WidgetRecommendationCategoryProvider.class, context.getApplicationContext(),
                R.string.widget_recommendation_category_provider_class);
    }

    /**
     * Returns a {@link WidgetRecommendationCategory} for the provided widget item that can be used
     * to display the recommendation grouped by categories.
     */
    @WorkerThread
    public WidgetRecommendationCategory getWidgetRecommendationCategory(Context context,
            WidgetItem item) {
        // This is a default implementation that uses application category to derive the category to
        // be displayed. The implementation can be overridden in individual launcher customization
        // via the overridden WidgetRecommendationCategoryProvider resource.

        Preconditions.assertWorkerThread();
        PackageManager pm = context.getPackageManager();
        if (item.widgetInfo != null && item.widgetInfo.getComponent() != null) {
            String widgetComponentName = item.widgetInfo.getComponent().getClassName();
            try {
                int predictionCategory = pm.getApplicationInfo(
                        item.widgetInfo.getComponent().getPackageName(), 0 /* flags */).category;
                return getCategoryFromApplicationCategory(context, predictionCategory,
                        widgetComponentName);
            } catch (PackageManager.NameNotFoundException e) {
                Log.e(TAG, "Failed to retrieve application category when determining the "
                        + "widget category for " + widgetComponentName, e);
            }
        }
        return null;
    }

    /** Maps application category to an appropriate displayable category. */
    private static WidgetRecommendationCategory getCategoryFromApplicationCategory(
            Context context, int applicationCategory, String componentName) {
        // Weather categories don't map to a specific application category, so, we maintain an
        // allowlist.
        String[] weatherRecommendationAllowlist =
                context.getResources().getStringArray(R.array.weather_recommendations);
        for (String allowedWeatherComponentName : weatherRecommendationAllowlist) {
            if (componentName.equalsIgnoreCase(allowedWeatherComponentName)) {
                return new WidgetRecommendationCategory(
                        R.string.weather_widget_recommendation_category_label, /*order=*/3);
            }
        }

        // Fitness categories don't map to a specific application category, so, we maintain an
        // allowlist.
        String[] fitnessRecommendationAllowlist =
                context.getResources().getStringArray(R.array.fitness_recommendations);
        for (String allowedFitnessComponentName : fitnessRecommendationAllowlist) {
            if (componentName.equalsIgnoreCase(allowedFitnessComponentName)) {
                return new WidgetRecommendationCategory(
                        R.string.fitness_widget_recommendation_category_label, /*order=*/2);
            }
        }

        if (applicationCategory == ApplicationInfo.CATEGORY_PRODUCTIVITY) {
            return new WidgetRecommendationCategory(
                    R.string.productivity_widget_recommendation_category_label, /*order=*/0);
        }

        if (applicationCategory == ApplicationInfo.CATEGORY_NEWS) {
            return new WidgetRecommendationCategory(
                    R.string.news_widget_recommendation_category_label, /*order=*/1);
        }

        if (applicationCategory == ApplicationInfo.CATEGORY_SOCIAL
                || applicationCategory == ApplicationInfo.CATEGORY_AUDIO
                || applicationCategory == ApplicationInfo.CATEGORY_VIDEO
                || applicationCategory == ApplicationInfo.CATEGORY_IMAGE) {
            return new WidgetRecommendationCategory(
                    R.string.social_and_entertainment_widget_recommendation_category_label,
                    /*order=*/4);
        }

        return new WidgetRecommendationCategory(
                R.string.others_widget_recommendation_category_label, /*order=*/5);
    }

}
