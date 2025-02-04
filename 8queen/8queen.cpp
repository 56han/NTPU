#include <iostream>
#include <list> 
#include <algorithm> 
#include <ctime> 

using namespace std;
const int n = 8; 
bool random_start = false;
bool generate_start = true; 
bool ids = false;
bool astar = false;
bool gbfs = false;
bool ucs = false;
bool rbfs = false;

class State {
public:
	int A[n][n], g, h, t; //State array, General Cost, Heuristic Cost, and Total Cost
	int pos, limit; //Position, and limit 
	State *parent; //Parent Pointer
	State(); //Constructor
	void reset(); //reset
	bool is_goal(); //true: state is goal.
					//false: state is not goal
	bool operator==(const State &) const; //Logical Equality Operator
	bool operator<(const State &) const; //Logical Less-Than Operator
	void print(); //State Array Printing function
};

int space = 1;
int runtime = 1;
int timer = 0;
int pos_i = 0, pos_j = 0;
list< State > closed, fringe, res, prin; 
State start, now, temp; 
void IDS(); 
int RBFS(int problem, State now, int f_limit);
list<State> RBFS_expand(State now);
void Expand(); 
void hur(State &s); 
void PrintPath(State *s); 
int min(int a, int b); 

State::State() {
	reset();
}

void State::reset() {
	int i, j;
	g = h = t = pos = limit = 0;
	parent = NULL;
	if (generate_start) {
		cout << "initial state" << endl;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				A[i][j] = 0;
			}
		}
		cout << "H:";
		cin >> pos_i;
		cout << "W:";
		cin >> pos_j;
		A[pos_i][pos_j] = 1;
		generate_start = false;
	}
}

bool State::is_goal() {
	if (now.g == n && now.h == 0)
		return true;
	else
		return false;
}

bool rbfs_check(State &s) {
	if (s.g == n && s.h == 0)
		return true;
	else
		return false;
}

void State::print() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			cout << A[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

bool State::operator==(const State &r) const {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (A[i][j] != r.A[i][j])
				return false;
		}
	}
	return true;
}

bool State::operator<(const State &r) const {
	if (rbfs||astar) {
		return t < r.t;
	}
	else if (ucs || ids) {
		return (n - g) < (n - r.g);
	}
	else if (gbfs) {
		return h < r.h;
	}
}

/*A* search*/
void Astar() {
	cout << "Starting A* Algorithm... \n";
	now = start;
	fringe.push_front(now);
	while (true) {
		now = fringe.front();
		for (list<State>::iterator it = fringe.begin(); it != fringe.end(); ++it) {
			if ((*it) < now) { 
				now = (*it);
			}
		}
		if (now.is_goal()) {
			runtime = ((clock()) / CLOCKS_PER_SEC) - timer;
			cout << "Time= " << runtime << "\n";
			cout << "Space= " << space << "\n";
			PrintPath(&now);
			cout << "Path:\n";
			for (list<State>::reverse_iterator it = prin.rbegin(); it != prin.rend(); ++it) {
				(*it).print();
			}
			return;
		}
		else {
			Expand();
		}
	}
}

/*Iterative-Deepening Search*/
void IDS() {
	int depth = 0; 
	cout << "Starting IDS Algorithm... \n";
	while (true) {
		now = start;
		fringe.push_front(now);
		while (!fringe.empty())
		{
			now = fringe.front();
			if (now.is_goal()) {
				runtime = ((clock()) / CLOCKS_PER_SEC) - timer;
				cout << "Time= " << runtime << "\n";
				cout << "Space= " << space << "\n";
				PrintPath(&now);
				cout << "Depth=" << depth << "\n";
				cout << "Path:\n";
				for (list<State>::reverse_iterator it = prin.rbegin(); it != prin.rend(); ++it) {
					(*it).print();
				}
				return;
			}
			else if (depth > now.g) {
				Expand();
			}
			else { 
				fringe.pop_front();
			}
		}
		fringe.clear();
		closed.clear();
		cout << "depth:   " << depth << endl;
		depth++;
	}
}

/*Greedy Best-First Search*/
void GBFS() {
	cout << "Starting GBFS Algorithm... \n";
	now = start;
	fringe.push_front(now);
	while (true) {
		now = fringe.front();
		for (list<State>::iterator it = fringe.begin(); it != fringe.end(); ++it) {
			if ((*it) < now) {  
				now = (*it);
			}
		}
		if (now.is_goal()) {		
			runtime = ((clock()) / CLOCKS_PER_SEC) - timer;
			cout << "Time= " << runtime << "\n";
			cout << "Space= " << space << "\n";
			PrintPath(&now);
			cout << "Path:\n";
			for (list<State>::reverse_iterator it = prin.rbegin(); it != prin.rend(); ++it) {
				(*it).print();
			}
			return;
		}
		else {
			Expand();
		}
	}
}

/*Uniform-Cost Search*/
void UCS() {
	cout << "Starting UCS Algorithm... \n";
	now = start;
	fringe.push_front(now);
	while (true) {
		now = fringe.front();
		for (list<State>::iterator it = fringe.begin(); it != fringe.end(); ++it) {
			if ((*it) < now) {  
				now = (*it);
			}
		}
		if (now.is_goal()) {
			runtime = ((clock()) / CLOCKS_PER_SEC) - timer;
			cout << "Time= " << runtime << "\n";
			cout << "Space= " << space << "\n";
			PrintPath(&now);
			cout << "Path:\n";
			for (list<State>::reverse_iterator it = prin.rbegin(); it != prin.rend(); ++it) {
				(*it).print();
			}
			return;
		}
		else {
			Expand();
		}
	}
}

/*Recursive Best-First Search*/
int RBFS(int problem, State now, int f_limit) {
	list < State > frontier;
	State best;
	while (problem) {
		if (rbfs_check(now)) {
			runtime = ((clock()) / CLOCKS_PER_SEC) - timer;
			cout << "Time= " << runtime << "\n";
			cout << "Space= " << space << "\n";
			PrintPath(&now);
			cout << "Path:\n";
			for (list<State>::reverse_iterator it = prin.rbegin(); it != prin.rend(); ++it) {
				(*it).print();
			}
			problem = 0;
		}
		if (problem) {
            if(now.g==n &&now.h!=0){
                return 100000;
            }
			if (frontier.size() == 0)
				frontier = RBFS_expand(now);
			best = frontier.front();
			if (frontier.size() > 1) {
				for (list<State>::iterator it = frontier.begin(); it != frontier.end(); ++it) {
					if ((*it) < best) {
						best = (*it);
					}
				}
			}
			frontier.remove(best);
			State alt = frontier.front();
			if (frontier.size() != 0) {
				for (list<State>::iterator it = frontier.begin(); it != frontier.end(); ++it) {
					if ((*it)< alt) {
						alt = (*it);
					}
				}
			}
			f_limit = min(f_limit, alt.t);
			if (best.t > f_limit) {
				closed.clear();
				return best.t;
			}
			else { 
				best.t = RBFS(1, best, f_limit);
				frontier.push_back(best);
				f_limit = now.limit;
				if (best.t == -1)
					problem = 0;
			}
		}
	}
	return -1;
}



void Expand() {
	closed.push_back(now);
	int  j;
	if ((n - now.g) > 0) {
		if (now.pos == n - 1) {
			for (j = 0; j < n; j++) {
				temp = now;
				if (temp.A[0][j] == 0) {
					temp.parent = &(closed.back());
					temp.g += 1;
					temp.A[0][j] = temp.g;
					hur(temp);
					temp.t = temp.g + temp.h;
					temp.pos = 0;
					fringe.push_front(temp); 
				}
			}
		}
		else {
			for (j = 0; j < n; j++) {
				temp = now;
				if (temp.A[temp.pos + 1][j] == 0) {
					temp.parent = &(closed.back());
					temp.g += 1;
					temp.A[temp.pos + 1][j] = temp.g;
					hur(temp);
					temp.t = temp.g + temp.h;
					temp.pos += 1;
					fringe.push_front(temp); 
				}
			}
		}
	}
	
	fringe.remove(now);
	if (fringe.size() > space)
		space = fringe.size();
}

void hur(State &s) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s.A[i][j] != 0) {
				for (int x = 0; x < n; x++) {
					if (x != j && s.A[i][x] != 0) {
						s.h++;
					}
					if (x != i && s.A[x][j] != 0) {
						s.h++;
					}
				}
				for (int y = 1; (i - y) >= 0 && (j - y) >= 0; y++) {
					if (s.A[i - y][j - y] != 0) {
						s.h++;
					}
				}
				for (int y = 1; (i + y) < n && (j - y) >= 0; y++) {
					if (s.A[i + y][j - y] != 0) {
						s.h++;
					}
				}
				for (int y = 1; (i - y) >= 0 && (j + y) < n; y++) {
					if (s.A[i - y][j + y] != 0) {
						s.h++;
					}
				}
				for (int y = 1; (i + y) < n && (j + y) < n; y++) {
					if (s.A[i + y][j + y] != 0) {
						s.h++;
					}
				}
			}
		}
	}
	s.h = s.h / 2;
}

void PrintPath(State *s) {
	if (s != NULL) {
		prin.push_back(*s);
		PrintPath((*s).parent);
	}
}

int min(int a, int b) {
	if (a > b)
		return b;
	else return a;
}

list<State> RBFS_expand(State now) {
	list<State> frontier;
	res.push_back(now);

	int  j;
	if ((n - now.g) > 0) {
		if (now.pos == n - 1) {
			for (j = 0; j < n; j++) {
				temp = now;
				if (temp.A[0][j] == 0) {
					temp.parent = &(res.back());
					temp.g += 1;
					temp.A[0][j] = temp.g;
					hur(temp);
					temp.t = temp.g + temp.h;
					temp.pos = 0;
					frontier.push_front(temp); 
				}
			}
		}
		else {
			for (j = 0; j < n; j++) {
				temp = now;
				if (temp.A[temp.pos + 1][j] == 0) {
					temp.parent = &(res.back());
					temp.g += 1;
					temp.A[temp.pos + 1][j] = temp.g;
					hur(temp);
					temp.t = temp.g + temp.h;
					temp.pos += 1;
					frontier.push_front(temp); 
				}
			}
		}
	}
	frontier.remove(now);
	if (frontier.size() > space)
		space = frontier.size();
	return frontier;
}

int main() {
	int choose = 0;
	start.g = 1;
	start.pos = pos_i;
	start.limit = 10000;
	hur(start); 
	start.t = start.g + start.h; 
	start.parent = NULL; 
	timer = (clock()) / CLOCKS_PER_SEC;
	cout << "1: A*"<<endl<<"2: IDS"<<endl<<"3: GBFS"<<endl<<"4: UCS"<<endl<<"5: RBFS"<< endl;
	cin >> choose;
	while(choose!=-1){
		if (choose == 1) {
		astar = true;
		Astar();
		}
		else if (choose == 2) {
			ids = true;
			IDS(); 
		}
		else if (choose == 3) {
			gbfs = true;
			GBFS();
		}
		else if (choose == 4) {
			ucs = true;
			UCS();
		}
		else if (choose == 5) {
			rbfs = true;
			cout << "Starting RBFS Algorithm... \n";
			RBFS(1, start, 10000);
		}
		cin >> choose;
	}
	
	system("PAUSE");
	return 0;
}
