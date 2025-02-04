#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <stdio.h>

using namespace std;

const int n = 3; //建立大小
bool random = false;
bool g_start = true; // 初始化
int i_search = 0;	//紀錄方法
// State Class Definition.
class State{
public:
	int A[n][n], g, h, t;  // State Array, General Cost, Heuristic Cost, and Total Cost.
	State *parent; //Parent Pointer.
	State(); //Constructor
	void reset(); // To set the start, cur, temp States...
	bool is_goal(); // true: state is goal.
					// false: state is not goal.
	bool operator==(const State &) const; //Logical equality Operator.
	bool operator<(const State &) const; //Logical Less-Than Operator.
	void print(); //State Array Printing function.
	void Heurs(); //State Heuristic Cost Calculator.
};

int cost;//General Cost
int Goal[n][n] = { { 5,8,6 },{ 0,7,4 },{ 2,3,1 } };  //目標
int space = 1, runtime = 1, timer = 0; //計數器建立
list< State > closed, fringe;
State start, cur, temp;
void IDS();
void UCS();
void Astar();
void GBFS();
bool RBFS(State s, int bound);
void Expand();
void PrintPath(State *s); //結果展示
bool InClosed(State &s);

int main() {
	cout << "1:IDS  2:UCS  3:A*  4:GBFS  5:RBFS" << endl;
	cin >> i_search;
	while(i_search!=-0){
        start.g = 0;
		start.Heurs();
		start.t = start.g + start.h;
		start.parent = NULL;
		timer = (clock() * 1000) / CLOCKS_PER_SEC;

		if(i_search == 1)
			IDS();
		else if(i_search == 2)
			UCS();
		else if(i_search == 3)
			Astar();
		else if(i_search == 4)
			GBFS();
		else if(i_search == 5) {
            cout << "starting RBFS Algorithm... \n";
			RBFS(start, 1000000);
            runtime = ((clock() * 1000) / CLOCKS_PER_SEC) - timer;
		}
		cin>>i_search;
	}
	getchar();
	return 0;
}

State::State() {
	reset();
}

void State::reset() {
	int i, j, k;
	g = h = t = 0;
	parent = NULL;
	if(g_start){
		if(!random){
			//手動輸入起始狀態
			cin>>A[0][0]>>A[0][1]>>A[0][2]>>A[1][0]>>A[1][1]>>A[1][2]>>A[2][0]>>A[2][1]>>A[2][2];
			cout << "initial state：" << endl;
			PrintPath(&start);
		}
		else{
			list< int > l;
			list< int >::iterator it;
			srand(time(0));
			for(i=0;i<n*n;i++)
				l.push_back(i);
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					it = l.begin();
					for(k=rand()%l.size();k>0;k--)
						it++;
					A[i][j] = (*it);
					l.erase(it);
				}
			}
			cout << "initial state：" << endl;
			PrintPath(&start);
		}
		g_start = false;
	}
}

bool State::is_goal(){
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(A[i][j] != Goal[i][j])
				return false;
		}
	}
	return true;
}

void State::print(){
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if((A[i][j]/10) == 0 )
				cout << A[i][j] << ' ' << ' ';
			else
				cout << A[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

bool State::operator==(const State &r)const{
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(A[i][j] != r.A[i][j])
				return false;
		}
	}
	return true;
}
bool State::operator<(const State &r)const {
	if(i_search == 1){
		return g < r.g;
	}
	else if(i_search == 2){
		return g < r.g;
	}
	else if(i_search == 3){
		return t < r.t;
	}
	else if(i_search == 4){
		return h < r.h;
	}
}

void State::Heurs(){
	int i, i2, j, j2, Heuristic = 0;
	bool found;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			found = false;
			for(i2=0;i2<n;i2++){
				for(j2=0;j2<n;j2++){
					if(Goal[i][j] == A[i2][j2]){
						Heuristic += abs(i-i2)+abs(j-j2);
						found = true;
					}
					if(found){
						break;
					}
				}
				if(found){
					break;
				}

			}
		}
	}
	h = Heuristic;
}

/* Iterative-Deepening Search (IDS)*/
void IDS(){
	int depth=0;
	cout << "starting IDS Algorithm... \n";
	while(true){
		cur = start;
		fringe.push_front(cur);
		while (!fringe.empty()){
			cur = fringe.front();
			if (cur.is_goal()){
				runtime = ((clock() * 1000) / CLOCKS_PER_SEC) - timer;
				cout << "Space= " << space << "\n";
				cout << "Cost= " << cur.g << "\n";
				cout << "Path:\n";
				PrintPath(&cur);
				return;
			}
			else if(depth > cur.g){
				Expand();
			}
			else{
				fringe.pop_front();
			}
		}
		fringe.clear();
		closed.clear();
		depth++;
	}
}

/*Uniform-Cost Search*/
void UCS(){
	cout << "starting Uniform-Cost Search Algorithm... \n";
	cur = start;
	fringe.push_front(cur);
	while(true){
		cur = fringe.front();
		for (list<State>::iterator it = fringe.begin();it != fringe.end();++it) {
			if((*it)<cur){
				cur = (*it);
			}
		}

		if(cur.is_goal()){
			runtime = ((clock() * 1000) / CLOCKS_PER_SEC) - timer;
			cout << "Space= " << space << "\n";
			cout << "Cost= " << cur.g << "\n";

			cout << "Path:\n";
			PrintPath(&cur);

			return;
		}
		else {
			Expand();
		}
	}
}

/*A* search*/
void Astar() {
	cout << "starting A* Algorithm... \n";
	cur = start;
	fringe.push_front(cur);
	while (true) {
		cur = fringe.front();
		for(list<State>::iterator it = fringe.begin(); it != fringe.end(); ++it) {
			if ((*it) < cur ) {
				cur = (*it);
			}
		}

		if(cur.is_goal()) {
			runtime = ((clock() * 1000) / CLOCKS_PER_SEC) - timer;
			cout << "Space= " << space << "\n";
			cout << "Cost= " << cur.g << "\n";
			cout << "Path:\n";
			PrintPath(&cur);
			return;
		}
		else{
			Expand();
		}
	}
}

/*Greedy Best-First Search*/
void GBFS(){
	cout << "starting GBFS Algorithm... \n";
	cur = start;
	fringe.push_front(cur);
	while(true){
		cur = fringe.front();
		for (list<State>::iterator it = fringe.begin(); it != fringe.end(); ++it) {
			if((*it) < cur ){
				cur = (*it);
			}
		}
		if(cur.is_goal()){
			runtime = ((clock() * 1000) / CLOCKS_PER_SEC) - timer;
			cout << "Space= " << space << "\n";
			cout << "Cost= " << cur.g << "\n";
			cout << "Path:\n";
			PrintPath(&cur);
			return;
		}
		else{
			Expand();
		}
	}
}

/*Recursive Best-First Search (RBFS)*/
bool RBFS(State s, int bound){
	State initial = s;
	State best, alter, temp;
	int best_f = 0, alter_f;
	bool result = 1;
	int arr[4] = {0};
	list< State > exp;
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (initial.A[i][j] == 0) {
				if (i > 0) {
					temp = initial;
					swap(temp.A[i][j], temp.A[i - 1][j]);
					temp.g += 1;
					temp.Heurs();
					temp.t = temp.g + temp.h;
					exp.push_front(temp);
					space++;
					arr[0] = temp.t;
				}
				if (i < n-1) {
					temp = initial;
					temp.parent = &(closed.back());
					swap(temp.A[i][j], temp.A[i + 1][j]);
					temp.g += 1;
					temp.Heurs();
					temp.t = temp.g + temp.h;
					exp.push_front(temp);
					space++;
					arr[1] = temp.t;
				}
				if (j > 0) {
					temp = initial;
					temp.parent = &(closed.back());
					swap(temp.A[i][j], temp.A[i][j - 1]);
					temp.g += 1;
					temp.Heurs();
					temp.t = temp.g + temp.h;
					exp.push_front(temp);
					space++;
					arr[2] = temp.t;
				}
				if (j < n-1) {
					temp = initial;
					temp.parent = &(closed.back());
					swap(temp.A[i][j], temp.A[i][j + 1]);
					temp.g += 1;
					temp.Heurs();
					temp.t = temp.g + temp.h;
					exp.push_front(temp);
					space++;
					arr[3] = temp.t;
				}
			}
		}
	}
	sort(arr, arr+4);
	best_f = arr[0];
	alter_f = arr[1];

	for(list<State>::iterator it = exp.begin(); it != exp.end(); it++){
		if(arr[0] == (*it).t){
			best = (*it);
			exp.erase(it);
			break;
		}
	}

	for(list<State>::iterator it = exp.begin(); it != exp.end(); ++it){
		if(arr[1] == (*it).t){
			alter = (*it);
			exp.erase(it);
			break;
		}
	}

	if(best.is_goal()){


			//PrintPath(&best);
			cost++;
			cout << "Space= " << space << "\n";
			cout << "Cost= " << cost << "\n";
			cout << "Path:\n";
			best.print();
			initial.print();
			return true;
    }

	while(true){
		if(best.t > bound){
			return false;
		}
		result = RBFS( best, min(bound, alter.t));
		if(result){


			//PrintPath(&best);
			cost++;
			cout << "Space= " << space << "\n";
			cout << "Cost= " << cost << "\n";
			cout << "Path:\n";
			best.print();
			initial.print();
			return true;
		}
		if(!result){
			alter.t = best.t;
			temp = best;
			best = alter;
			alter = temp;
		}
	}
}

void Expand(){
	closed.push_back(cur);
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(cur.A[i][j] == 0) {
				if(i>0){
					temp = cur;
					temp.parent = &(closed.back());
					swap(temp.A[i][j], temp.A[i - 1][j]);
					if (!InClosed(temp)) {
						temp.g += 1;
						temp.Heurs();
						temp.t = temp.g + temp.h;
						fringe.push_front(temp);
						space++;
					}
				}
				if(i<n-1){
					temp = cur;
					temp.parent = &(closed.back());
					swap(temp.A[i][j], temp.A[i + 1][j]);
					if (!InClosed(temp)) {
						temp.g += 1;
						temp.Heurs();
						temp.t = temp.g + temp.h;
						fringe.push_front(temp);
						space++;
					}
				}
				if(j>0){
					temp = cur;
					temp.parent = &(closed.back());
					swap(temp.A[i][j], temp.A[i][j - 1]);
					if (!InClosed(temp)) {
						temp.g += 1;
						temp.Heurs();
						temp.t = temp.g + temp.h;
						fringe.push_front(temp);
						space++;
					}
				}
				if(j<n-1){
					temp = cur;
					temp.parent = &(closed.back());
					swap(temp.A[i][j], temp.A[i][j + 1]);
					if (!InClosed(temp)) {
						temp.g += 1;
						temp.Heurs();
						temp.t = temp.g + temp.h;
						fringe.push_front(temp);
						space++;
					}
				}
			}
		}
	}
	fringe.remove(cur);
}

void PrintPath(State *s) {
	if(s != NULL){
		(*s).print();
		PrintPath((*s).parent);
	}
}

bool InClosed(State &s){
	for (list<State>::iterator it = closed.begin(); it != closed.end(); ++it) {
		if((*it) == s) {
			return true;
		}
	}
	return false;
}
