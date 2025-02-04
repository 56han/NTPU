package com.example.motionapp

import android.annotation.SuppressLint
import android.graphics.Color
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.google.android.material.imageview.ShapeableImageView

class RecordMyAdapter (private val RecordFitnessList : ArrayList<Record_List>): RecyclerView.Adapter<RecordMyAdapter.MyVideoHolder>() {
    private lateinit var mListener : onItemListener
    interface onItemListener{
        fun onItemClick(position : Int)
    }

    fun setonItemListener(listener: onItemListener){
        mListener = listener
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): MyVideoHolder {
        val itemView = LayoutInflater.from(parent.context).inflate(R.layout.record_list_item,parent,false)
        return MyVideoHolder(itemView,mListener)
    }


    override fun onBindViewHolder(holder: MyVideoHolder, position: Int) {
        val currentItem = RecordFitnessList[position]
        holder.RecordImage.setImageResource(currentItem.RecordTitleImage)
        holder.RecordHeading.text = currentItem.RecordHeading_ID

    }

    override fun getItemCount(): Int {
        return RecordFitnessList.size
    }
    class MyVideoHolder(itemView: View, listener: onItemListener) :RecyclerView.ViewHolder(itemView){

        val RecordImage : ShapeableImageView = itemView.findViewById(R.id.RecordTitleImage)
        val RecordHeading : TextView = itemView.findViewById(R.id.RecordHeading_ID)

        init{
            itemView.setOnClickListener {
                listener.onItemClick(adapterPosition)
            }
        }
    }
}