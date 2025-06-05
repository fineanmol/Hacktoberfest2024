package com.android.launcher3;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.view.View;
import android.view.ViewDebug;
import android.view.ViewGroup;
import android.widget.FrameLayout;

public class InsettableFrameLayout extends FrameLayout implements Insettable {

    @ViewDebug.ExportedProperty(category = "launcher")
    protected Rect mInsets = new Rect();

    public Rect getInsets() {
        return mInsets;
    }

    public InsettableFrameLayout(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public void setFrameLayoutChildInsets(View child, Rect newInsets, Rect oldInsets) {
        final LayoutParams lp = (LayoutParams) child.getLayoutParams();

        if (child instanceof Insettable) {
            ((Insettable) child).setInsets(newInsets);
        } else if (!lp.ignoreInsets) {
            lp.topMargin += (newInsets.top - oldInsets.top);
            lp.leftMargin += (newInsets.left - oldInsets.left);
            lp.rightMargin += (newInsets.right - oldInsets.right);
            lp.bottomMargin += (newInsets.bottom - oldInsets.bottom);
        }
        child.setLayoutParams(lp);
    }

    @Override
    public void setInsets(Rect insets) {
        final int n = getChildCount();
        for (int i = 0; i < n; i++) {
            final View child = getChildAt(i);
            setFrameLayoutChildInsets(child, insets, mInsets);
        }
        mInsets.set(insets);
    }

    @Override
    public LayoutParams generateLayoutParams(AttributeSet attrs) {
        return new InsettableFrameLayout.LayoutParams(getContext(), attrs);
    }

    @Override
    protected LayoutParams generateDefaultLayoutParams() {
        return new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);
    }

    // Override to allow type-checking of LayoutParams.
    @Override
    protected boolean checkLayoutParams(ViewGroup.LayoutParams p) {
        return p instanceof InsettableFrameLayout.LayoutParams;
    }

    @Override
    protected LayoutParams generateLayoutParams(ViewGroup.LayoutParams p) {
        return new LayoutParams(p);
    }

    public static class LayoutParams extends FrameLayout.LayoutParams {
        public boolean ignoreInsets = false;

        public LayoutParams(Context c, AttributeSet attrs) {
            super(c, attrs);
            TypedArray a = c.obtainStyledAttributes(attrs,
                    R.styleable.InsettableFrameLayout_Layout);
            ignoreInsets = a.getBoolean(
                    R.styleable.InsettableFrameLayout_Layout_layout_ignoreInsets, false);
            a.recycle();
        }

        public LayoutParams(int width, int height) {
            super(width, height);
        }

        public LayoutParams(ViewGroup.LayoutParams lp) {
            super(lp);
        }
    }

    @Override
    public void onViewAdded(View child) {
        super.onViewAdded(child);
        if (!isAttachedToWindow()) {
            return;
        }
        setFrameLayoutChildInsets(child, mInsets, new Rect());
    }

    public static void dispatchInsets(ViewGroup parent, Rect insets) {
        final int n = parent.getChildCount();
        for (int i = 0; i < n; i++) {
            final View child = parent.getChildAt(i);
            if (child instanceof Insettable) {
                ((Insettable) child).setInsets(insets);
            }
        }
    }
}
