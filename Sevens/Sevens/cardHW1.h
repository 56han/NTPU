#ifndef CARDHW1_H_INCLUDED
#define CARDHW1_H_INCLUDED
#include <iostream>
using namespace std;
class cardcc{
	private:
	char num[14]={'0','A','2','3','4','5','6','7','8','9','0','J','Q','K'};
	int value;
	char suit;
	public:
	static const char SPADES='S';
	static const char CLUBS='C';
    static const char HEARTS='H';
    static const char DIAMONDS='D';
	cardcc(int a,char b);
	void output();
	void suit_spade();
	void suit_club();
	void suit_heart();
	void suit_diamond();
};


#endif // CARDHW1_H_INCLUDED
