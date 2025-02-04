package com.example.motionapp

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.Toast
import androidx.core.content.ContextCompat
import com.google.android.material.textfield.TextInputEditText

class Sign_Activity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_sign)

        var  AccountText = findViewById<TextInputEditText>(R.id.AccountInputEditText)
        var  PasswordText = findViewById<TextInputEditText>(R.id.PasswordInputEditText)
        val HomeActBtn = findViewById<Button>(R.id.GotoSignBtn)

        HomeActBtn.setOnClickListener{
            var Account = AccountText.text.toString()
            var Password = PasswordText.text.toString()
            if(Account != "" && Password != "") {
                Toast.makeText(this@Sign_Activity,"Your account:$Account signed in successfully.", Toast.LENGTH_SHORT).show()
                val HomeIntent = Intent(this, Home_Activity::class.java)
                startActivity(HomeIntent)
            }
            else{
                Toast.makeText(this@Sign_Activity,"Check if your entry is complete.", Toast.LENGTH_SHORT).show()
            }
        }
        window.statusBarColor = ContextCompat.getColor(this,R.color.black)
    }
}