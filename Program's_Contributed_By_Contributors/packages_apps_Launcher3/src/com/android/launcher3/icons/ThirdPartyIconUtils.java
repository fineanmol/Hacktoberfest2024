package com.android.launcher3.icons;

import android.content.Context;
import android.graphics.drawable.Drawable;

import com.android.launcher3.Utilities;
import com.android.launcher3.util.ComponentKey;

import com.android.launcher3.icons.calendar.DynamicCalendar;
import com.android.launcher3.icons.clock.CustomClock;
import com.android.launcher3.icons.clock.DynamicClock;
import com.android.launcher3.icons.pack.IconPackManager;
import com.android.launcher3.icons.pack.IconResolver;
import com.android.launcher3.util.Themes;

class ThirdPartyIconUtils {
    static Drawable getByKey(Context context, ComponentKey key, int iconDpi,
                             IconResolver.DefaultDrawableProvider fallback) {
        IconResolver resolver = IconPackManager.get(context).resolve(key);
        Drawable icon = resolver == null
                ? null
                : resolver.getIcon(iconDpi, fallback);

        if (Utilities.ATLEAST_OREO) {
            // Icon pack clocks go first.
            if (icon != null && resolver.isClock()) {
                return CustomClock.getClock(context, icon, resolver.clockData());
            }

            // Google Clock goes second, but only if the icon pack does not override it.
            if (icon == null && key.componentName.equals(DynamicClock.DESK_CLOCK)) {
                String packageName = key.componentName.getPackageName();
                String themedIconPack = Themes.getThemedIconPack(context);
                IconProvider.ThemeData td = IconProvider.INSTANCE.get(context)
                        .getThemeDataForPackage(packageName, themedIconPack);
                return ClockDrawableWrapper.forPackage(context, packageName, iconDpi, td);
            }
        }

        // Google Calendar is checked last. Only applied if the icon pack does not override it.
        if (icon == null && key.componentName.getPackageName().equals(DynamicCalendar.CALENDAR)) {
            return DynamicCalendar.load(context, key.componentName, iconDpi);
        }

        return icon;
    }
}
