package com.vinz.playerpedia.data

import android.os.Parcelable

data class PlayerWordStart(
    val playerLetter: String,
    val playerWordList: List<PlayerWordData>
) : Parcelable {
    constructor(parcel: android.os.Parcel) : this(
        parcel.readString()!!,
        parcel.createTypedArrayList(PlayerWordData)!!
    ) {
    }

    override fun writeToParcel(parcel: android.os.Parcel, flags: Int) {
        parcel.writeString(playerLetter)
        parcel.writeTypedList(playerWordList)
    }

    override fun describeContents(): Int {
        return 0
    }

    companion object CREATOR : Parcelable.Creator<PlayerWordStart> {
        override fun createFromParcel(parcel: android.os.Parcel): PlayerWordStart {
            return PlayerWordStart(parcel)
        }

        override fun newArray(size: Int): Array<PlayerWordStart?> {
            return arrayOfNulls(size)
        }
    }
}
