package com.example.motionapp

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.Toast
import androidx.core.content.ContextCompat
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class Record_Activity : AppCompatActivity() {
    private lateinit var FitnessRecyclerView : RecyclerView
    private lateinit var FitnessArrayList : ArrayList<Record_List>
    lateinit var imageId : Array<Int>
    lateinit var heading : Array<String>
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_record)
        imageId = arrayOf(
            R.drawable.fitness01,
            R.drawable.fitness02,
            R.drawable.fitness03,
            R.drawable.fitness04,
            R.drawable.fitness05,
            R.drawable.fitness06,
            R.drawable.fitness07,
            R.drawable.fitness08,
            R.drawable.fitness09
        )

        heading = arrayOf(
            "Fat Burning Cardio Workout - 37 Minute Fitness Blender Cardio Workout at Home",
            "This is fitness02 video.",
            "This is fitness03 video.",
            "This is fitness03 video.",
            "This is fitness04 video.",
            "This is fitness05 video.",
            "This is fitness06 video.",
            "This is fitness07 video.",
            "This is fitness08 video.",
            "This is fitness09 video."
        )
        FitnessRecyclerView = findViewById(R.id.RecordRecyclerView)
        FitnessRecyclerView.layoutManager = LinearLayoutManager(this)
        FitnessRecyclerView.setHasFixedSize(true)

        FitnessArrayList = arrayListOf<Record_List>()
        GetUserData()

        window.statusBarColor = ContextCompat.getColor(this,R.color.black)
    }
    private fun GetUserData() {
        for(i in imageId.indices){
            val fitness = Record_List(imageId[i],heading[i])
            FitnessArrayList.add(fitness)
        }

        var adapter = RecordMyAdapter(FitnessArrayList)
        FitnessRecyclerView.adapter = adapter

        adapter.setonItemListener(object :  RecordMyAdapter.onItemListener {
            override fun onItemClick(position: Int) {
                Toast.makeText(this@Record_Activity,"You clicked on item no. $position ", Toast.LENGTH_SHORT).show()

                val CheckRecordIntent = Intent(this@Record_Activity, CheckRecord_Activity::class.java)
                CheckRecordIntent.putExtra("Name",FitnessArrayList[position].RecordHeading_ID)
                startActivity(CheckRecordIntent)
            }
        })
    }
}