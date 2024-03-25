#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string moves;
	cin >> moves;
	
	int cursor = 0;
	string respond = "";
	
	while (cursor < moves.size()) {
		bool r = false;
		bool b = false;
		bool l = false;
		
		for (int i = 0; i < 3; i++) {
			char move = moves[cursor + i];
			if (move == 'R') r = true;
			if (move == 'B') b = true;
			if (move == 'L') l = true;
		}
		
		if (r && b && l) {
			cursor += 3;
			respond.push_back('C');
		} else {
			char move = moves[cursor];
			
			if (move == 'R') respond.push_back('S');
			if (move == 'B') respond.push_back('K');
			if (move == 'L') respond.push_back('H');
			
			cursor += 1;
		}
	}
	
	cout << respond << endl;
	
	return 0;
}