package com.vinz.playerpedia.adapter

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import com.google.android.material.textview.MaterialTextView
import com.vinz.playerpedia.R
import com.vinz.playerpedia.data.PlayerWordData

class PlayerDataAdapter(
    private val playerList: List<PlayerWordData>
) :
    RecyclerView.Adapter<PlayerDataAdapter.ViewHolder>() {

    private lateinit var onItemClickCallback: OnItemClickCallback

    fun setOnItemClickCallback(onItemClickCallback: OnItemClickCallback) {
        this.onItemClickCallback = onItemClickCallback
    }

    interface OnItemClickCallback {
        fun onItemClicked(data: PlayerWordData)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.item_player, parent, false)
        return ViewHolder(view)
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        val player = playerList[position]
        holder.word.text = player.playerWordName
        holder.itemView.setOnClickListener {
            onItemClickCallback.onItemClicked(playerList[position])
        }
    }

    override fun getItemCount(): Int = playerList.size

    class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {

        val word: MaterialTextView = view.findViewById(R.id.word_title)

    }
}