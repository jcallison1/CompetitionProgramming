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

using namespace std;

#define lint long long int

void find_sea(vector<vector<bool>>& matrix, set<pair<int, int>>& visited, pair<int, int> start) {
	if (matrix[start.second][start.first] == true) return;
	
	queue<pair<int, int>> queue;
	queue.push(start);
	
	auto check_tile = [&](pair<int, int> pos) {
		if (0 <= pos.first && pos.first < matrix[0].size() && 0 <= pos.second && pos.second < matrix.size()) {
			if (matrix[pos.second][pos.first] == false) {
				queue.push(pos);
			}
		}
	};
	
	while (!queue.empty()) {
		auto pos = queue.front();
		queue.pop();
		
		if (visited.find(pos) != visited.end()) continue;
		visited.insert(pos);
		
		check_tile({ pos.first - 1, pos.second });
		check_tile({ pos.first + 1, pos.second });
		check_tile({ pos.first, pos.second - 1 });
		check_tile({ pos.first, pos.second + 1 });
	}
}

int count_per_land(vector<vector<bool>>& matrix, set<pair<int, int>>& visited, set<pair<int, int>>& sea_tiles, pair<int, int> start) {
	queue<pair<int, int>> queue;
	queue.push(start);
	
	int per = 0;
	
	auto check_tile = [&](pair<int, int> pos) {
		bool inside = 0 <= pos.first && pos.first < matrix[0].size() && 0 <= pos.second && pos.second < matrix.size();
		
		if (!inside || sea_tiles.find(pos) != sea_tiles.end()) {
			per++;
		}
		
		if (inside && matrix[pos.second][pos.first] == true) {
			queue.push(pos);
		}
	};
	
	while (!queue.empty()) {
		auto pos = queue.front();
		queue.pop();
		
		if (visited.find(pos) != visited.end()) continue;
		visited.insert(pos);
		
		check_tile({ pos.first - 1, pos.second });
		check_tile({ pos.first + 1, pos.second });
		check_tile({ pos.first, pos.second - 1 });
		check_tile({ pos.first, pos.second + 1 });
	}
	
	return per;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int width, height;
	
	cin >> height >> width;
	
	vector<vector<bool>> matrix(height, vector<bool>(width, false));
	
	for (int y = 0; y < height; y++) {
		string line;
		cin >> line;
		
		for (int x = 0; x < width; x++) {
			matrix[y][x] = line[x] == '1';
		}
	}
	
	set<pair<int, int>> sea_tiles;
	
	for (int y = 0; y < height; y++) {
		if (y == 0 || y == height - 1) {
			for (int x = 0; x < width; x++) {
				find_sea(matrix, sea_tiles, { x, y });
			}
		} else {
			find_sea(matrix, sea_tiles, { 0, y });
			find_sea(matrix, sea_tiles, { width - 1, y });
		}
	}
	
	set<pair<int, int>> land_tiles;
	
	int total_per = 0;
	
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (matrix[y][x] == true && land_tiles.find({x, y}) == land_tiles.end()) {
				total_per += count_per_land(matrix, land_tiles, sea_tiles, {x, y});
			}
		}
	}
	
	cout << total_per << endl;
	
	// cerr << sea_tiles.size() << endl;
	// cerr << land_tiles.size() << endl;
	
	// for (int y = 0; y < height; y++) {
	// 	for (int x = 0; x < width; x++) {
	// 		cout << (sea_tiles.find({x, y}) != sea_tiles.end() ? 'O' : '.');
	// 		// cout << (matrix[y][x] ? 1 : 0);
	// 	}
		
	// 	cout << endl;
	// }
	
	return 0;
}