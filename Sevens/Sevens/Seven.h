#ifndef SEVEN_H_INCLUDED
#define SEVEN_H_INCLUDED
#include <vector>
using namespace std;
class Seven{
private:
    static const char SPADES='S';
    static const char CLUBS='C';
    static const char HEARTS='H';
    static const char DIAMONDS='D';
    int vv;
    char ss;
    int flaggg;
    int cov_v;
    char cov_s;
    int a;
    int recordcov;
    int INPUT[52];
    int ALL[52];
    int c_value;
    int c_suit;
    int cc_value,cc_suit;
    int Time;
    int c1_v,c1_s;
    int on_table[3][4];
    int record;
    int r;
    int bo,co;
    int myp,conp;
    vector<int> PlayerCard;
    vector<int> MyCard;
    vector<int> Player7Check;
    vector<int> My7Check;
    vector<int> Player1Check;
    vector<int> My1Check;
    vector<int> Player13Check;
    vector<int> My13Check;
public:
    Seven();
    void onTable(int ,int);
    void leftcard();
    void mystart();
    void mycover(int ,char );
    void myturn(int ,char );
    void computerstart();
    void computerturn();
    int fapie();
    void famypie();
    void play1();
    void play2();
    void points();
    void com_cover_ontable();
};
#endif // SEVEN_H_INCLUDED
