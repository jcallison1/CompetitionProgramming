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

struct SlowResult {
	int path_length;
	int prev_element;
};

vector<SlowResult> cache;

SlowResult slowest(vector<int>& heights, int n) {
	if (cache[n].path_length != -1) return cache[n];
	
	SlowResult result = {1, -1};
	
	if (n != 0) {
		int max = 0;
		
		for (int i = 0; i < n; i++) {
			if (heights[i] > heights[n]) {
				auto r = slowest(heights, i);
				r.path_length++;
				
				if (max < r.path_length) {
					max = r.path_length;
					result.path_length = max;
					result.prev_element = i;
					
					// cout << r.path_length << endl;
				}
			}
		}
	}
	
	cache[n] = result;
	// cout << result.path_length << endl;
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	vector<int> heights;
	
	while (cin) {
		int h;
		cin >> h;
		if (!cin) break;
		
		heights.push_back(h);
	}
	
	// cout << heights.size() << endl;
	
	for (int i = 0; i < (int) heights.size(); i++) {
		cache.push_back({ -1, -1 });
	}
	
	SlowResult best = { 0, -1 };
	int first = 0;
	
	for (int i = 0; i < (int) heights.size(); i++) {
		auto r = slowest(heights, i);
		// cout << r.path_length << endl;
		
		if (r.path_length > best.path_length) {
			best = r;
			first = i;
		}
	}
	
	// cout << best.path_length << endl;
	
	vector<int> the_path;
	
	auto current = best;
	
	// cout << heights[first];
	the_path.push_back(heights[first]);
	
	while (current.prev_element != -1) {
		// cout << " " << heights[current.prev_element];
		the_path.push_back(heights[current.prev_element]);
		current = cache[current.prev_element];
	}
	
	bool o = false;
	
	for (auto i = the_path.rbegin(); i != the_path.rend(); i++) {
		if (o) cout << " ";
		cout << *i;
		o = true;
	}
	
	cout << endl;
	
	return 0;
}