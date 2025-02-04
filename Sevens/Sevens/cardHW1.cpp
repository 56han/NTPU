#include "cardHW1.h"
#include <iostream>
#include <iomanip>
using namespace std;
cardcc::cardcc(int a,char b){
	if((a<=13 && a>=1) && ((b== SPADES) || (b== HEARTS) || (b== DIAMONDS) || (b== CLUBS))){
		value=a;
		suit=b;
		cout<<"value:"<<value<<endl;
		cout<<"suit:"<<suit<<endl;
	}

}

void cardcc::output(){
	if(value!=10){
		if((suit== SPADES)||(suit== HEARTS)||(suit== DIAMONDS)||(suit== CLUBS)){
			if(value<=13 && value>=1){
				for(int i=0;i<6;i++){
					cout<<setw(3)<<num[value];
				}
				cout<<endl;
				if(suit==SPADES){
					suit_spade();
				}	//spades
				else if(suit==HEARTS){
					suit_heart();
				}	//hearts
				else if(suit==DIAMONDS){
					suit_diamond();
				}	//diamonds
				else{
					suit_club();
				}	//clubs
				for(int i=0;i<6;i++){
					cout<<setw(3)<<num[value];
				}
				cout<<endl;
			}
		}	//value:1~9 and 11~13
	}// end for value!=10

	//"10" is the exception, because it does not have ASCII number.

	else if(value==10){
		if((suit== SPADES)||(suit== HEARTS)||(suit== DIAMONDS)||(suit== CLUBS)){
			for(int i=0;i<6;i++){
				cout<<setw(3)<<"10";
			}
			cout<<endl;
			if(suit==SPADES){
				cout<<setw(3)<<"10"<<setw(7)<<"*"<<setw(8)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(8)<<"***"<<setw(7)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(11)<<"*********"<<setw(4)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(12)<<"***********"<<setw(3)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(11)<<"**  *  **"<<setw(4)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(7)<<"*"<<setw(8)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(8)<<"***"<<setw(7)<<"10"<<endl;
			}	//spades
			else if(suit==HEARTS){
				cout<<setw(3)<<"10"<<setw(15)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(10)<<"**   **"<<setw(5)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(11)<<"**** ****"<<setw(4)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(10)<<"*******"<<setw(5)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(9)<<"*****"<<setw(6)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(8)<<"***"<<setw(7)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(7)<<"*"<<setw(8)<<"10"<<endl;
			}	//hearts
			else if(suit==DIAMONDS){
				cout<<setw(3)<<"10"<<setw(7)<<"*"<<setw(8)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(8)<<"***"<<setw(7)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(9)<<"*****"<<setw(6)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(10)<<"*******"<<setw(5)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(9)<<"*****"<<setw(6)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(8)<<"***"<<setw(7)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(7)<<"*"<<setw(8)<<"10"<<endl;
			}	//diamonds
			else{
				cout<<setw(3)<<"10"<<setw(7)<<"*"<<setw(8)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(8)<<"***"<<setw(7)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(11)<<"** *** **"<<setw(4)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(12)<<"***** *****"<<setw(3)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(11)<<"**  *  **"<<setw(4)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(7)<<"*"<<setw(8)<<"10"<<endl;
				cout<<setw(3)<<"10"<<setw(8)<<"***"<<setw(7)<<"10"<<endl;
			}	//clubs
			for(int i=0;i<6;i++){
				cout<<setw(3)<<"10";
			}
			cout<<endl;
		}
	}	//end for "10"
}

void cardcc::suit_club(){
	cout<<setw(3)<<num[value]<<setw(7)<<"*"<<setw(8)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(8)<<"***"<<setw(7)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(11)<<"** *** **"<<setw(4)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(12)<<"***** *****"<<setw(3)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(11)<<"**  *  **"<<setw(4)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(7)<<"*"<<setw(8)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(8)<<"***"<<setw(7)<<num[value]<<endl;
}
void cardcc::suit_spade(){
	cout<<setw(3)<<num[value]<<setw(7)<<"*"<<setw(8)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(8)<<"***"<<setw(7)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(11)<<"*********"<<setw(4)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(12)<<"***********"<<setw(3)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(11)<<"**  *  **"<<setw(4)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(7)<<"*"<<setw(8)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(8)<<"***"<<setw(7)<<num[value]<<endl;
}
void cardcc::suit_heart(){
	cout<<setw(3)<<num[value]<<setw(15)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(10)<<"**   **"<<setw(5)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(11)<<"**** ****"<<setw(4)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(10)<<"*******"<<setw(5)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(9)<<"*****"<<setw(6)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(8)<<"***"<<setw(7)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(7)<<"*"<<setw(8)<<num[value]<<endl;
}
void cardcc::suit_diamond(){
	cout<<setw(3)<<num[value]<<setw(7)<<"*"<<setw(8)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(8)<<"***"<<setw(7)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(9)<<"*****"<<setw(6)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(10)<<"*******"<<setw(5)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(9)<<"*****"<<setw(6)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(8)<<"***"<<setw(7)<<num[value]<<endl;
	cout<<setw(3)<<num[value]<<setw(7)<<"*"<<setw(8)<<num[value]<<endl;
}
