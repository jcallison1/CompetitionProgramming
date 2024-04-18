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
	
	int breaks, price;
	cin >> breaks >> price;
	
	vector<int> all_watching;
	
	for (int i = 0; i < breaks; i++) {
		int x;
		cin >> x;
		all_watching.push_back(x);
	}
	
	lint best_sum = -9999999999;
	lint current_sum = 0;
	
	for (int watching : all_watching) {
		current_sum += watching - price;
		
		if (current_sum > best_sum) {
			best_sum = current_sum;
		}
		
		if (current_sum < 0) {
			current_sum = 0;
		}
	}
	
	cout << best_sum << endl;
	
	return 0;
}