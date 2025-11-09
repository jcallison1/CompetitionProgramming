// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <unordered_set>
#include <sstream>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <queue>
#include <climits>
#include <cassert>

using namespace std;

#define lint long long int

struct Guards {
	uint32_t value;
	int size;
	
	Guards(string s) : Guards() {
		int i = 0;
		
		for (auto c : s) {
			if (c == 'F') set_guard(i, 0);
			if (c == 'L') set_guard(i, 1);
			if (c == 'R') set_guard(i, 2);
			
			i++;
		}
		
		size = s.size();
	}
	
	Guards() : value(0) {}
	
	int get_guard(int i) {
		return (value >> (i * 2)) & 3;
	}
	
	void set_guard(int i, int v) {
		value &= ~(3 << (i * 2));
		value |= v << (i * 2);
	}
};

bool dostuff(Guards guards, set<uint32_t>& dead_ends, int players) {
	// cerr << guards.value << endl;
	
	if (players <= 0) return true;
	
	// if (dead_ends.find(guards.value) != dead_ends.end()) return false;
		
	bool has_path = false;
	
	for (int i = 1; i < guards.size; i++) {
		int left_guard = guards.get_guard(i - 1);
		int right_guard = guards.get_guard(i);
		
		if (left_guard == 0 || left_guard == 1) {
			if (right_guard == 0 || right_guard == 2) {
				has_path = true;
				
				auto new_guards = guards;
				new_guards.set_guard(i - 1, 2);
				new_guards.set_guard(i, 1);
				
				if (dostuff(new_guards, dead_ends, players - 1)) return true;
			}
		}
	}
	
	if (!has_path) dead_ends.insert(guards.value);
	
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int guards_, players;
	cin >> guards_ >> players;
	
	string guards_line;
	cin >> guards_line;
	
	Guards guards(guards_line);
	
	set<uint32_t> dead_ends;
	
	bool answer = dostuff(guards, dead_ends, players);
	
	cout << (answer ? 1 : 0) << endl;
	
	return 0;
}