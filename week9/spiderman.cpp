#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <sstream>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <queue>

using namespace std;

#define lint long long int

#define BIG 999999999

// int search(vector<vector<int>>& cache, vector<int>& dists, int index, int street_dist) {
// 	if (street_dist < 0) return BIG;
	
// 	if (cache[index][street_dist] != -1) return cache[index][street_dist];
	
// 	if (index >= dists.size())
// 		return cache[index][street_dist] = street_dist != 0 ? BIG : 0;
	
// 	// int highest = max(
// 	// 	max(
// 	// 		search(cache, dists, index + 1, street_dist + dists[index]),
// 	// 		search(cache, dists, index + 1, street_dist - dists[index])
// 	// 	),
// 	// 	street_dist
// 	// );
	
// 	int highest = min(
// 		search(cache, dists, index + 1, street_dist + dists[index]),
// 		search(cache, dists, index + 1, street_dist - dists[index])
// 	) + street_dist;
	
// 	cache[index][street_dist] = highest;
// 	return highest;
// }

// void reconstruct_path(vector<vector<int>>& cache, vector<int>& dists) {
// 	if (cache[cache.size() - 1][0] == -1) {
// 		cout << "IMPOSSIBLE" << endl;
// 		return;
// 	}
	
// 	string path;
// 	int street_dist = 0;
	
// 	for (int index = cache.size() - 1; index > 0; index--) {
// 		auto& row = cache[index - 1];
		
// 		int down_index = street_dist - dists[index - 1];
// 		int up_index = street_dist + dists[index - 1];
		
// 		int down_h = (0 <= down_index && down_index < row.size()) ? row[down_index] : BIG;
// 		int up_h = (0 <= up_index && up_index < row.size()) ? row[up_index] : BIG;
		
// 		// cerr << down_index << " " << up_index << endl;
// 		// cerr << down_h << " " << up_h << endl;
		
// 		if (down_h == -1) down_h = BIG;
// 		if (up_h == -1) up_h = BIG;
		
// 		if (down_h < up_h) {
// 			path.push_back('U');
// 			street_dist = down_index;
// 		} else {
// 			path.push_back('D');
// 			street_dist = up_index;
// 		}
// 	}
	
// 	reverse(path.begin(), path.end());
	
// 	cout << path << endl;
// }

// void reconstruct_path2(vector<vector<int>>& cache, vector<int>& dists) {
// 	if (cache[0][0] >= BIG) {
// 		cout << "IMPOSSIBLE" << endl;
// 		return;
// 	}
	
// 	string path;
// 	int street_dist = 0;
	
// 	for (int index = 1; index < cache.size(); index++) {
// 		auto& row = cache[index];
		
// 		int down_index = street_dist - dists[index - 1];
// 		int up_index = street_dist + dists[index - 1];
		
// 		int down_h = (0 <= down_index && down_index < row.size()) ? row[down_index] : BIG;
// 		int up_h = (0 <= up_index && up_index < row.size()) ? row[up_index] : BIG;
		
// 		if (down_h == -1) down_h = BIG;
// 		if (up_h == -1) up_h = BIG;
		
// 		if (down_h < up_h) {
// 			path.push_back('D');
// 			street_dist = down_index;
// 		} else {
// 			path.push_back('U');
// 			street_dist = up_index;
// 		}
// 	}
	
// 	cout << path << endl;
// }

struct TableEntry {
	int best_height;
	int direction;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int test_cases;
	cin >> test_cases;
	
	for (int test_case = 0; test_case < test_cases; test_case++) {
		int dist_count;
		cin >> dist_count;
		
		vector<int> dists;
		int dist_sum = 0;
		
		for (int i = 0; i < dist_count; i++) {
			int dist;
			cin >> dist;
			dists.push_back(dist);
			dist_sum += dist;
		}
		
		// vector<vector<int>> cache(dist_count + 1, vector<int>(dist_sum + 2, 999999999));
		
		vector<vector<TableEntry>> table(dist_count + 1, vector<TableEntry>(dist_sum + 2, {BIG, 0}));
		
		table[0][0] = {0, 1};
		
		for (int index = 0; index < dist_count; index++) {
			for (int dist = 0; dist <= dist_sum; dist++) {
				int down_dist = dist - dists[index];
				int up_dist = dist + dists[index];
				int next_index = index + 1;
				
				int best_down_dist = table[index][dist].best_height;
				int best_up_dist = max(best_down_dist, up_dist);
				
				if (down_dist >= 0 && table[next_index][down_dist].best_height > best_down_dist) {
					table[next_index][down_dist] = {best_down_dist, -1};
				}
				
				if (up_dist <= dist_sum + 1 && table[next_index][up_dist].best_height > best_up_dist) {
					table[next_index][up_dist] = {best_up_dist, 1};
				}
			}
		}
		
		// for (int index = 1; index <= dist_count; index++) {
		// 	for (int height = 0; height <= dist_sum; height++) {
		// 		int down_height = height - dists[index - 1];
		// 		int up_height = height + dists[index - 1];
		// 		int prev_index = index - 1;
				
		// 		TableEntry result = {BIG, 0};
				
		// 		if (down_height >= 0 && table[prev_index][down_height].best_height < result.best_height) {
		// 			result = {table[prev_index][down_height].best_height, 1};
		// 		}
				
		// 		if (up_height <= dist_sum && table[prev_index][up_height].best_height < result.best_height) {
		// 			int new_height = max(table[prev_index][up_height].best_height, height);
		// 			result = {new_height, -1};
		// 		}
				
		// 		table[index][height] = result;
		// 	}
		// }
		
		for (auto row : table) {
			for (auto x : row) {
				if (x.best_height == BIG)
					cerr << "  .";
				else
					cerr << setw(3) << x.best_height;
			}
			
			cerr << endl;
		}
		
		if (table[dist_count][0].best_height == BIG) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		
		string path;
		int current_dist = 0;
		
		for (int index = dist_count; index > 0; index--) {
			auto dir = table[index][current_dist].direction;
			
			path.push_back(dir > 0 ? 'U' : 'D');
			
			current_dist -= dir * dists[index - 1];
		}
		
		reverse(path.begin(), path.end());
		
		cout << path << endl;
		
		// search(cache, dists, 0, 0);
		
		// for (auto row : cache) {
		// 	for (auto x : row) {
		// 		if (x == -1)
		// 			cerr << "  .";
		// 		else
		// 			cerr << setw(3) << x;
		// 	}
			
		// 	cerr << endl;
		// }
		
		// reconstruct_path2(cache, dists);
	}
	
	return 0;
}