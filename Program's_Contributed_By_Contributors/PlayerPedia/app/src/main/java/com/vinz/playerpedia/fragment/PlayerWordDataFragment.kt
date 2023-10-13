package com.vinz.playerpedia.fragment

import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.navigation.findNavController
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.vinz.playerpedia.R
import com.vinz.playerpedia.adapter.PlayerDataAdapter
import com.vinz.playerpedia.data.PlayerDummyData.playerDummy
import com.vinz.playerpedia.data.PlayerWordData
import com.vinz.playerpedia.databinding.FragmentPlayerWordDataBinding

class PlayerWordDataFragment : Fragment() {

    private var _binding: FragmentPlayerWordDataBinding? = null
    private val binding get() = _binding!!

    private lateinit var playerDataAdapter: PlayerDataAdapter
    private lateinit var recyclerView: RecyclerView


    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        // Inflate the layout for this fragment
        _binding = FragmentPlayerWordDataBinding.inflate(inflater, container, false)
        return binding.root
    }

    @Suppress("DEPRECATION")
    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        val playerLetter = arguments?.getString("playerData")
        Log.d("playerLetter", playerLetter.toString())

        val filteredPlayers = playerDummy.filter { playerWordStart ->
            playerWordStart.playerLetter == playerLetter
        }

        recyclerView = binding.rvPlayerName
        recyclerView.setHasFixedSize(true)
        recyclerView.layoutManager = LinearLayoutManager(requireContext())
        playerDataAdapter = PlayerDataAdapter(filteredPlayers[0].playerWordList)
        recyclerView.adapter = playerDataAdapter

        playerDataAdapter.setOnItemClickCallback(object : PlayerDataAdapter.OnItemClickCallback {
            override fun onItemClicked(data: PlayerWordData) {
                // Tambahkan kode untuk membuka detail makanan
                showSelectedPlayer(data)
            }
        })

        binding.btnBack.setOnClickListener {
            requireActivity().onBackPressed()
        }

    }

    private fun showSelectedPlayer(player: PlayerWordData) {
        val mBundle = Bundle()
        mBundle.putParcelable("player", player)
        view?.findNavController()?.navigate(R.id.action_playerWordDataFragment_to_detailFragment, mBundle)
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }

}