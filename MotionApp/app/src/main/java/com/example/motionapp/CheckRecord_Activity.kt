package com.example.motionapp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import androidx.core.content.ContextCompat

class CheckRecord_Activity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_check_record)

        val RecordName : TextView = findViewById(R.id.RecordVideoName)

        val bundle:Bundle?=intent.extras
        val Name = bundle!!.getString("Name")

        RecordName.text = Name

        window.statusBarColor = ContextCompat.getColor(this,R.color.black)
    }
}