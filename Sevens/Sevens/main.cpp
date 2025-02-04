#include "CardHW2.h"
#include "CardHW1.h"
#include "Seven.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
int A;
int starter=0;
int flag=0;
int main(){
    Seven S;
    A=S.fapie();
    cout<<"Your card:"<<endl;
    S.famypie();
    //start the game
    // first round
    if(A==0){
        cout<<"Start from you (Player 01)!"<<endl;
        S.mystart();
        system("pause");
        system("cls");
        cout<<"After playing the spades 7, here are your cards:"<<endl;
        S.leftcard();
        starter=1;
    }
    else{
        cout<<"Start from Player 02"<<"!"<<endl;
        S.computerstart();
        starter=0;
    }
    //After first round
    while(flag<51){
        if(starter==0){
            S.play1();
            starter=1;
        }
        else{
            S.play2();
            starter=0;
        }
        flag++;
    }
    cout<<"The End!"<<endl;
    S.points();
}
