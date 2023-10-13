package com.vinz.playerpedia.activity

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.navigation.findNavController
import androidx.recyclerview.widget.GridLayoutManager
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.vinz.playerpedia.R
import com.vinz.playerpedia.adapter.PlayerAdapter
import com.vinz.playerpedia.data.PlayerDummyData
import com.vinz.playerpedia.data.PlayerWordStart
import com.vinz.playerpedia.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding : ActivityMainBinding

    private lateinit var playerAdapter: PlayerAdapter
    private lateinit var recyclerView: RecyclerView

    private var isLinearLayoutManager = true

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        recyclerView = binding.rvWords
        recyclerView.setHasFixedSize(true)
        recyclerView.layoutManager = LinearLayoutManager(this)
        playerAdapter = PlayerAdapter(PlayerDummyData.playerDummy)
        recyclerView.adapter = playerAdapter

        binding.btnChangeView.setOnClickListener {
            isLinearLayoutManager = !isLinearLayoutManager
            setLayout()
        }

        playerAdapter.setOnItemClickCallback(object : PlayerAdapter.OnItemClickCallback {
            override fun onItemClicked(data: PlayerWordStart) {
                // Tambahkan kode untuk membuka detail makanan
                showSelectedWord(data)
            }
        })
    }

    private fun setLayout() {
        if (isLinearLayoutManager) {
            recyclerView.layoutManager = LinearLayoutManager(this)
            binding.btnChangeView.setImageResource(R.drawable.ic_grid)
        } else {
            recyclerView.layoutManager = GridLayoutManager(this, 2)
            binding.btnChangeView.setImageResource(R.drawable.ic_list)
        }
    }

    private fun showSelectedWord(player: PlayerWordStart) {
        val intent = Intent(this, PlayerDataActivity::class.java)
        val playerLetterToFind = player.playerLetter
        intent.putExtra("playerData", playerLetterToFind)
        startActivity(intent)
    }

}