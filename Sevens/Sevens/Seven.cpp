#include "Seven.h"
#include "cardHW2.h"
#include "cardHW1.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
Seven::Seven(){
    r=0;
    bo=0;
    co=0;
    recordcov=0;
    Time=0;
    cov_v=0;
    flaggg=0;
    myp=0;
    conp=0;
    for(int i=0;i<52;i++){
        INPUT[i]=0;
        ALL[i]=0;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            on_table[i][j]=-1;
        }
    }
}
int Seven::fapie(){
    srand(time(0));
    int B;
    for(int i=0;i<52;i++){
        INPUT[i]=rand()%52;
        if(ALL[INPUT[i]]==0){
            ALL[INPUT[i]]=1;
        }
        else{
            i--;
        }
    }
    for(int l=0;l<26;l++){
        MyCard.push_back(INPUT[l]);
        if(INPUT[l]%13==6&&INPUT[l]/13==0){ //searching spade 7
            B=0;
        }
        if(MyCard[l]==19||MyCard[l]==32||MyCard[l]==45){
                My7Check.push_back(MyCard[l]);
        }
        else if((MyCard[l]>6&&MyCard[l]<=12)||(MyCard[l]>19&&MyCard[l]<=25)||(MyCard[l]>32&&MyCard[l]<=38)||(MyCard[l]>45&&MyCard[l]<=51)){
                My13Check.push_back(MyCard[l]);
        }
        else if((MyCard[l]>=0&&MyCard[l]<6)||(MyCard[l]>12&&MyCard[l]<19)||(MyCard[l]>25&&MyCard[l]<32)||(MyCard[l]>38&&MyCard[l]<45)){
                My1Check.push_back(MyCard[l]);//1~6
        }
    }
    cout<<endl;
    for(int l=0;l<26;l++){
            PlayerCard.push_back(INPUT[26+l]);
            if(INPUT[26+l]%13==6&&INPUT[26+l]/13==0){ //searching spade 7
                B=1;
            }
            if(PlayerCard[l]==19||PlayerCard[l]==32||PlayerCard[l]==45){
                Player7Check.push_back(PlayerCard[l]);//7
            }
            else if((PlayerCard[l]>6&&PlayerCard[l]<=12)||(PlayerCard[l]>19&&PlayerCard[l]<=25)||(PlayerCard[l]>32&&PlayerCard[l]<=38)||(PlayerCard[l]>45&&PlayerCard[l]<=51)){
                Player13Check.push_back(PlayerCard[l]);//8~13
            }
            else if((PlayerCard[l]>=0&&PlayerCard[l]<6)||(PlayerCard[l]>12&&PlayerCard[l]<19)||(PlayerCard[l]>25&&PlayerCard[l]<32)||(PlayerCard[l]>38&&PlayerCard[l]<45)){
                Player1Check.push_back(PlayerCard[l]);//1~6
            }
    }
    cout<<endl;
    return B;
}
void Seven::famypie(){
    for(int h=0;h<(26/10)+1;h++){
        for(int m=1;m<=9;m++){
            for(int t=1;t<=10;t++){
                if(h*10+t>26){
                    break;
                }
                    c_value=MyCard[h*10+t-1]%13;
                    c_suit=MyCard[h*10+t-1]/13;
                    card s(c_value,c_suit);
                    s.output(m);
            }
                cout<<endl;
        }
    }
}
void Seven::play1(){
    int Flag=0;
    int s;
    int ww=0,www=0;
        for(int i=0;i<My13Check.size();i++){
            for(int j=0;j<4;j++){
                if(My13Check[i]==7+13*j&&on_table[0][j]==-1){
                    flaggg=1;
                }//-------------------------------------------------------------8
                if(My13Check[i]==on_table[0][j]+1&&My13Check[i]%13!=0){
                    flaggg=1;
                }//--------------------------------------------------------9~13
            }
        }
        for(int i=0;i<My1Check.size();i++){
            for(int j=0;j<4;j++){
                if(My1Check[i]==5+13*j&&on_table[2][j]==-1){
                    flaggg=1;
                }//---------------------------------------------------------------6
                if(My1Check[i]==on_table[2][j]-1&&My1Check[i]%13!=12){
                    flaggg=1;
                }//-----------------------------------------------------------1~5

            }
        }
        for(int i=0;i<My7Check.size();i++){
            for(int j=0;j<4;j++){
                if((My7Check[i]==19||My7Check[i]==32||My7Check[i]==45)&&on_table[1][j]==-1){
                    flaggg=1;
                }//---------------------------------------------------------------7
            }
        }
        if(flaggg==1){
            cout<<"(Player 01's) Your turn!"<<endl;
            cout<<"Please enter the value:(1:A, 11:J, 12:Q, 13:K)"<<endl;
            while(cin>>vv){
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
                /*cout<<"Wrong Input. Please enter again."<<endl;
                cout<<endl;
                cout<<"Please enter the value:(1:A, 11:J, 12:Q, 13:K)"<<endl;*/
                for(int i=0;i<MyCard.size();i++){//check whether i have that card
                    if(MyCard[i]==vv-1+s*13){
                        break;
                    }
                    else{
                        ww++;
                    }
                }
                if(ww!=MyCard.size()){
                    if(vv>=1&&vv<7){
                        if(on_table[2][s]-1==13*s+vv-1||(vv==6&&on_table[2][s]==-1&&on_table[1][s]!=-1)){
                            myturn(vv,ss);
                            Flag=1;
                        }
                    }
                    else if(vv==7){
                        myturn(vv,ss);
                        Flag=1;

                    }
                    else if(vv>7&&vv<=13){
                        if(on_table[0][s]+1==13*s+vv-1||(vv==8 && on_table[0][s]==-1 && on_table[1][s]!=-1)){
                            myturn(vv,ss);
                            Flag=1;
                        }
                    }
                }
                if(Flag==1){
                    break;
                }
                cout<<"Wrong Input. The card can not be played."<<endl;
                cout<<"Please enter again."<<endl;
                cout<<endl;
                cout<<"Please enter the value:(1:A, 11:J, 12:Q, 13:K)"<<endl;
            }
            system("pause");
            system("cls");
            cout<<"After playing that card, here are your cards:"<<endl;
            leftcard();
        }
        else{
            cout<<"Which one do you want to cover?"<<endl;
            cout<<"Please enter the value:(1:A, 11:J, 12:Q, 13:K)"<<endl;
            cin>>cov_v;
            cout<<"Please enter the suit:(S:Spade, C:Clubs, H:Hearts, D:Diamonds)"<<endl;
            cin>>cov_s;
            for(int i=0;i<MyCard.size();i++){
                if(MyCard[i]==cov_v-1+cov_s*13){
                    break;
                }
                else{
                    www++;
                }
            }
            if(www!=MyCard.size()){
                if((cov_v>=1&&cov_v<=13)&&(cov_s=='S'||cov_s=='H'||cov_s=='C'||cov_s=='D')){
                    mycover(cov_v,cov_s);
                    system("pause");
                    system("cls");
                    cout<<"After covering that card, here are your cards:"<<endl;
                    leftcard();
                }
            }
            else{
                cout<<"Wrong COVER Input. Please enter again."<<endl;
                cout<<endl;
                play1();
            }
        }
        flaggg=0;
}
void Seven::play2(){
    cout<<"Player 02 played a card!"<<endl;
    computerturn();
}
void Seven::mycover(int ccv, char ccs){//SHDC
    cardcc N(ccv,ccs);
    N.output();
    myp+=ccv;
    if(ccs=='S'){//0~12
        recordcov=ccv-1;
    }
    else if(ccs=='H'){//13~25
        recordcov=ccv+13-1;
    }
    else if(ccs=='D'){//26~38
        recordcov=ccv+26-1;
    }
    else if(ccs=='C'){//39~51
        recordcov=ccv+39-1;
    }
    for(int i=0;i<25-Time;i++){
        if(MyCard[i]==recordcov){
            MyCard.erase(MyCard.begin()+i);
            break;
        }
        if(My1Check[i]==recordcov){
            My1Check.erase(My1Check.begin()+i);
            break;
        }
        if(My1Check[i]==recordcov){
            My1Check.erase(My1Check.begin()+i);
            break;
        }
    }
}
void Seven::leftcard(){
    Time++;
    if(Time==26){
        return;
    }
    for(int h=0;h<((26-Time)/10)+1;h++){
        for(int m=1;m<=9;m++){
            for(int t=1;t<=10;t++){
                if(h*10+t>26-Time){
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

void Seven::mystart(){
    cardcc Nnew(7,'S');
    Nnew.output();
    on_table[1][0]=6;
    onTable(1,1);
    for(int i=0;i<26;i++){
        if(MyCard[i]==6){
            MyCard.erase(MyCard.begin()+i);
        }
    }
}
void Seven::myturn(int va, char su){//SHDC
    cardcc N(va,su);
    N.output();
    if(su=='S'){//0~12
        record=va-1;
        if(record<6){
            on_table[2][0]=record;
            onTable(2,0);
        }
        else{
            on_table[0][0]=record;
            onTable(0,0);
        }
    }
    else if(su=='H'){//13~25
        record=va-1+13;
        if(record<19){
            on_table[2][1]=record;
            onTable(2,1);
        }
        else if(record==19){
            on_table[1][1]=record;
            onTable(1,1);
        }
        else{
            on_table[0][1]=record;
            onTable(0,1);
        }
    }
    else if(su=='D'){//26~38
        record=va-1+26;
        if(record<32){
            on_table[2][2]=record;
            onTable(2,2);
        }
        else if(record==32){
            on_table[1][2]=record;
            onTable(1,2);
        }
        else{
            on_table[0][2]=record;
            onTable(0,2);
        }
    }
    else if(su=='C'){//39~51
        record=va-1+39;
        if(record<45){
            on_table[2][3]=record;
            onTable(2,3);
        }
        else if(record==45){
            on_table[1][3]=record;
            onTable(1,3);
        }
        else{
            on_table[0][3]=record;
            onTable(0,3);
        }
    }
    for(int i=0;i<25-Time;i++){
        if(MyCard[i]==record){
            MyCard.erase(MyCard.begin()+i);
            break;
        }
    }
}
void Seven::computerstart(){
    cardcc nnew(7,'S');
    nnew.output();
    on_table[1][0]=6;
    onTable(1,0);
}
void Seven::computerturn(){//SHDC
    int c;
    srand(time(0));
    if(!Player7Check.empty()){
        r=rand()%Player7Check.size();
        if(Player7Check[r]==19){
            on_table[1][1]=19;
            cardcc n_new(7,'H');
            n_new.output();
            onTable(1,1);
        }
        else if(Player7Check[r]==32){
            on_table[1][2]=32;
            cardcc n_new(7,'D');
            n_new.output();
            onTable(1,2);
        }
        else if(Player7Check[r]==45){
            on_table[1][3]=45;
            cardcc n_new(7,'C');
            n_new.output();
            onTable(1,3);
        }
        Player7Check.erase(Player7Check.begin()+r);
        return;
    }//-----------------------------------------------------------------7
    else if(!Player13Check.empty()||!Player1Check.empty()){//SHDC
            for(int i=0;i<Player13Check.size();i++){
                for(int j=0;j<4;j++){
                    if(Player13Check[i]==7+13*j&&on_table[0][j]==-1&&on_table[1][j]!=-1){
                        on_table[0][j]=7+13*j;
                        if(j==0){
                            cardcc n_new(8,'S');
                            n_new.output();
                        }
                        else if(j==1){
                            cardcc n_new(8,'H');
                            n_new.output();

                        }
                        else if(j==2){
                            cardcc n_new(8,'D');
                            n_new.output();

                        }
                        else{
                            cardcc n_new(8,'C');
                            n_new.output();
                        }
                        onTable(0,j);
                        Player13Check.erase(Player13Check.begin()+i);
                        return;
                    }//----------------------------------------------------------------------8
                    if(Player13Check[i]==on_table[0][j]+1&&Player13Check[i]%13!=0){//SHDC
                        on_table[0][j]++;
                        c=on_table[0][j]%13;
                        if(j==0){
                            cardcc n_new(c+1,'S');
                            n_new.output();
                        }
                        else if(j==1){
                            cardcc n_new(c+1,'H');
                            n_new.output();
                        }
                        else if(j==2){
                            cardcc n_new(c+1,'D');
                            n_new.output();
                        }
                        else{
                            cardcc n_new(c+1,'C');
                            n_new.output();
                        }
                        onTable(0,j);
                        Player13Check.erase(Player13Check.begin()+i);
                        return;
                    }//------------------------------------------------------------9~13
                }
            }
            for(int i=0;i<Player1Check.size();i++){
                for(int j=0;j<4;j++){
                    if(Player1Check[i]==5+13*j&&on_table[2][j]==-1&&on_table[1][j]!=-1){
                        on_table[2][j]=5+13*j;
                        if(j==0){
                            cardcc n_new(6,'S');
                            n_new.output();
                        }
                        else if(j==1){
                            cardcc n_new(6,'H');
                            n_new.output();

                        }
                        else if(j==2){
                            cardcc n_new(6,'D');
                            n_new.output();

                        }
                        else{
                            cardcc n_new(6,'C');
                            n_new.output();
                        }
                        onTable(2,j);
                        Player1Check.erase(Player1Check.begin()+i);
                        return;
                    }//---------------------------------------------------------------6
                    if(Player1Check[i]==on_table[2][j]-1&&Player1Check[i]%13!=12){
                        on_table[2][j]--;
                        c=on_table[2][j]%13;
                        if(j==0){
                            cardcc n_new(c+1,'S');
                            n_new.output();
                        }
                        else if(j==1){
                            cardcc n_new(c+1,'H');
                            n_new.output();

                        }
                        else if(j==2){
                            cardcc n_new(c+1,'D');
                            n_new.output();

                        }
                        else{
                            cardcc n_new(c+1,'C');
                            n_new.output();
                        }
                        onTable(2,j);
                        Player1Check.erase(Player1Check.begin()+i);
                        return;
                    }//----------------------------------------------------------------1~5
                }
            }
    }
    int mini=13, I=-1;
    for(int i=0;i<Player1Check.size();i++){
        if(Player1Check[i]%13<mini){
            I=i;
            mini=Player1Check[i]%13;
        }
    }
    if(I!=-1){
        conp+=mini+1;
        Player1Check.erase(Player1Check.begin()+I);
        cout<<"Player 02 covered a card."<<endl;
        com_cover_ontable();
        return;
    }
    int maxi=-1;
    for(int i=0;i<Player13Check.size();i++){
        if(Player1Check[i]%13>maxi){
            I=i;
            maxi=Player1Check[i]%13;
        }
    }
    conp+=maxi+1;
    Player13Check.erase(Player13Check.begin()+I);
    cout<<"Player 02 covered a card."<<endl;
}

void Seven::points(){
    if(myp<conp){
        cout<<"Your point(Player 01's points):"<<myp<<endl;
        cout<<"Player 02's point:"<<conp<<endl;
        cout<<"you win!"<<endl;
    }
    else if(myp>conp){
        cout<<"Your point(Player 01's points):"<<myp<<endl;
        cout<<"Player 02's point:"<<conp<<endl;
        cout<<"Player 02 wins!"<<endl;
    }
    else{
        cout<<"Your point(Player 01's points):"<<myp<<endl;
        cout<<"Player 02's point:"<<conp<<endl;
        cout<<"It's even!"<<endl;
    }
}
void Seven::onTable(int b,int c){
        a=on_table[b][c];
        bo=b;
        co=c;
        cout<<"Here is the card on the table:"<<endl;
        for(int h=0;h<3;h++){
            for(int m=1;m<=9;m++){
                for(int t=0;t<4;t++){
                    if(on_table[h][t]==-1){
                        for(int i=0;i<6;i++){
                            cout<<setw(3)<<" ";
                        }
                    }
                    else{
                        c1_v=on_table[h][t]%13;
                        c1_s=on_table[h][t]/13;
                        card s1(c1_v,c1_s);
                        s1.output(m);
                    }
                }
                cout<<endl;
            }
        }
}
void Seven::com_cover_ontable(){
        a=on_table[bo][co];
        cout<<"Here is the card on the table:"<<endl;
        for(int h=0;h<3;h++){
            for(int m=1;m<=9;m++){
                for(int t=0;t<4;t++){
                    if(on_table[h][t]==-1){
                        for(int i=0;i<6;i++){
                            cout<<setw(3)<<" ";
                        }
                    }
                    else{
                        c1_v=on_table[h][t]%13;
                        c1_s=on_table[h][t]/13;
                        card s1(c1_v,c1_s);
                        s1.output(m);
                    }
                }
                cout<<endl;
            }
        }
}
