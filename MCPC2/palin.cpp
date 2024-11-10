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

template <class T>
void find_palin(vector<pair<int, int>>& found, T sample, int length) {
	for (int i = 0; i < length; i++) {
		int left = i;
		int right = i + 2;
		
		while (left >= 0 && right < length && sample(left) == sample(right)) {
			left -= 1;
			right += 1;
		}
		
		left += 1;
		right -= 1;
		
		if (right - left + 1 <= 1) continue;
		
		found.push_back({left, right});
	}
	
	for (int i = 0; i < length; i++) {
		int left = i;
		int right = i + 1;
		
		while (left >= 0 && right < length && sample(left) == sample(right)) {
			left -= 1;
			right += 1;
		}
		
		left += 1;
		right -= 1;
		
		if (right - left + 1 <= 1) continue;
		
		found.push_back({left, right});
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int rows, cols;
	cin >> rows >> cols;
	
	vector<string> grid;
	
	for (int i = 0; i < rows; i++) {
		string s;
		cin >> s;
		
		grid.push_back(s);
	}
		
	vector<vector<pair<int, int>>> col_cache(cols, vector<pair<int, int>>(rows, {-1, -1}));
	vector<pair<int, int>> row_pals;
	
	for (int c = 0; c < cols; c++) {
		row_pals.clear();
		find_palin(row_pals, [&](int i) { return grid[i][c]; }, rows);
		
		auto& thing = col_cache[c];
		
		for (auto& pal : row_pals) {
			int length = pal.second - pal.first + 1;
			
			for (int r = pal.first; r <= pal.second; r++) {
				int u = thing[r].second - thing[r].first + 1;
				
				if (length >= u || thing[r].first == -1) {
					thing[r] = pal;
				}
			}
		}
	}
	
	int best_result = 1;
	
	for (int r = 0; r < rows; r++) {
		row_pals.clear();
		find_palin(row_pals, [&](int i) { return grid[r][i]; }, cols);
		
		for (auto [row_left, row_right] : row_pals) {
			for (int c = row_left; c <= row_right; c++) {
				// auto& pals = col_cache[c];
				
				auto [col_left, col_right] = col_cache[c][r];
				
				if (col_left == -1) continue;
				
				int area = (col_right - col_left + 1) * (row_right - row_left + 1);
						
				best_result = max(best_result, area);
				
				// for (auto& [col_left, col_right] : pals) {
				// 	if (col_left <= r && r <= col_right) {
				// 		int area = (col_right - col_left + 1) * (row_right - row_left + 1);
						
				// 		best_result = max(best_result, area);
				// 	}
				// }
			}
		}
	}
	
	cout << best_result << endl;
	
	return 0;
}