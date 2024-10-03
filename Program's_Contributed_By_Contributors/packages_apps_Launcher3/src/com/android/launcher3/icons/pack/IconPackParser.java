package com.android.launcher3.icons.pack;

import android.content.ComponentName;
import android.content.pm.PackageManager;
import android.content.res.Resources;
import android.content.res.XmlResourceParser;
import android.util.Log;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;

import java.io.IOException;
import java.util.List;

class IconPackParser {
    private static final String TAG = "IconPackParser";

    static IconPack.Data parsePackage(PackageManager pm, Resources res, String pkg)
            throws IOException, XmlPullParserException {
        IconPack.Data iconPack = new IconPack.Data();

        int resId = res.getIdentifier("appfilter", "xml", pkg);
        if (resId != 0) {
            XmlResourceParser parseXml = pm.getXml(pkg, resId, null);
            while (parseXml.next() != XmlPullParser.END_DOCUMENT) {
                if (parseXml.getEventType() == XmlPullParser.START_TAG) {
                    switch (parseXml.getName()) {
                        case "item":
                            addItem(parseXml, iconPack);
                            break;
                        case "calendar":
                            addCalendar(parseXml, iconPack);
                            break;
                        case "iconback":
                            addImgsTo(res, pkg, parseXml, iconPack.iconBacks);
                            break;
                        case "iconmask":
                            addImgsTo(res, pkg, parseXml, iconPack.iconMasks);
                            break;
                        case "iconupon":
                            addImgsTo(res, pkg, parseXml, iconPack.iconUpons);
                            break;
                        case "scale":
                            setScale(parseXml, iconPack);
                            break;
                        case "dynamic-clock":
                            addClock(res, pkg, parseXml, iconPack);
                            break;
                    }
                }
            }
        }

        return iconPack;
    }

    private static void addItem(XmlResourceParser parseXml,
                                IconPack.Data iconPack) {
        String component = parseXml.getAttributeValue(null, "component");
        String drawable = parseXml.getAttributeValue(null, "drawable");
        if (component != null && drawable != null) {
            ComponentName componentName = parseComponent(component);
            if (componentName != null) {
                iconPack.drawables.put(componentName, drawable);
            }
        }
    }

    private static void addCalendar(XmlResourceParser parseXml, IconPack.Data iconPack) {
        String component = parseXml.getAttributeValue(null, "component");
        String prefix = parseXml.getAttributeValue(null, "prefix");
        if (component != null && prefix != null) {
            ComponentName componentName = parseComponent(component);
            if (componentName != null) {
                iconPack.calendarPrefix.put(componentName, prefix);
            }
        }
    }

    private static ComponentName parseComponent(String component) {
        if (component.startsWith("ComponentInfo{") && component.endsWith("}")) {
            component = component.substring(14, component.length() - 1);
            return ComponentName.unflattenFromString(component);
        }
        return null;
    }

    private static void addImgsTo(Resources res, String pkg, XmlResourceParser parseXml,
                                  List<Integer> list) {
        for (int i = 0; i < parseXml.getAttributeCount(); i++) {
            if (parseXml.getAttributeName(i).startsWith("img")) {
                int id = res.getIdentifier(parseXml.getAttributeValue(i), "drawable", pkg);
                if (id != 0) {
                    list.add(id);
                }
            }
        }
    }

    private static void setScale(XmlResourceParser parseXml, IconPack.Data iconPack) {
        String factor = parseXml.getAttributeValue(null, "factor");
        if (factor != null) {
            try {
                // ToDo: Parse reference to dimens
                iconPack.scale = Float.parseFloat(factor);
            } catch (NumberFormatException e) {
                Log.d(TAG, "Invalid scale: " + factor, e);
            }
        }
    }

    private static void addClock(Resources res, String pkg, XmlResourceParser parseXml,
                                 IconPack.Data iconPack) {
        String drawable = parseXml.getAttributeValue(null, "drawable");
        if (drawable != null) {
            int drawableId = res.getIdentifier(drawable, "drawable", pkg);
            if (drawableId != 0) {
                iconPack.clockMetadata.put(drawableId, new IconPack.Clock(
                        parseXml.getAttributeIntValue(null, "hourLayerIndex", -1),
                        parseXml.getAttributeIntValue(null, "minuteLayerIndex", -1),
                        parseXml.getAttributeIntValue(null, "secondLayerIndex", -1),
                        parseXml.getAttributeIntValue(null, "defaultHour", 0),
                        parseXml.getAttributeIntValue(null, "defaultMinute", 0),
                        parseXml.getAttributeIntValue(null, "defaultSecond", 0)));
            }
        }
    }
}
