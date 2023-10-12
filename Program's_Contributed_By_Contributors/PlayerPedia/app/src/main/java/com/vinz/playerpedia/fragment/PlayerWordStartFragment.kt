package com.vinz.playerpedia.fragment

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.navigation.findNavController
import androidx.recyclerview.widget.GridLayoutManager
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.vinz.playerpedia.R
import com.vinz.playerpedia.adapter.PlayerAdapter
import com.vinz.playerpedia.data.PlayerDummyData
import com.vinz.playerpedia.data.PlayerWordStart
import com.vinz.playerpedia.databinding.FragmentPlayerWordStartBinding

class PlayerWordStartFragment : Fragment() {

    private var _binding : FragmentPlayerWordStartBinding? = null
    private val binding get() = _binding!!

    private lateinit var playerAdapter: PlayerAdapter
    private lateinit var recyclerView: RecyclerView

    private var isLinearLayoutManager = true

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        // Inflate the layout for this fragment
        _binding  = FragmentPlayerWordStartBinding.inflate(inflater, container, false)
        return binding.root
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        recyclerView = binding.rvWords
        recyclerView.setHasFixedSize(true)
        recyclerView.layoutManager = LinearLayoutManager(requireContext())
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
            recyclerView.layoutManager = LinearLayoutManager(requireContext())
            binding.btnChangeView.setImageResource(R.drawable.ic_grid)
        } else {
            recyclerView.layoutManager = GridLayoutManager(requireContext(), 2)
            binding.btnChangeView.setImageResource(R.drawable.ic_list)
        }
    }

    private fun showSelectedWord(player: PlayerWordStart) {
        val mBundle = Bundle()
        val playerLetterToFind = player.playerLetter
        mBundle.putString("playerData", playerLetterToFind)
        view?.findNavController()?.navigate(R.id.action_playerWordStartFragment_to_playerWordDataFragment, mBundle)
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }

}