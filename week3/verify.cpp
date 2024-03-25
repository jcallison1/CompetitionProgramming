#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int count;
	cin >> count;
	
	vector<tuple<int, int>> coords;
	
	for (int test = 0; test < count; test++) {
		int x, y;
		cin >> x >> y;
		
		coords.push_back({ x, y });
	}
	
	bool bad = false;
	
	for (auto a : coords) {
		if (bad) break;
		
		for (auto b : coords) {
			if (get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b)) continue;
			
			if (
				get<0>(a) == get<0>(b) ||
				get<1>(a) == get<1>(b) ||
				(abs(get<0>(a) - get<0>(b)) == abs(get<1>(a) - get<1>(b)))
			) {
				bad = true;
				break;
			}
		}
	}
	
	cout << (bad ? "INCORRECT" : "CORRECT") << endl;
	
	return 0;
}