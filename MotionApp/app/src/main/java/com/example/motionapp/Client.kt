package com.example.motionapp

import android.app.Service
import android.content.ContentValues.TAG
import android.content.Intent
import android.net.InetAddresses
import android.nfc.Tag
import android.os.IBinder
import android.util.Log
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers.IO
import kotlinx.coroutines.launch
import java.net.Inet4Address
import java.net.Socket
import kotlin.coroutines.CoroutineContext
import java.util.*
import java.io.OutputStream
import java.io.PrintWriter
import java .nio.charset.Charset
import java.io.BufferedWriter
import java.io.OutputStreamWriter

class Client : Service() {
    val address="10.141.50.13"
    //val address="192.168.50.227"
    val port=8888
    val ClientSocket:Socket= Socket(address,port)
    override fun onBind(intent: Intent): IBinder {
        TODO("Return the communication channel to the service.")
    }

    override fun onStartCommand(intent: Intent?, flags: Int, startId: Int): Int {
        ConnectToServer()
        //return super.onStartCommand(intent, flags, startId)
        return START_STICKY
    }
    fun ConnectToServer(){
        val out = PrintWriter(
            BufferedWriter(
                OutputStreamWriter(ClientSocket.getOutputStream())
            ),
            true
        )
        val read=Scanner(System.`in`)
        println("Send message：")
        val message=read.nextLine()
        out.println(message)
        //out.println("Hello")
        while(read!=null){
            println("Send message：")
            val message=read.nextLine()
            out.println(message)
        }
    }
}
    /*val address="10.141.50.13"
    val port=8888

    //private val Connection:Socket= Socket(address,port)
    //private var connected:Boolean=true
    //private val reader:Scanner=Scanner(Connection.getInputStream())
    //private val writer:OutputStream=Connection.getOutputStream()
    override fun onBind(intent: Intent): IBinder {
        TODO("Return the communication channel to the service.")
    }

    override fun onStartCommand(intent: Intent?, flags: Int, startId: Int): Int {
        ConnectToServer()
        //return super.onStartCommand(intent, flags, startId)
        return START_STICKY
    }
    fun ConnectToServer(){
        val Connection:Socket= Socket(address,port)
        //var connected:Boolean=true
        val scanner=Scanner(Connection.getInputStream())
        val printWriter=PrintWriter(Connection.getOutputStream())
        val reader="Successful"
        //while(scanner.hasNextLine()){
         //   Log.d(TAG,"${ scanner.nextLine()}")
        //}
    }*/