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
	
	Guards(string s) : Guards() {
		int i = 0;
		
		for (auto c : s) {
			if (c == 'F') set_guard(i, 0);
			if (c == 'L') set_guard(i, 1);
			if (c == 'R') set_guard(i, 2);
			
			i++;
		}
	}
	
	Guards() : value(0) {}
	
	int get_guard(int i) {
		return (value << (i * 2)) & 3;
	}
	
	void set_guard(int i, int v) {
		value &= ~(3 << (i * 2));
		value |= v << (i * 2);
	}
};

int dostuff(Guards guards, map<Guards, bool> j) {
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int guards, players;
	cin >> guards >> players;
	
	string guards_line;
	cin >> guards_line;
	
	Guards guards(guards_line);
	
	
	
	return 0;
}