/*
 * Copyright (C) 2021-2022 Miku UI
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

package com.android.launcher3.util

import android.content.Context
import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.hardware.SensorManager
import kotlin.math.sqrt

class ShakeUtils(context: Context) : SensorEventListener {
    private val mSensorManager = context.getSystemService(Context.SENSOR_SERVICE) as SensorManager
    private val sensor = mSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER)
    private var mOnShakeListeners = ArrayList<OnShakeListener>()

    // Last time we triggered shake
    private var mLastShakeTime = 0L
    private var mLastUpdateTime = 0L

    // Last position we triggered shake
    private var mLastX = 0f
    private var mLastY = 0f
    private var mLastZ = 0f

    interface OnShakeListener {
        fun onShake(speed: Double)
    }

    companion object {
        //  Minimal time interval of position changes
        private const val MIN_SHAKE_INTERVAL = 1024

        // Minimal shake speed
        private const val SPEED_SHAKE_MILLISECONDS = 400

        // Minimal time interval between two shakes
        private const val SHAKE_INTERVAL_MILLISECOND = 55
    }

    private var registered = false
        set(value) {
            if (value != field) {
                field = value
                if (value) {
                    mSensorManager.registerListener(this, sensor, SensorManager.SENSOR_DELAY_UI)
                } else {
                    mSensorManager.unregisterListener(this)
                }
            }
        }

    fun registerShakeListener(listener: OnShakeListener) {
        mOnShakeListeners.add(listener)
        registered = mOnShakeListeners.size > 0
    }

    fun unregisterShakeListener(listener: OnShakeListener) {
        mOnShakeListeners.remove(listener)
        registered = mOnShakeListeners.size > 0
    }

    override fun onSensorChanged(event: SensorEvent) {
        val curUpdateTime = System.currentTimeMillis()
        // Times between two shakes
        val timeInterval = curUpdateTime - mLastUpdateTime
        if (timeInterval < SHAKE_INTERVAL_MILLISECOND) {
            return
        }
        if (event.values.size < 3) {
            return
        }
        mLastUpdateTime = curUpdateTime
        val x = event.values[0]
        val y = event.values[1]
        val z = event.values[2]
        val deltaX = x - mLastX
        val deltaY = y - mLastY
        val deltaZ = z - mLastZ
        mLastX = x
        mLastY = y
        mLastZ = z
        val speed =
            sqrt((deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ).toDouble()) * 1000.0 / timeInterval
        if (speed >= SPEED_SHAKE_MILLISECONDS) {
            startShake(speed)
        }
    }

    private fun startShake(speed: Double) {
        val curShakeTime = System.currentTimeMillis()
        if (curShakeTime - mLastShakeTime < MIN_SHAKE_INTERVAL) {
            return
        }
        mLastShakeTime = curShakeTime
        mOnShakeListeners.forEach { it.onShake(speed) }
    }

    override fun onAccuracyChanged(sensor: Sensor, accuracy: Int) {}
}
