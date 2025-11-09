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
	
	lint n, k;
	cin >> n >> k;
	
	vector<lint> prev_level;
	vector<lint> next_level;
	
	prev_level.push_back(1);
	// cerr << 1 << endl;
	
	lint mults = 0;
	
	for (int l = 1; l < n; l++) {
		next_level.push_back(1);
		// cerr << 1 << " ";
		
		for (int i = 1; i < l; i++) {
			lint num = prev_level[i - 1] + prev_level[i];
			
			if (num % k == 0) mults++;
			
			next_level.push_back(num);
			// cerr << num << " ";
		}
		
		next_level.push_back(1);
		// cerr << 1 << endl;
		
		swap(prev_level, next_level);
		next_level.clear();
	}
	
	cout << mults << endl;
	
	return 0;
}