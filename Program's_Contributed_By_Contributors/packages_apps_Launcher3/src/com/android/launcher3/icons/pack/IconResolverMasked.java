package com.android.launcher3.icons.pack;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffXfermode;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;

import com.android.launcher3.icons.BaseIconFactory;
import com.android.launcher3.icons.LauncherIcons;
import static com.android.launcher3.icons.LauncherIcons.CONFIG_HINT_NO_WRAP;

import com.android.launcher3.icons.clock.CustomClock;

public class IconResolverMasked implements IconResolver {
    private final Context mContext;
    private final IconPack.Data mData;
    private final ApplicationInfo mPackInfo;
    private final int mHashCode;

    private final Canvas mCanvas = new Canvas();
    private final Paint mPaint = new Paint(Paint.ANTI_ALIAS_FLAG | Paint.FILTER_BITMAP_FLAG);

    IconResolverMasked(Context context, IconPack.Data data, ApplicationInfo packInfo,
                       int hashCode) {
        mContext = context;
        mData = data;
        mPackInfo = packInfo;
        mHashCode = hashCode & 0xFFFF;
    }

    @Override
    public boolean isCalendar() {
        return false;
    }

    @Override
    public boolean isClock() {
        return false;
    }

    @Override
    public CustomClock.Metadata clockData() {
        return null;
    }

    @Override
    public Drawable getIcon(int iconDpi, DefaultDrawableProvider fallback) {
        Drawable icon = fallback.get();

        LauncherIcons li = LauncherIcons.obtain(mContext);
        PackageManager pm = mContext.getPackageManager();
        try {
            Resources res = pm.getResourcesForApplication(mPackInfo);

            // Re-render without scaling after creating the bitmap in the right dimensions.
            Bitmap iconBm = li.createScaledBitmap(icon, BaseIconFactory.MODE_WITH_SHADOW);
            mCanvas.setBitmap(iconBm);
            icon.setBounds(0, 0, iconBm.getWidth(), iconBm.getHeight());
            icon.draw(mCanvas);

            // Scale the bitmap using the icon pack scale.
            scaleBitmap(iconBm, mData.scale);

            // Cut parts off using the mask image.
            if (!mData.iconMasks.isEmpty()) {
                int iconMask = mData.iconMasks.get(mHashCode % mData.iconMasks.size());
                maskBitmap(iconBm, res.getDrawableForDensity(iconMask, iconDpi, null));
            }

            // Add icon back after scaling.
            if (!mData.iconBacks.isEmpty()) {
                int iconBack = mData.iconBacks.get(mHashCode % mData.iconBacks.size());
                backBitmap(iconBm, res.getDrawableForDensity(iconBack, iconDpi, null), li);
            }

            // Render upon image onto icon. We use SRC_ATOP to make sure it stays within bounds.
            if (!mData.iconUpons.isEmpty()) {
                int iconUpon = mData.iconUpons.get(mHashCode % mData.iconUpons.size());
                uponBitmap(iconBm, res.getDrawableForDensity(iconUpon, iconDpi, null));
            }

            return new BitmapDrawable(mContext.getResources(), iconBm);
        } catch (PackageManager.NameNotFoundException | Resources.NotFoundException e) {
            e.printStackTrace();
        }

        li.recycle();
        return icon;
    }

    private void scaleBitmap(Bitmap bitmap, float scale) {
        if (scale != 1f) {
            Bitmap iconBmScaled = Bitmap.createScaledBitmap(bitmap,
                    (int)(bitmap.getWidth() * mData.scale),
                    (int)(bitmap.getHeight() * mData.scale),
                    true);

            float move = 0.5f * (1f - mData.scale);

            Matrix matrix = new Matrix();
            matrix.postTranslate(move * bitmap.getWidth(), move * bitmap.getHeight());

            bitmap.eraseColor(Color.TRANSPARENT);
            mCanvas.setBitmap(bitmap);
            mCanvas.drawBitmap(iconBmScaled, matrix, null);

            iconBmScaled.recycle();
        }
    }

    private void maskBitmap(Bitmap bitmap, Drawable mask) {
        if (mask != null) {
            Bitmap maskBm = Bitmap.createBitmap(
                    bitmap.getWidth(), bitmap.getHeight(), Bitmap.Config.ARGB_8888);

            // Render the mask image to a bitmap.
            mCanvas.setBitmap(maskBm);
            mask.setBounds(0, 0, bitmap.getWidth(), bitmap.getHeight());
            mask.draw(mCanvas);

            // Then use PorterDuff to remove black mask parts.
            mPaint.setXfermode(new PorterDuffXfermode(PorterDuff.Mode.DST_OUT));
            mCanvas.setBitmap(bitmap);
            mCanvas.drawBitmap(maskBm, 0f, 0f, mPaint);

            maskBm.recycle();
        }
    }

    @SuppressLint("WrongConstant")
    private void backBitmap(Bitmap bitmap, Drawable back, LauncherIcons li) {
        if (back != null) {
            Bitmap backBm = Bitmap.createBitmap(
                    bitmap.getWidth(), bitmap.getHeight(), Bitmap.Config.ARGB_8888);

            mCanvas.setBitmap(backBm);
            back.setBounds(0, 0, bitmap.getWidth(), bitmap.getHeight());
            back.draw(mCanvas);

            mPaint.setXfermode(new PorterDuffXfermode(PorterDuff.Mode.DST_OVER));
            mCanvas.setBitmap(bitmap);
            mCanvas.drawBitmap(backBm, 0f, 0f, mPaint);

            backBm.recycle();
        }
    }

    private void uponBitmap(Bitmap bitmap, Drawable upon) {
        if (upon != null) {
            Bitmap uponBm = Bitmap.createBitmap(
                    bitmap.getWidth(), bitmap.getHeight(), Bitmap.Config.ARGB_8888);

            mCanvas.setBitmap(uponBm);
            upon.setBounds(0, 0, bitmap.getWidth(), bitmap.getHeight());
            upon.draw(mCanvas);

            mPaint.setXfermode(new PorterDuffXfermode(PorterDuff.Mode.SRC_ATOP));
            mCanvas.setBitmap(bitmap);
            mCanvas.drawBitmap(uponBm, 0f, 0f, mPaint);

            uponBm.recycle();
        }
    }
}
