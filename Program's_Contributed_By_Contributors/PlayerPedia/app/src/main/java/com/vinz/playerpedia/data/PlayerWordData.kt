package com.vinz.playerpedia.data

import android.os.Parcel
import android.os.Parcelable

data class PlayerWordData(
    val playerWordName: String,
    val playerWordClub: String,
    val playerWordPosition: String,
    val playerWordNationality: String,
    val playerWordDescription: String,
    val playerWordImageResourceId: String,
) : Parcelable {
    constructor(parcel: Parcel) : this(
        parcel.readString()!!,
        parcel.readString()!!,
        parcel.readString()!!,
        parcel.readString()!!,
        parcel.readString()!!,
        parcel.readString()!!
    )

    override fun writeToParcel(parcel: Parcel, flags: Int) {
        parcel.writeString(playerWordName)
        parcel.writeString(playerWordClub)
        parcel.writeString(playerWordPosition)
        parcel.writeString(playerWordNationality)
        parcel.writeString(playerWordDescription)
        parcel.writeString(playerWordImageResourceId)
    }

    override fun describeContents(): Int {
        return 0
    }

    companion object CREATOR : Parcelable.Creator<PlayerWordData> {
        override fun createFromParcel(parcel: Parcel): PlayerWordData {
            return PlayerWordData(parcel)
        }

        override fun newArray(size: Int): Array<PlayerWordData?> {
            return arrayOfNulls(size)
        }
    }
}