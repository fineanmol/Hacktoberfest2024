package com.vinz.playerpedia.fragment

import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.fragment.app.Fragment
import com.bumptech.glide.Glide
import com.vinz.playerpedia.data.PlayerWordData
import com.vinz.playerpedia.databinding.FragmentDetailBinding

class DetailFragment : Fragment() {

    private var _binding: FragmentDetailBinding? = null
    private val binding get() = _binding!!

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        // Inflate the layout for this fragment
        _binding = FragmentDetailBinding.inflate(inflater, container, false)
        return binding.root
    }

    @Suppress("DEPRECATION")
    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        val player = arguments?.getParcelable<PlayerWordData>("player") as PlayerWordData

        Glide.with(requireContext())
            .load(player.playerWordImageResourceId)
            .into(binding.ivPlayer)

        binding.tvPlayerName.text = player.playerWordName
        binding.tvPlayerClub.text = player.playerWordClub
        binding.tvPlayerPosition.text = player.playerWordPosition
        binding.tvPlayerNationally.text = player.playerWordNationality
        binding.tvPlayerDescription.text = player.playerWordDescription

        binding.btnBack.setOnClickListener {
            requireActivity().onBackPressed()
        }

        binding.btnSearchGoogle.setOnClickListener {
            val playerName = player.playerWordName

            // Buat URL pencarian Google dengan data player.playerWordName
            val searchQuery = "https://www.google.com/search?q=${playerName}"

            // Buat intent untuk membuka browser dengan URL pencarian Google
            val intent = Intent(Intent.ACTION_VIEW, Uri.parse(searchQuery))

            // Periksa apakah ada aplikasi browser yang dapat menangani intent ini
            if (intent.resolveActivity(requireContext().packageManager) != null) {
                startActivity(intent)
            } else {
                // Jika tidak ada aplikasi browser yang dapat menangani intent ini
                // Tampilkan pesan kesalahan atau lakukan tindakan lain sesuai kebutuhan Anda
                // Misalnya, tampilkan pesan toast bahwa tidak ada browser yang tersedia.
                Toast.makeText(requireContext(), "Tidak ada browser yang tersedia.", Toast.LENGTH_SHORT).show()
            }
        }
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }

}