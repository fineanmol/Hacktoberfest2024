package com.android.launcher3.shortcuts;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ShortcutInfo;
import android.os.UserHandle;

import com.android.launcher3.model.data.ItemInfo;
import com.android.launcher3.util.ComponentKey;

/**
 * A key that uniquely identifies a shortcut using its package, id, and user handle.
 */
public class ShortcutKey extends ComponentKey {

    public static final String EXTRA_SHORTCUT_ID = "shortcut_id";
    private static final String INTENT_CATEGORY = "com.android.launcher3.DEEP_SHORTCUT";

    public ShortcutKey(String packageName, UserHandle user, String id) {
        // Use the id as the class name.
        super(new ComponentName(packageName, id), user);
    }

    public ShortcutKey(ComponentName componentName, UserHandle user) {
        super(componentName, user);
    }

    public String getId() {
        return componentName.getClassName();
    }

    public String getPackageName() {
        return componentName.getPackageName();
    }

    /**
     * Creates a {@link ShortcutRequest} for this key
     */
    public ShortcutRequest buildRequest(Context context) {
        return new ShortcutRequest(context, user)
                .forPackage(componentName.getPackageName(), getId());
    }

    public static ShortcutKey fromInfo(ShortcutInfo shortcutInfo) {
        return new ShortcutKey(shortcutInfo.getPackage(), shortcutInfo.getUserHandle(),
                shortcutInfo.getId());
    }

    public static ShortcutKey fromIntent(Intent intent, UserHandle user) {
        String shortcutId = intent.getStringExtra(EXTRA_SHORTCUT_ID);
        return new ShortcutKey(intent.getPackage(), user, shortcutId);
    }

    public static ShortcutKey fromItemInfo(ItemInfo info) {
        return fromIntent(info.getIntent(), info.user);
    }

    public static Intent makeIntent(ShortcutInfo si) {
        return makeIntent(si.getId(), si.getPackage()).setComponent(si.getActivity());
    }

    /**
     * Creates an intent for shortcut id and package name.
     */
    public static Intent makeIntent(String shortcutId, String packageName) {
        return new Intent(Intent.ACTION_MAIN)
                .addCategory(INTENT_CATEGORY)
                .setPackage(packageName)
                .setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_RESET_TASK_IF_NEEDED)
                .putExtra(EXTRA_SHORTCUT_ID, shortcutId);
    }
}
