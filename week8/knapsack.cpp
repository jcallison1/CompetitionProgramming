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

// struct Result {
// 	pair<int, int> prev;
// 	int index;
// 	int max_value;
// 	bool on;
// };

struct LinkEntry {
	pair<int, int> prev;
	int index;
};

struct SearchState {
	vector<Thing>& things;
	map<pair<int, int>, int>& cache;
	map<pair<int, int>, LinkEntry>& chain;
	// pair<int, int> chain_start;
};

int search(SearchState& state, int index, int weight_remaining) {
	auto cache_key = pair(index, weight_remaining);
	
	if (weight_remaining <= 0 || index >= state.things.size()) {
		state.chain[cache_key] = {{-1, -1}, -1};
		return 0;
	}
	
	auto cache_entry = state.cache.find(cache_key);
	
	if (cache_entry != state.cache.end())
		return (*cache_entry).second;
	
	
	// Result result;
	// result.index = index;
	
	// auto without = search(cache, things, index + 1, weight_remaining);
	
	// if (things[index].weight > weight_remaining) {
	// 	auto without = search(cache, things, index + 1, weight_remaining);
	// }
	// auto without = search(cache, things, index + 1, weight_remaining);
	// auto with = search(cache, things, index + 1, weight_remaining - things[index].weight);
	// with.max_value += things[index].value;
	
	// if (with.max_value > without.max_value) {
	// 	result.max_value = with.max_value;
	// 	result.prev = with.current;
	// 	result.on = true;
	// } else {
	// 	result.max_value = without.max_value;
	// 	result.prev = without.current;
	// 	result.on = false;
	// }
	
	auto w = state.things[index].weight;
	
	auto without = search(state, index + 1, weight_remaining);
	auto with = w > weight_remaining ? 0 : search(state, index + 1, weight_remaining - w) + state.things[index].value;
	
	auto result = max(with, without);
	
	if (result == with) {
		state.chain[cache_key] = LinkEntry {{index + 1, weight_remaining - w}, index};
		// state.chain_start = cache_key;
	} else {
		state.chain[cache_key] = state.chain[{index + 1, weight_remaining}];
	}
	
	state.cache[cache_key] = result;
	
	return result;
}

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
		
		map<pair<int, int>, int> cache;
		map<pair<int, int>, LinkEntry> chain;
		
		// chain[0] = {-1, -1};
		
		SearchState state = {
			things,
			cache,
			chain,
			// {-1, -1}
		};
		
		auto max = search(state, 0, cap);
		vector<int> steps;
		
		// cerr << max << endl;
		
		auto current = chain[{0, cap}];
		
		// while (current.max_value > 0) {
		// 	if (current.on)
		// 		steps.push_back(current.current.first);
			
		// 	current = cache[current.prev];
		// }
		
		while (current.index != -1) {
			// cerr << current.index << endl;
			steps.push_back(current.index);
			current = chain[current.prev];
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