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

bool search(map<int, bool>& cache, vector<int>& base_angles, int current_angle) {
	if (current_angle >= 360) current_angle = current_angle % 360;
	if (current_angle < 0) current_angle = 360 - abs(current_angle) % 360;
	
	if (cache.find(current_angle) != cache.end()) return cache[current_angle];
	
	// if (current_angle < 0 || current_angle > 360) return false;
	if (current_angle == 0) return true;
	
	// cout << current_angle << endl;
	
	bool result = false;
	cache[current_angle] = false;
	
	for (auto angle : base_angles) {
		result |= search(cache, base_angles, current_angle - angle);
		result |= search(cache, base_angles, current_angle + angle);
	}
	
	cache[current_angle] = result;
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int intial_count, want_count;
	cin >> intial_count >> want_count;
	
	vector<int> base_angles;
	
	for (int i = 0; i < intial_count; i++) {
		int k;
		cin >> k;
		base_angles.push_back(k);
	}
	
	for (int i = 0; i < want_count; i++) {
		int angle;
		cin >> angle;
		
		map<int, bool> cache;
		bool good = search(cache, base_angles, angle);
		
		cout << (good ? "YES" : "NO") << endl;
	}
	
	return 0;
}