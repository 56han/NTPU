#include "CardHW2.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
card::card(int a,int b){
	value=a+1;
	suit=b+1;
}//it means that spade 7 is card(6,0)

void card::output(int x){
	if(value!=10){
		if(x==9||x==1){
			for(int i=0;i<6;i++){
				cout<<setw(3)<<num[value];
			}
		}
		else{
			cout<<setw(3)<<num[value];
			if(suit==1){
				suit_spade(x-2);
			}	//spades//1
			else if(suit==2){
                suit_heart(x-2);
			}	//hearts//2
			else if(suit==3){
			     suit_diamond(x-2);
			}	//diamonds//3
			else{
			   suit_club(x-2);
			}	//clubs//4
			cout<<setw(3)<<num[value];
		}
	}
	//"10" is the exception, because it does not have ASCII number.

	else if(value==10){
		if(x==9||x==1){
			for(int i=0;i<6;i++){
				cout<<setw(3)<<"10";
			}
		}
		else{
			cout<<setw(3)<<"10";
			if(suit==1){
				suit_spade(x-2);
			}	//spades
			else if(suit==2){
				suit_heart(x-2);
			}	//hearts
			else if(suit==3){
				suit_diamond(x-2);
			}	//diamonds
			else{
				suit_club(x-2);
			}	//clubs
			cout<<setw(3)<<"10";
		}
	}	//end for "10"
}

void card::suit_club(int y){
	cout<<club[y];
}
void card::suit_spade(int y){
	cout<<spade[y];
}
void card::suit_heart(int y){
	cout<<heart[y];
}
void card::suit_diamond(int y){
	cout<<diamond[y];
}
