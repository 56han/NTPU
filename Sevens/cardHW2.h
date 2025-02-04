#ifndef CARDHW2_H_INCLUDED
#define CARDHW2_H_INCLUDED
#include <string>
#include <iomanip>
using namespace std;
class card{
	private:
	char num[14]={'0','A','2','3','4','5','6','7','8','9','0','J','Q','K'};
	int value, suit;
	string spade[7]={"      *     ",
					 "     ***    ",
					 "  ********* ",
					 " ***********",
					 "  **  *  ** ",
					 "      *     ",
					 "     ***    "};
	string club[7]={ "      *     ",
					 "     ***    ",
					 "  ** *** ** ",
					 " ***** *****",
					 "  **  *  ** ",
					 "      *     ",
					 "     ***    "};
	string heart[7]={"            ",
					 "   **   **  ",
					 "  **** **** ",
				     "   *******  ",
					 "    *****   ",
					 "     ***    ",
					 "      *     "};
	string diamond[7]={ "      *     ",
						"     ***    ",
						"    *****   ",
						"   *******  ",
						"    *****   ",
						"     ***    ",
						"      *     "};
	public:
	card(int a,int b);
	void suit_club(int y);
	void suit_spade(int y);
	void suit_diamond(int y);
	void suit_heart(int y);
	void output(int x);
};


#endif // CARDHW2_H_INCLUDED
