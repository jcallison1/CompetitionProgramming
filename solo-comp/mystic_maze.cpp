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

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct NodeState {
	int best_dist;
	bool visited;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int rows, cols;
	cin >> rows >> cols;
	
	vector<string> grid;
	
	for (int r = 0; r < rows; r++) {
		string row;
		
		for (int c = 0; c < cols; c++) {
			char ch;
			cin >> ch;
			row.push_back(ch);
		}
		
		grid.push_back(row);
	}
	
	vector<vector<NodeState>> states(rows, vector<NodeState>(cols, { INT_MAX, false }));
	queue<pair<int, int>> to_do;
	
	states[0][0].best_dist = 1;
	to_do.push({0, 0});
	
	while (!to_do.empty()) {
		auto [this_r, this_c] = to_do.front();
		to_do.pop();
		
		auto& this_state = states[this_r][this_c];
		this_state.visited = true;
		
		for (int i = 0; i < 4; i++) {
			int r = this_r + dr[i];
			int c = this_c + dc[i];
			
			if (0 <= r && r < rows && 0 <= c && c < cols && grid[r][c] == 'O') {
				auto& other_state = states[r][c];
				
				if (this_state.best_dist + 1 < other_state.best_dist) {
					other_state.best_dist = this_state.best_dist + 1;
					to_do.push({r, c});
				}
			}
		}
	}
	
	// for (int r = 0; r < rows; r++) {
	// 	for (int c = 0; c < cols; c++) {
	// 		cerr << grid[r][c];
	// 	}
		
	// 	cerr << endl;
	// }
	
	int best_dist = states[rows - 1][cols - 1].best_dist;
	
	cout << (best_dist == INT_MAX ? 0 : best_dist) << endl;
	
	return 0;
}