package com.example.motionapp

import android.annotation.SuppressLint
import android.app.Activity
import android.app.AlertDialog
import android.content.Context
import android.content.Intent
import android.database.Cursor
import android.graphics.Bitmap
import android.graphics.Color
import android.media.MediaMetadataRetriever
import android.net.Uri
import android.os.Build
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import android.provider.DocumentsContract
import android.provider.MediaStore
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.widget.Button
import android.widget.ImageView
import android.widget.ProgressBar
import android.widget.Toast
import androidx.core.content.ContextCompat
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView


class Upload_Activity : AppCompatActivity() {
    private val SELECT_VIDEOS_KITKAT = 1
    private var selectedVideo: String? = null

    private lateinit var UploadRecyclerView : RecyclerView
    private lateinit var UploadArrayList : ArrayList<Upload_List>
    lateinit var UploadImageId : Array<Int>
    lateinit var UploadHeading : Array<String>
    //var UploadImageId = ArrayList<Int>()
    //var UploadHeading = ArrayList<String>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_upload)

        //get values from name_activity
        //val bundle:Bundle?=intent.extras
        //val VideoName = bundle!!.getString("VideoName")
        //val Address = bundle!!.getString("Address")

        /*Go Button*/
        val MatchActBtn = findViewById<Button>(R.id.GoMatchBtn)
        MatchActBtn.setOnClickListener {
            val MatchIntent = Intent(this, Loading_Activity::class.java)
            startActivity(MatchIntent)
        }

        /*Plus Button*/
        val PlusBtn = findViewById<Button>(R.id.UploadVideoBtn)
        PlusBtn.setOnClickListener {
            val Uplaodintent = Intent(Intent.ACTION_OPEN_DOCUMENT)
            Uplaodintent.addCategory(Intent.CATEGORY_OPENABLE)
            Uplaodintent.putExtra(Intent.EXTRA_ALLOW_MULTIPLE, true)
            Uplaodintent.type = "video/mp4"
            startActivityForResult(Uplaodintent, SELECT_VIDEOS_KITKAT)
        }

        /*RecyclerView*/

        /*
        lateinit var Image : ImageView
        val retriever = MediaMetadataRetriever()
        retriever.setDataSource(Address)
        Image.setImageBitmap(retriever.getFrameAtTime(1000000, MediaMetadataRetriever.OPTION_CLOSEST))

        UploadImageId.add(R.drawable.fitness01)
        UploadHeading.add(VideoName.toString())*/


        UploadImageId = arrayOf(
            R.drawable.fitness01,
            R.drawable.fitness02,
            R.drawable.fitness03,
            R.drawable.fitness04,
            R.drawable.fitness05,
            R.drawable.fitness06,
            R.drawable.fitness07,
            R.drawable.fitness08,
            R.drawable.fitness09
        )

        UploadHeading = arrayOf(
            "Fat Burning Cardio Workout - 37 Minute Fitness Blender Cardio Workout at Home",
            "This is fitness02 video.",
            "This is fitness03 video.",
            "This is fitness03 video.",
            "This is fitness04 video.",
            "This is fitness05 video.",
            "This is fitness06 video.",
            "This is fitness07 video.",
            "This is fitness08 video.",
            "This is fitness09 video."
        )


        UploadRecyclerView = findViewById(R.id.UploadRecyclerView)
        UploadRecyclerView.layoutManager = LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, false)
        UploadRecyclerView.setHasFixedSize(true)

        UploadArrayList = arrayListOf<Upload_List>()
        GetUserUploadData()

        window.statusBarColor = ContextCompat.getColor(this,R.color.black)
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)
        if (resultCode == RESULT_OK) {
            selectedVideo = data?.let { getSelectedVideos(requestCode, it) }

            //Go to Name_Activity
            val NameIntent = Intent(this, Name_Activity::class.java)
            NameIntent.putExtra("Address",selectedVideo)
            startActivity(NameIntent)

        }
    }

    private fun getSelectedVideos(requestCode: Int, data: Intent): String? {
        val videoURI: Uri? = data.data
        val filePath = getPath(this, videoURI)

        //val testPath : String? = videoURI?.path   //test
        //println("testPath"+testPath) //test
        println("Uri"+videoURI.toString())
        println("filePath"+ filePath )
        return filePath
    }

    @SuppressLint("NewApi")
    fun getPath(context: Context, uri: Uri?): String? {
        val docId = DocumentsContract.getDocumentId(uri)
        val split = docId.split(":").toTypedArray()
        val type = split[0]
        if ("primary".equals(type, ignoreCase = true)) {
            return Environment.getExternalStorageDirectory().toString() + "/" + split[1]
        }
        return null
    }

    /*recycler view*/
    private fun GetUserUploadData() {
        for(i in UploadImageId.indices){
            val upload = Upload_List(UploadImageId[i],UploadHeading[i])
            UploadArrayList.add(upload)
        }

        var adapter = UploadMyAdapter(UploadArrayList)
        UploadRecyclerView.adapter = adapter

        adapter.setonItemListener(object :  UploadMyAdapter.onUploadItemListener{
            override fun onItemClick(position: Int) {
                Toast.makeText(this@Upload_Activity,"You clicked on item no. $position ", Toast.LENGTH_SHORT).show()
            }
        })
    }


}