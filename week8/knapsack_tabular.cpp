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

struct Thing {
	int weight;
	int value;
};

// struct CacheEntry {
// 	int result;
// 	bool on;
// };

// int search(vector<vector<int>>& cache, vector<Thing>& things, int index, int weight_remaining) {
// 	if (weight_remaining <= 0 || index >= things.size()) return 0;
	
// 	if (cache[index][weight_remaining] != -1) return cache[index][weight_remaining];
	
// 	auto t = things[index];
	
// 	auto without = search(cache, things, index + 1, weight_remaining);
// 	auto with = t.weight > weight_remaining ? 0 : search(cache, things, index + 1, weight_remaining - t.weight) + t.value;
	
// 	auto result = max(with, without);
	
// 	cache[index][weight_remaining] = result;
	
// 	return result;
// }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	while (true) {
		int cap, size;
		cin >> cap >> size;
		if (!cin) break;
		
		vector<Thing> things;
		
		for (int i = 0; i < size; i++) {
			int value, weight;
			cin >> value >> weight;
			
			things.push_back({weight, value});
		}
		
		vector<vector<int>> cache(size + 1, vector<int>(cap + 1, 0));
		
		// auto max = search(cache, things, 0, cap);
		
		for (int index = things.size() - 1; index >= 0; index--) {
			for (int weight_remaining = 1; weight_remaining <= cap; weight_remaining++) {
				auto t = things[index];
				
				if (t.weight > weight_remaining) {
					cache[index][weight_remaining] = cache[index + 1][weight_remaining];
				} else {
					cache[index][weight_remaining] = max(
						cache[index + 1][weight_remaining],
						cache[index + 1][weight_remaining - t.weight] + t.value
					);
				}
			}
		}
		
		// for (auto row : cache) {
		// 	for (auto v : row) {
		// 		cerr << setw(3) << v << " ";
		// 	}
			
		// 	cerr << endl;
		// }
		
		// cerr << max << endl;
		
		int weight_remaining = cap;
		vector<int> steps;
		
		for (int index = 0; index < things.size(); index++) {
			auto t = things[index];
			
			if (cache[index][weight_remaining] > cache[index + 1][weight_remaining]) {
				steps.push_back(index);
				weight_remaining -= t.weight;
			}
		}
		
		cout << steps.size() << endl;
		
		bool not_first = false;
		
		for (auto i : steps) {
			if (not_first) cout << " ";
			cout << i;
			not_first = true;
		}
		
		cout << endl;
	}
	
	return 0;
}