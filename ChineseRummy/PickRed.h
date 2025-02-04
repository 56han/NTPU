#ifndef PICKRED_H_INCLUDED
#define PICKRED_H_INCLUDED
#include <vector>
#include <fstream>
using namespace std;
class PickRed{
    friend ostream &operator<<(ostream &, const PickRed &);
private:
    static const char SPADES='S';
    static const char CLUBS='C';
    static const char HEARTS='H';
    static const char DIAMONDS='D';
    int starter;
    int flag;
    int vv;
    char ss;
    int flaggg;
    int cov_v;
    char cov_s;
    int recordcov;
    vector<int> INPUT;
    int ALL[52];
    int c_value;
    int c_suit;
    int cc_value,cc_suit;
    int Time;
    int c1_v,c1_s;
    vector<int> on_table;
    int record;
    int r;
    int myp,conp;
    vector<int> mypoint;
    vector<int> conpoint;
    vector<int> PlayerCard;
    vector<int> MyCard;
    vector<int> my_under10;
    vector<int> my_up10;
    vector<int> com_under10;
    vector<int> com_up10;

public:
    PickRed();
    void onTable();
    void play1();
    void play2();
    void draw(int);
    void myturn(int ,int ,int);
    void comturn(int ,int );
    void leftcard();
    void fapie();
    void GOGO();
    void points();
    void SetColor(int );
};


#endif // PICKRED_H_INCLUDED
