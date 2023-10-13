package com.vinz.playerpedia.activity

import android.content.Intent
import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import androidx.navigation.findNavController
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.vinz.playerpedia.R
import com.vinz.playerpedia.adapter.PlayerDataAdapter
import com.vinz.playerpedia.data.PlayerDummyData
import com.vinz.playerpedia.data.PlayerWordData
import com.vinz.playerpedia.databinding.ActivityPlayerDataBinding

class PlayerDataActivity : AppCompatActivity() {
    private lateinit var binding: ActivityPlayerDataBinding

    private lateinit var playerDataAdapter: PlayerDataAdapter
    private lateinit var recyclerView: RecyclerView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityPlayerDataBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val playerLetter = intent.getStringExtra("playerData")

        val filteredPlayers = PlayerDummyData.playerDummy.filter { playerWordStart ->
            playerWordStart.playerLetter == playerLetter
        }

        recyclerView = binding.rvPlayerName
        recyclerView.setHasFixedSize(true)
        recyclerView.layoutManager = LinearLayoutManager(this)
        playerDataAdapter = PlayerDataAdapter(filteredPlayers[0].playerWordList)
        recyclerView.adapter = playerDataAdapter

        playerDataAdapter.setOnItemClickCallback(object : PlayerDataAdapter.OnItemClickCallback {
            override fun onItemClicked(data: PlayerWordData) {
                // Tambahkan kode untuk membuka detail makanan
                showSelectedPlayer(data)
            }
        })

        binding.btnBack.setOnClickListener {
            onBackPressed()
        }
    }

    private fun showSelectedPlayer(player: PlayerWordData) {
        val intent = Intent(this, DetailActivity::class.java)
        intent.putExtra("player", player)
        startActivity(intent)
    }
}