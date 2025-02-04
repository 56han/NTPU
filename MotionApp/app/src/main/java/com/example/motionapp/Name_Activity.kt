package com.example.motionapp

import android.content.Intent
import android.media.Image
import android.media.MediaMetadataRetriever
import android.os.Bundle
import android.widget.Button
import android.widget.ImageView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.ContextCompat
import com.google.android.material.textfield.TextInputEditText


class Name_Activity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_name)

        //get values from upload_activity
        val bundle:Bundle?=intent.extras
        val Address = bundle!!.getString("Address")

        //get 1st frame screenshot
        val Image = findViewById<ImageView>(R.id.ImageView)
        val retriever = MediaMetadataRetriever()
        retriever.setDataSource(Address)
        Image.setImageBitmap(retriever.getFrameAtTime(1000000, MediaMetadataRetriever.OPTION_CLOSEST))

        val UploadBtn = findViewById<Button>(R.id.GotoUploadBtn)
        var NameText = findViewById<TextInputEditText>(R.id.VideoNameInputEditText)
        UploadBtn.setOnClickListener{
            var Name = NameText.text.toString()
            if(Name != "") {
                Toast.makeText(this@Name_Activity,"$Name has already uploaded successfully!", Toast.LENGTH_SHORT).show()
                val SuccessUploadIntent = Intent(this, Upload_Activity::class.java)
                SuccessUploadIntent.putExtra("VideoName",Name)
                SuccessUploadIntent.putExtra("Address",Address)
                startActivity(SuccessUploadIntent)
            }
            else{
                Toast.makeText(this@Name_Activity,"Please enter the name.", Toast.LENGTH_SHORT).show()
            }
        }
        window.statusBarColor = ContextCompat.getColor(this,R.color.black)
    }
}