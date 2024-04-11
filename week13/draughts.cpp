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

int search(vector<string>& grid, int x, int y) {
	auto check = [&](int x_offset, int y_offset) {
		int near_x = x + x_offset;
		int near_y = y + y_offset;
		int far_x = x + x_offset * 2;
		int far_y = y + y_offset * 2;
		
		int result = 0;
		
		if (0 <= far_x && far_x < 10 && 0 <= far_y && far_y < 10) {
			if (grid[near_y][near_x] == 'B' && grid[far_y][far_x] == '#') {
				swap(grid[y][x], grid[far_y][far_x]);
				grid[near_y][near_x] = '#';
				
				result = search(grid, far_x, far_y) + 1;
				
				grid[near_y][near_x] = 'B';
				swap(grid[y][x], grid[far_y][far_x]);
			}
		}
		
		return result;
	};
	
	return max({
		check(-1, -1),
		check(1, -1),
		check(-1, 1),
		check(1, 1)
	});
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int test_cases;
	cin >> test_cases;
	
	for (int test_case = 0; test_case < test_cases; test_case++) {
		vector<string> grid;
		vector<pair<int, int>> starting_poses;
		
		for (int y = 0; y < 10; y++) {
			string row;
			cin >> row;
			
			for (int x = 0; x < 10; x++) {
				if (row[x] == 'W') {
					starting_poses.push_back({x, y});
				}
			}
			
			grid.push_back(row);
		}
		
		int best = 0;
		
		for (auto start_pos : starting_poses) {
			best = max(best, search(grid, start_pos.first, start_pos.second));
		}
		
		cout << best << endl;
	}
	
	return 0;
}