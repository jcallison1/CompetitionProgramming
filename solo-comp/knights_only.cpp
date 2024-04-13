#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

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

pair<int, int> offsets[] = {
	{-2, -1},
	{-2, 1},
	{2, -1},
	{2, 1},
	{-1, -2},
	{1, -2},
	{-1, 2},
	{1, 2}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	vector<string> grid;
	vector<pair<int, int>> knights;
	
	for (int r = 0; r < 8; r++) {
		string row;
		
		for (int c = 0; c < 8; c++) {
			char ch;
			cin >> ch;
			
			row.push_back(ch);
			
			if (ch == 'o') {
				knights.push_back({r, c});
			}
		}
		
		grid.push_back(row);
	}
	
	int captures = 0;
	
	for (auto [this_r, this_c] : knights) {
		for (auto [dr, dc] : offsets) {
			int r = this_r + dr;
			int c = this_c + dc;
			
			if (0 <= r && r < 8 && 0 <= c && c < 8 && grid[r][c] == 'x') {
				grid[r][c] = '.';
				captures++;
			}
		}
	}
	
	cout << captures << endl;
	
	return 0;
}