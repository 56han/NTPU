package com.example.motionapp

import android.content.Context
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import androidx.core.content.ContextCompat

class Home_Activity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_home)

        val UploadActBtn = findViewById<Button>(R.id.StartBtn)
        UploadActBtn.setOnClickListener{
            val UploadIntent = Intent(this, Upload_Activity::class.java)
            startActivity(UploadIntent)
        }
        val RecordActBtn = findViewById<Button>(R.id.RecordBtn)
        RecordActBtn.setOnClickListener{
            val RecordIntent = Intent(this, Record_Activity::class.java)
            startActivity(RecordIntent)
        }
        window.statusBarColor = ContextCompat.getColor(this,R.color.black)
    }
}