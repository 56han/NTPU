package com.example.motionapp

import android.animation.ObjectAnimator
import android.annotation.SuppressLint
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.CountDownTimer
import android.view.View
import android.widget.ProgressBar
import android.widget.TextView
import androidx.core.content.ContextCompat
import kotlin.concurrent.thread

class Match_Activity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {

        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_match)

        val Transparent = findViewById<View>(R.id.BlackView)
        var CountTimeView = findViewById<TextView>(R.id.CountDown)
        //var CountTime = CountTimeView.text.toString().toInt()

        object : CountDownTimer(5000, 100) {

            override fun onFinish() {
                CountTimeView.setVisibility(TextView.INVISIBLE)
                Transparent.setVisibility(View.INVISIBLE)
            }

            override fun onTick(millisUntilFinished: Long) {
                    CountTimeView.text = "${(millisUntilFinished/1000)+1}"
            }
        }.start()

        window.statusBarColor = ContextCompat.getColor(this,R.color.black)
    }

}