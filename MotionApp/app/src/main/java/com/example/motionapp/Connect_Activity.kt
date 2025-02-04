package com.example.motionapp

import android.content.Intent
import android.os.Build
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import android.provider.Settings
import android .system.Os.socket
import android.widget.Button
import androidx.core.content.ContextCompat


class Connect_Activity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_connect)
        //val ConnectService = Intent(this, Client::class.java)
        //startService(ConnectService)123


        /*
        if (Build.VERSION.SDK_INT >= 30) {
            if (!Environment.isExternalStorageManager()) {
                val getpermission = Intent()
                getpermission.action = Settings.ACTION_MANAGE_ALL_FILES_ACCESS_PERMISSION
                startActivity(getpermission)
            }
        }*/


        val ConnectBtn = findViewById<Button>(R.id.ContinueBtn)
        ConnectBtn.setOnClickListener{

            val ConnectIntent = Intent(this, MainActivity::class.java)
            startActivity(ConnectIntent)
        }
        window.statusBarColor = ContextCompat.getColor(this,R.color.black)
    }
}