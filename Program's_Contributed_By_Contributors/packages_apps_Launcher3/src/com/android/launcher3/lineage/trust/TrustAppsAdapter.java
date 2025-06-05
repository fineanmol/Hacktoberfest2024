/*
 * Copyright (C) 2019 The LineageOS Project
 * Copyright (C) 2023 AlphaDroid
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
package com.android.launcher3.lineage.trust;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.graphics.drawable.Animatable2;
import android.graphics.drawable.AnimatedVectorDrawable;
import android.graphics.drawable.Drawable;
import android.os.Build;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.DiffUtil;
import androidx.recyclerview.widget.RecyclerView;

import com.android.internal.util.everest.EverestUtils;
import com.android.launcher3.R;
import com.android.launcher3.lineage.trust.db.TrustComponent;

import java.util.ArrayList;
import java.util.List;

class TrustAppsAdapter extends RecyclerView.Adapter<TrustAppsAdapter.ViewHolder> {
    private List<TrustComponent> mList = new ArrayList<>();
    private Listener mListener;
    private boolean mHasSecureKeyguard;
    private Context mContext;

    TrustAppsAdapter(Context context, Listener listener, boolean hasSecureKeyguard) {
        mContext = context;
        mListener = listener;
        mHasSecureKeyguard = hasSecureKeyguard;
    }

    public void update(List<TrustComponent> list) {
        DiffUtil.DiffResult result = DiffUtil.calculateDiff(new Callback(mList, list));
        mList = list;
        result.dispatchUpdatesTo(this);
    }

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int type) {
        return new ViewHolder(LayoutInflater.from(parent.getContext())
                .inflate(R.layout.item_hidden_app, parent, false));
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder viewHolder, int i) {
        viewHolder.bind(mList.get(i), mHasSecureKeyguard);
    }

    @Override
    public int getItemCount() {
        return mList.size();
    }

    public interface Listener {
        void onHiddenItemChanged(@NonNull TrustComponent component);

        void onProtectedItemChanged(@NonNull TrustComponent component);
    }

    class ViewHolder extends RecyclerView.ViewHolder {
        private ImageView mIconView;
        private TextView mLabelView;
        private ImageView mHiddenView;
        private ImageView mProtectedView;

        ViewHolder(@NonNull View itemView) {
            super(itemView);

            mIconView = itemView.findViewById(R.id.item_hidden_app_icon);
            mLabelView = itemView.findViewById(R.id.item_hidden_app_title);
            mHiddenView = itemView.findViewById(R.id.item_hidden_app_switch);
            mProtectedView = itemView.findViewById(R.id.item_protected_app_switch);
        }

        void bind(TrustComponent component, boolean hasSecureKeyguard) {
            mIconView.setImageDrawable(component.getIcon());
            mLabelView.setText(component.getLabel());

            mHiddenView.setImageResource(component.isHidden() ?
                    R.drawable.ic_hidden_locked : R.drawable.ic_hidden_unlocked);

            mProtectedView.setImageResource(component.isProtected() ?
                    R.drawable.ic_protected_locked : R.drawable.ic_protected_unlocked);

            mProtectedView.setVisibility(hasSecureKeyguard ? View.VISIBLE : View.GONE);

            mHiddenView.setVisibility(EverestUtils.launchablePackages(mContext).contains(component.getPackageName()) ?
                    View.VISIBLE : View.GONE);

            mHiddenView.setOnClickListener(v -> {
                component.invertVisibility();

                mHiddenView.setImageResource(component.isHidden() ?
                        R.drawable.avd_hidden_lock : R.drawable.avd_hidden_unlock);
                AnimatedVectorDrawable avd = (AnimatedVectorDrawable) mHiddenView.getDrawable();

                int position = getAdapterPosition();
                if (Build.VERSION.SDK_INT > Build.VERSION_CODES.M) {
                    avd.registerAnimationCallback(new Animatable2.AnimationCallback() {
                        @Override
                        public void onAnimationEnd(Drawable drawable) {
                            updateHiddenList(position, component);
                        }
                    });
                    avd.start();
                } else {
                    avd.start();
                    updateHiddenList(position, component);
                }
            });

            mProtectedView.setOnClickListener(v -> {
                component.invertProtection();

                mProtectedView.setImageResource(component.isProtected() ?
                        R.drawable.avd_protected_lock : R.drawable.avd_protected_unlock);
                AnimatedVectorDrawable avd = (AnimatedVectorDrawable) mProtectedView.getDrawable();

                int position = getAdapterPosition();
                if (Build.VERSION.SDK_INT > Build.VERSION_CODES.M) {
                    avd.registerAnimationCallback(new Animatable2.AnimationCallback() {
                        @Override
                        public void onAnimationEnd(Drawable drawable) {
                            updateProtectedList(position, component);
                        }
                    });
                    avd.start();
                } else {
                    avd.start();
                    updateProtectedList(position, component);
                }
            });
        }

        private void updateHiddenList(int position, TrustComponent component) {
            mListener.onHiddenItemChanged(component);
            updateList(position, component);
        }

        private void updateProtectedList(int position, TrustComponent component) {
            mListener.onProtectedItemChanged(component);
            updateList(position, component);
        }

        private void updateList(int position, TrustComponent component) {
            mList.set(position, component);
            notifyItemChanged(position);
        }
    }

    private static class Callback extends DiffUtil.Callback {
        List<TrustComponent> mOldList;
        List<TrustComponent> mNewList;

        public Callback(List<TrustComponent> oldList,
                        List<TrustComponent> newList) {
            mOldList = oldList;
            mNewList = newList;
        }


        @Override
        public int getOldListSize() {
            return mOldList.size();
        }

        @Override
        public int getNewListSize() {
            return mNewList.size();
        }

        @Override
        public boolean areItemsTheSame(int iOld, int iNew) {
            String oldPkg = mOldList.get(iOld).getPackageName();
            String newPkg = mNewList.get(iNew).getPackageName();
            return oldPkg.equals(newPkg);
        }

        @Override
        public boolean areContentsTheSame(int iOld, int iNew) {
            return mOldList.get(iOld).equals(mNewList.get(iNew));
        }
    }
}
