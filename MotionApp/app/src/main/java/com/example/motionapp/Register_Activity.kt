package com.example.motionapp

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.Toast
import androidx.core.content.ContextCompat
import com.google.android.material.textfield.TextInputEditText

class Register_Activity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_register)

        var  AccountText = findViewById<TextInputEditText>(R.id.AccountInputEditText)
        var  PasswordText = findViewById<TextInputEditText>(R.id.PasswordInputEditText)
        var  ConfirmPasswordText = findViewById<TextInputEditText>(R.id.ConfirmPasswordInputEditText)
        val HomeActBtn = findViewById<Button>(R.id.GotoRegisterBtn)

        HomeActBtn.setOnClickListener{
            var Account = AccountText.text.toString()
            var Password = PasswordText.text.toString()
            var ConfirmPassword = ConfirmPasswordText.text.toString()

            if(Account != "" && Password != "" && ConfirmPassword != "") {
                if(Password == ConfirmPassword){
                    Toast.makeText(this@Register_Activity,"You account:$Account registered successfully.", Toast.LENGTH_SHORT).show()
                    val HomeIntent = Intent(this, Home_Activity::class.java)
                    startActivity(HomeIntent)
                }
                else{
                    Toast.makeText(this@Register_Activity,"You entered the wrong confirmed-password.", Toast.LENGTH_SHORT).show()
                }
            }
            else{
                Toast.makeText(this@Register_Activity,"Check if your entry is complete.", Toast.LENGTH_SHORT).show()
            }

        }
        window.statusBarColor = ContextCompat.getColor(this,R.color.black)
    }
}