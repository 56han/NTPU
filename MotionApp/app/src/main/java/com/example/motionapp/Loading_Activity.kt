package com.example.motionapp

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.os.Looper
import android.view.WindowManager
import android.widget.ProgressBar
import android.widget.TextView
import androidx.core.content.ContextCompat
import kotlin.random.Random

class Loading_Activity : AppCompatActivity() {

    var ProgressStatus = 0
    var handler = Handler()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_loading)

        val ProgressBar = findViewById<ProgressBar>(R.id.ProgressBar_ID)
        val PercentageText = findViewById<TextView>(R.id.ProgressTextView)
        ProgressBar.progress = 0
        ProgressStatus = 0

        val FilesToDownload = 100  //modify depend on file upload time
        ProgressBar.max = FilesToDownload

        Thread(Runnable {
            while (ProgressStatus < FilesToDownload){
                ProgressStatus +=1
                Thread.sleep(50)
                handler.post {
                    ProgressBar.progress = ProgressStatus
                    var Percentage = ((ProgressStatus.toDouble() / FilesToDownload) * 100).toInt()
                    PercentageText.text = "$Percentage %"
                }
            }
            val LoadingIntent = Intent(this, Match_Activity::class.java)
            startActivity(LoadingIntent)
        }).start()

        window.statusBarColor = ContextCompat.getColor(this,R.color.black)
    }
}