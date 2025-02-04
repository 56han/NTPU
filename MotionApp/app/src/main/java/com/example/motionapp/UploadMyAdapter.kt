package com.example.motionapp

import android.graphics.Color
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.core.content.ContextCompat
import androidx.recyclerview.widget.RecyclerView
import com.google.android.material.imageview.ShapeableImageView


class UploadMyAdapter (private val UploadVideoList : ArrayList<Upload_List>): RecyclerView.Adapter<UploadMyAdapter.MyVideoHolder>(){
    private lateinit var nListener : onUploadItemListener
    interface onUploadItemListener{
        fun onItemClick(position : Int)
    }

    fun setonItemListener(listener: onUploadItemListener){
        nListener = listener
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): MyVideoHolder {
        val itemView = LayoutInflater.from(parent.context).inflate(R.layout.video_list_item,parent,false)
        return MyVideoHolder(itemView,nListener)
    }



    override fun onBindViewHolder(holder: MyVideoHolder, position: Int) {
        val currentItem = UploadVideoList[position]
        holder.UploadVideoImage.setImageResource(currentItem.UploadVideoTitleImage)
        holder.UploadVideoHeading.text = currentItem.UploadVideoHeading_ID


        //not yet
        holder.itemView.setOnClickListener {
            it.setBackgroundResource(R.color.selected)
        }

        /*
        holder.itemView.setOnClickListener {
            //it.setBackgroundResource(R.color.selected)

            for(index in 0 until UploadVideoList.size) {
                if(UploadVideoList.get(holder.getAdapterPosition()) == currentItem) {
                    it.setBackgroundResource(R.color.selected)
                }
                else{
                    UploadVideoList.get(index).setBackgroundResource(R.color.white)
                }
            }

        }*/

    }


    /*
    override fun onBindViewHolder(holder: MyVideoHolder, position: Int) {

        var index = -1
        val currentItem = UploadVideoList[position]
        holder.UploadVideoImage.setImageResource(currentItem.UploadVideoTitleImage)
        holder.UploadVideoHeading.text = currentItem.UploadVideoHeading_ID
        holder.itemView.setOnClickListener(View.OnClickListener {
            index = position
            notifyDataSetChanged()
        })
        if (index === position) {
            holder.itemView.setBackgroundResource(R.color.selected)
        }
        else {
            holder.itemView.setBackgroundResource(R.color.white)
        }
    }
    */



    override fun getItemCount(): Int {
        return UploadVideoList.size
    }
    class MyVideoHolder(itemView: View, listener: onUploadItemListener) :RecyclerView.ViewHolder(itemView){

        val UploadVideoImage : ShapeableImageView = itemView.findViewById(R.id.UploadVideoTitleImage)
        val UploadVideoHeading : TextView = itemView.findViewById(R.id.UploadVideoHeading_ID)

        init{
            itemView.setOnClickListener {
                listener.onItemClick(adapterPosition)
            }
        }

    }

}