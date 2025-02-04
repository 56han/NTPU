package com.example.motionapp

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import androidx.activity.result.contract.ActivityResultContracts
import androidx.core.content.ContextCompat

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val SignActBtn = findViewById<Button>(R.id.SignBtn)
        SignActBtn.setOnClickListener{
            val SignIntent = Intent(this, Sign_Activity::class.java)
            startActivity(SignIntent)
        }
        val RegisterActBtn = findViewById<Button>(R.id.RegisterBtn)
        RegisterActBtn.setOnClickListener{
            val RegisterIntent = Intent(this, Register_Activity::class.java)
            startActivity(RegisterIntent)
        }
        window.statusBarColor = ContextCompat.getColor(this,R.color.black)
    }
}