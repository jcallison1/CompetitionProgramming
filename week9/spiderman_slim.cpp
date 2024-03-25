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
#include <climits>

using namespace std;

#define lint long long int

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
		
		vector<vector<TableEntry>> table(dist_count + 1, vector<TableEntry>(dist_sum + 2, {INT_MAX, 0}));
		
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
		
		// for (auto row : table) {
		// 	for (auto x : row) {
		// 		if (x.best_height == INT_MAX)
		// 			cerr << "  .";
		// 		else
		// 			cerr << setw(3) << x.best_height;
		// 	}
			
		// 	cerr << endl;
		// }
		
		if (table[dist_count][0].best_height == INT_MAX) {
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
	}
	
	return 0;
}