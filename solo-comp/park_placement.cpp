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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int rows, cols, good_count;
	cin >> rows >> cols >> good_count;
	
	unordered_set<int> good_tiles;
	
	for (int i = 0; i < good_count; i++) {
		int x;
		cin >> x;
		good_tiles.insert(x);
	}
	
	vector<vector<int>> sum_grid(rows, vector<int>(cols + 1, 0));
	
	for (int r = 0; r < rows; r++) {
		int row_sum = 0;
		
		for (int c = 0; c < cols; c++) {
			int x;
			cin >> x;
			
			row_sum += (good_tiles.find(x) == good_tiles.end() ? 0 : 1);
			sum_grid[r][c + 1] = row_sum;
		}
	}
	
	int best_size = 0;
	
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			for (int k = c + 1; k <= cols; k++) {
				int length = k - c;
				bool is_square = true;
				
				if (r + length > rows) continue;
				
				for (int i = r; i < r + length; i++) {
					if (sum_grid[i][k] - sum_grid[i][c] != length) {
						is_square = false;
						break;
					}
				}
				
				if (is_square) {
					best_size = max(best_size, length);
				} else {
					break;
				}
			}
		}
	}
	
	cout << best_size*best_size << endl;
	
	return 0;
}