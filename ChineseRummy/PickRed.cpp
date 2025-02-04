#include "PickRed.h"
#include "HW2.h"
#include "HW1.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;
PickRed::PickRed(){
    starter=0;
    flag=0;
    flaggg=0;
    myp=0;
    conp=0;
    for(int i=0;i<52;i++){
        ALL[i]=0;
    }
}

void PickRed::SetColor(int color = 7){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,color);
}

void PickRed::GOGO(){
    int x;
    fapie();
    for(int j=0;j<4;j++){
        x=INPUT[j];
        on_table.push_back(x);
        INPUT.erase(INPUT.begin()+j);
    }
    onTable();
    SetColor(7);
    cout<<"Start from you (Player 01)!"<<endl;
    starter=2;
    play1();
    points();
    while(flag<24){
        if(starter==2){
            starter=1;
            play2();//computer
            SetColor(7);
            points();
        }
        else if(starter==1){
            starter=2;
            play1();//me
            SetColor(7);
            points();
        }
        flag++;
    }
    cout<<"The End!"<<endl;
}

void PickRed::fapie(){
    int r;
    int x;
    srand(time(0));
    for(int i=0;i<52;i++){
        r=rand()%52;
        if(ALL[r]==0){
            ALL[r]=1;
            INPUT.push_back(r);
        }
        else{
            i--;
        }
    }
    for(int i=0;i<12;i++){
        MyCard.push_back(INPUT[i]);
        INPUT.erase(INPUT.begin()+i);
        if((MyCard[i]%13)+1<=9){
            x=MyCard[i];
            my_under10.push_back(x);
        }
        else if((MyCard[i]%13)+1>9){// 9 10 J Q K is 10 points but 1 with 9
            x=MyCard[i];
            my_up10.push_back(x);
        }
    }
    for(int i=0;i<12;i++){
        PlayerCard.push_back(INPUT[12+i]);
        INPUT.erase(INPUT.begin()+12+i);
        if((PlayerCard[i]%13)+1<=9){
            x=PlayerCard[i];
            com_under10.push_back(x);
        }
        else if((PlayerCard[i]%13)+1>9){// 9 10 J Q K is 10 points but 1 with 9
            x=PlayerCard[i];
            com_up10.push_back(x);
        }
    }
}
void PickRed::play1(){
    int s;
    int Flag=0;
    int ww=0,www=0;
    cout<<"Your cards:"<<endl;
    leftcard();
        for(int i=0;i<my_under10.size();i++){
            for(int j=0;j<on_table.size();j++){
                if((my_under10[i]%13)+1+(on_table[j]%13)+1==10){
                    flaggg=1;
                    break;
                }
            }
        }
        for(int i=0;i<my_up10.size();i++){
            for(int j=0;j<on_table.size();j++){
                if((my_up10[i]%13)+1==(on_table[j]%13)+1){
                    flaggg=1;
                    break;
                }
            }
        }
        if(flaggg==1){//I have a card (needn't to played my card on the table)
            SetColor(7);
            cout<<"(Player 01's) Your turn!"<<endl;
            cout<<"Please enter the value:(1:A, 11:J, 12:Q, 13:K)"<<endl;
            cin>>vv;
            while(cin.fail()==1){
                SetColor(7);
                cout<<"Please enter the correct value:(1:A, 11:J, 12:Q, 13:K)"<<endl;
                cin.clear();
                cin.ignore();
                cin>>vv;
            }
            while(1){
                SetColor(7);
                cout<<"Please enter the suit:(S:Spade, C:Clubs, H:Hearts, D:Diamonds)"<<endl;
                cin>>ss;//SHDC
                if((ss=='S'||ss=='H'||ss=='D'||ss=='C')&&(vv>=1&&vv<=13)){
                   if(ss=='S'){
                        s=0;
                    }
                    else if(ss=='H'){
                        s=1;
                    }
                    else if(ss=='D'){
                        s=2;
                    }
                    else if(ss=='C'){
                        s=3;
                    }
                }
                for(int i=0;i<MyCard.size();i++){//check whether i have that card
                    if(MyCard[i]==vv-1+s*13){
                        break;
                    }
                    else{
                        ww++;
                    }
                }
                if(ww!=MyCard.size()){//check whether that card can be played
                    for(int i=0;i<on_table.size();i++){
                        if(vv>=10){
                           if((on_table[i]%13)+1==vv){
                                Flag=1;
                                break;
                            }
                        }
                        else if(vv<10){
                            if((on_table[i]%13)+1+vv==10){
                                Flag=1;
                                break;
                            }
                        }
                    }
                }
                if(Flag==1){
                    myturn(vv,s,0);
                    draw(1);
                    SetColor(7);
                    break;
                }
                SetColor(7);
                cout<<"Wrong Input. The card can not be played."<<endl;
                cout<<"Please enter the value:(1:A, 11:J, 12:Q, 13:K)"<<endl;
                cin>>vv;
                while(cin.fail()==1){
                    SetColor(7);
                    cout<<"Please enter the correct value:(1:A, 11:J, 12:Q, 13:K)"<<endl;
                    cin.clear();
                    cin.ignore();
                    cin>>vv;
                }
            }
        }
        else{//i can not eat so i need to play a card
            SetColor(7);
            cout<<"You need to play a card on the table."<<endl;
            cout<<"Please play a card."<<endl;
            cout<<"Please enter the value:(1:A, 11:J, 12:Q, 13:K)"<<endl;
            cin>>vv;
            while(cin.fail()==1){
                SetColor(7);
                cout<<"Please enter the correct value:(1:A, 11:J, 12:Q, 13:K)"<<endl;
                cin.clear();
                cin.ignore();
                cin>>vv;
            }
            while(1){
                SetColor(7);
                cout<<"Please enter the suit:(S:Spade, C:Clubs, H:Hearts, D:Diamonds)"<<endl;
                cin>>ss;//SHDC
                if((ss=='S'||ss=='H'||ss=='D'||ss=='C')&&(vv>=1&&vv<=13)){
                   if(ss=='S'){
                        s=0;
                    }
                    else if(ss=='H'){
                        s=1;
                    }
                    else if(ss=='D'){
                        s=2;
                    }
                    else if(ss=='C'){
                        s=3;
                    }
                }
                for(int i=0;i<MyCard.size();i++){//check whether i have that card
                    if(MyCard[i]==vv-1+s*13){
                        MyCard.erase(MyCard.begin()+i);
                        break;
                    }
                    else{
                        www++;
                    }
                }
                on_table.push_back(vv-1+s*13);
                SetColor(7);
                cout<<"The cards on the table:"<<endl;
                onTable();
                draw(1);
                SetColor(7);
                cout<<"Here are your cards:"<<endl;
                leftcard();
                SetColor(7);
                if(www!=MyCard.size()){
                    break;
                }
                cout<<"Wrong Input. The card can not be played."<<endl;
                cout<<"Please enter the value:(1:A, 11:J, 12:Q, 13:K)"<<endl;
                cin>>vv;
                while(cin.fail()==1){
                    SetColor(7);
                    cout<<"Please enter the correct value:(1:A, 11:J, 12:Q, 13:K)"<<endl;
                    cin.clear();
                    cin.ignore();
                    cin>>vv;
                }
            }
        }
        flaggg=0;
}
void PickRed::play2(){//0:S 1:H 2:D 3:C
    srand(time(0));
    int r;
    int y;
    int k1;
    int i1;
    int fla=2;
    for(int k=0;k<com_up10.size();k++){
        for(int l=0;l<on_table.size();l++){
            if((com_up10[k]%13)+1==(on_table[l]%13)+1){
                k1=k;
                fla=0;
                comturn((com_up10[k1]%13)+1,com_up10[k1]/13);
                break;
            }
        }
    }
    if(fla!=0){
        for(int i=0;i<com_under10.size();i++){
            for(int j=0;j<on_table.size();j++){
                if((com_under10[i]%13)+1+(on_table[j]%13)+1==10){
                    i1=i;
                    fla=1;
                    comturn((com_under10[i1]%13)+1,com_under10[i1]/13);
                    break;
                }
            }
        }
    }
    if(fla!=0&&fla!=1){//computer need to play a card
        r=rand()%PlayerCard.size();
        y=PlayerCard[r];
        on_table.push_back(y);
        PlayerCard.erase(PlayerCard.begin()+r);
    }
    draw(0);
    fla=2;
}
ostream &operator<<(ostream &output, const PickRed &a){
    if(a.myp<a.conp){
        output<<"My points:"<<a.myp<<endl;
        output<<"Computer's point: "<<a.conp<<endl;
        output<<"you win!"<<endl;
    }
    else if(a.myp>a.conp){
        output<<"My points:"<<a.myp<<endl;
        output<<"Computer's point: "<<a.conp<<endl;
        output<<"Computer wins!"<<endl;
    }
    else{
        output<<"My points:"<<a.myp<<endl;
        output<<"Computer's point: "<<a.conp<<endl;
        output<<"It's even!"<<endl;
    }
}
void PickRed::myturn(int v1,int s1,int Q1){//0:S 1:H 2:D 3:C
    for(int j=0;j<on_table.size();j++){
            if(v1==(on_table[j]%13)+1){
                if(s1==1||s1==2){
                    mypoint.push_back(v1-1+13*s1);
                }
                if(on_table[j]/13==1||on_table[j]/13==2){
                    mypoint.push_back(on_table[j]);
                }
                on_table.erase(on_table.begin()+j);
                break;
            }
            else if(v1+(on_table[j]%13)+1==10){
                if(s1==1||s1==2){
                    mypoint.push_back(v1-1+13*s1);
                }
                if(on_table[j]/13==1||on_table[j]/13==2){
                    mypoint.push_back(on_table[j]);
                }
                if(on_table[j]==0){
                    mypoint.push_back(0);
                }
                if(v1-1+13*s1==0){
                    mypoint.push_back(0);
                }
                on_table.erase(on_table.begin()+j);
                break;
            }
    }
        for(int i=0;i<MyCard.size();i++){
            if(MyCard[i]==v1-1+s1*13){
                MyCard.erase(MyCard.begin()+i);
                break;
            }
        }
        for(int i=0;i<my_under10.size();i++){
            if(my_under10[i]==v1-1+s1*13){
                my_under10.erase(my_under10.begin()+i);
                break;
            }
        }
        for(int i=0;i<my_up10.size();i++){
            if(my_up10[i]==v1-1+s1*13){
                my_up10.erase(my_up10.begin()+i);
                break;
            }
        }
}
void PickRed::comturn(int v2,int s2){
    char ch;
    if(s2==0){
        ch='S';
    }
    else if(s2==1){
        ch='H';
    }
    else if(s2==2){
        ch='D';
    }
    else if(s2==3){
        ch='C';
    }
    SetColor(7);
    cout<<"Player played the card:"<<endl;
    cardcc nnew(v2,ch);
    nnew.output();
    for(int j=0;j<on_table.size();j++){
            if(v2==(on_table[j]%13)+1){
                if(s2==1||s2==2){
                    conpoint.push_back(v2-1+13*s2);
                }
                if(on_table[j]/13==1||on_table[j]/13==2){
                    conpoint.push_back(on_table[j]);
                }
                on_table.erase(on_table.begin()+j);
                break;
            }
            else if(v2+(on_table[j]%13)+1==10){
                if(s2==1||s2==2){
                    conpoint.push_back(v2-1+13*s2);
                }
                if(on_table[j]/13==1||on_table[j]/13==2){
                    conpoint.push_back(on_table[j]);
                }
                if(on_table[j]==0){
                    conpoint.push_back(0);

                }
                if(v2-1+13*s2==0){
                    conpoint.push_back(0);
                }
                on_table.erase(on_table.begin()+j);
                break;
            }
    }
    for(int i=0;i<PlayerCard.size();i++){
        if(PlayerCard[i]==v2-1+s2*13){
            PlayerCard.erase(PlayerCard.begin()+i);
            break;
        }
    }
    for(int i=0;i<com_under10.size();i++){
        if(com_under10[i]==v2-1+s2*13){
            com_under10.erase(com_under10.begin()+i);
            break;
        }
    }
    for(int i=0;i<com_up10.size();i++){
        if(com_up10[i]==v2-1+s2*13){
            com_up10.erase(com_up10.begin()+i);
            break;
        }
    }
}
void PickRed::draw(int who){//who=0:computer //who=1:me
    int f=1;
    int y;
    y=INPUT[0];
    for(int j=1;j<on_table.size();j++){
        if((y%13)+1>=10){
            if((y%13)+1==(on_table[j]%13)+1){
                if(who==0){
                    SetColor(7);
                    cout<<y%13+1<<" and "<<(on_table[j]%13)+1<<" can be taken away by computer."<<endl;
                    if(y/13==1||y/13==2){
                        conpoint.push_back(y);
                    }
                    if(on_table[j]/13==1||on_table[j]/13==2){
                        conpoint.push_back(on_table[j]);
                    }
                    on_table.erase(on_table.begin()+j);
                    f=0;
                    break;
                }
                else if(who==1){
                    SetColor(7);
                    cout<<y%13+1<<" and "<<(on_table[j]%13)+1<<" can be taken away by you."<<endl;
                    if(y/13==1||y/13==2){
                        mypoint.push_back(y);
                    }
                    if(on_table[j]/13==1||on_table[j]/13==2){
                        conpoint.push_back(on_table[j]);
                    }
                    on_table.erase(on_table.begin()+j);
                    f=0;
                    break;
                }
            }
        }//---------------------------------------------------------------
        else{
            if((y%13)+1+(on_table[j]%13)+1==10){
                if(who==0){
                    cout<<y%13+1<<" and "<<(on_table[j]%13)+1<<" can be taken away by computer."<<endl;
                    if(y/13==1||y/13==2){
                        conpoint.push_back(y);
                    }
                    if(on_table[j]/13==1||on_table[j]/13==2){
                        conpoint.push_back(on_table[j]);
                    }
                    on_table.erase(on_table.begin()+j);
                    f=0;
                       break;
                }
                else if(who==1){
                    cout<<y%13+1<<" and "<<(on_table[j]%13)+1<<" can be taken away by you."<<endl;
                    if(y/13==1||y/13==2){
                        mypoint.push_back(y);
                    }
                    if(on_table[j]/13==1||on_table[j]/13==2){
                        conpoint.push_back(on_table[j]);
                    }
                    on_table.erase(on_table.begin()+j);
                    f=0;
                    break;
                }
            }
        }
    }
    if(f==1){
        on_table.push_back(INPUT[0]);
    }
    INPUT.erase(INPUT.begin()+0);
    onTable();
}
void PickRed::leftcard(){
    if(MyCard.size()==0){
        return;
    }
    for(int h=0;h<(MyCard.size()/10)+1;h++){
        for(int m=1;m<=9;m++){
            for(int t=1;t<=10;t++){
                if(h*10+t>MyCard.size()){
                    break;
                }
                cc_value=MyCard[h*10+t-1]%13;
                cc_suit=MyCard[h*10+t-1]/13;
                card ss(cc_value,cc_suit);
                ss.output(m);
            }
            cout<<endl;
        }
    }//output my remaining cards
}
void PickRed::points(){
    myp=0;
    conp=0;
    for(int m=0;m<mypoint.size();m++){
        if(mypoint[m]==0){
            myp+=10;
        }
        else if((mypoint[m]%13)+1>=9){
            myp+=10;
        }
        else if(mypoint[m]==13||mypoint[m]==26){
            myp+=20;
        }
        else{
            myp+=(mypoint[m])%13+1;
        }
    }
    for(int c=0;c<conpoint.size();c++){
        if(conpoint[c]==0){
            conp+=10;
        }
        else if((conpoint[c]%13)+1>=9){
            conp+=10;
        }
        else if(conpoint[c]==13||conpoint[c]==26){
            conp+=20;
        }
        else{
            conp+=(conpoint[c])%13+1;
        }
    }
    SetColor(7);
    cout<<"My point:"<<myp<<endl;
    cout<<"Computer's point:"<<conp<<endl;
}
void PickRed::onTable(){
    int row;
    for(int j=0;j<on_table.size()-1;j++){
        for(int i=0;i<on_table.size();i++){
            if((on_table[i+1]/13==1||on_table[i+1]/13==2)&&(on_table[i]/13==0||on_table[i]/13==3)){
                swap(on_table[i],on_table[i+1]);
            }
        }
    }
    for(int j=0;j<on_table.size()-1;j++){
        for(int i=0;i<on_table.size();i++){
            if(on_table[i+1]>=13&&on_table[i+1]<39&&on_table[i]>=13&&on_table[i]<39){
                if(on_table[i+1]%13>on_table[i]%13){
                    swap(on_table[i],on_table[i+1]);
                }
            }
        }
    }
    SetColor(7);
    cout<<"Here is the card on the table:"<<endl;
    if(on_table.size()%4==0){
        row=on_table.size()/4;
    }
    else{
        row=(on_table.size()/4)+1;
    }
    for(int h=0;h<row;h++){
        for(int m=1;m<=9;m++){
            for(int t=0;t<4;t++){
                if(h*4+t>=on_table.size()){
                    break;
                }
                c1_v=on_table[h*4+t]%13;
                c1_s=on_table[h*4+t]/13;
                card s1(c1_v,c1_s);
                s1.output(m);
            }
            cout<<endl;
        }
    }
}
