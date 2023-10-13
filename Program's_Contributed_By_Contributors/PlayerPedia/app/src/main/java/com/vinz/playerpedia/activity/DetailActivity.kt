package com.vinz.playerpedia.activity

import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.bumptech.glide.Glide
import com.vinz.playerpedia.data.PlayerWordData
import com.vinz.playerpedia.databinding.ActivityDetailBinding

class DetailActivity : AppCompatActivity() {

    private lateinit var binding: ActivityDetailBinding

    @Suppress("DEPRECATION")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityDetailBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val player = intent.getParcelableExtra<PlayerWordData>("player") as PlayerWordData

        Glide.with(this)
            .load(player.playerWordImageResourceId)
            .into(binding.ivPlayer)

        binding.tvPlayerName.text = player.playerWordName
        binding.tvPlayerClub.text = player.playerWordClub
        binding.tvPlayerPosition.text = player.playerWordPosition
        binding.tvPlayerNationally.text = player.playerWordNationality
        binding.tvPlayerDescription.text = player.playerWordDescription

        binding.btnBack.setOnClickListener {
            onBackPressed()
        }

        binding.btnSearchGoogle.setOnClickListener {
            val playerName = player.playerWordName

            // Buat URL pencarian Google dengan data player.playerWordName
            val searchQuery = "https://www.google.com/search?q=${playerName}"

            // Buat intent untuk membuka browser dengan URL pencarian Google
            val intent = Intent(Intent.ACTION_VIEW, Uri.parse(searchQuery))

            // Periksa apakah ada aplikasi browser yang dapat menangani intent ini
            if (intent.resolveActivity(this.packageManager) != null) {
                startActivity(intent)
            } else {
                // Jika tidak ada aplikasi browser yang dapat menangani intent ini
                // Tampilkan pesan kesalahan atau lakukan tindakan lain sesuai kebutuhan Anda
                // Misalnya, tampilkan pesan toast bahwa tidak ada browser yang tersedia.
                Toast.makeText(this, "Tidak ada browser yang tersedia.", Toast.LENGTH_SHORT).show()
            }
        }
    }
}