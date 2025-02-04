package com.example.motionapp

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.Toast
import androidx.core.content.ContextCompat

class FinalScore_Activity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_final_score)


        val HomeBtn = findViewById<Button>(R.id.BackHomeBtn)
        HomeBtn.setOnClickListener{
            val HomeIntent = Intent(this, Home_Activity::class.java)
            startActivity(HomeIntent)
        }

        val SaveRecordBtn = findViewById<Button>(R.id.SaveBtn)
        SaveRecordBtn.setOnClickListener{
            val SaveIntent = Intent(this, Home_Activity::class.java)  //save the record and back home
            Toast.makeText(this@FinalScore_Activity,"Save successfully!", Toast.LENGTH_SHORT).show()
            startActivity(SaveIntent)
        }

        window.statusBarColor = ContextCompat.getColor(this,R.color.black)
    }
}