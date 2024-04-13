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

struct NeighborSet {
	unsigned int bitset = 0;
	
	void insert(int n) {
		bitset |= (1 << (n - 1));
	}
	
	NeighborSet union_set(NeighborSet other) {
		return { bitset | other.bitset };
	}
	
	int missing_element() {
		int r = -1;
		
		for (int i = 0; i < 9; i++) {
			if ((bitset & (1 << i)) == 0) {
				if (r != -1) return 0;
				r = i;
			}
		}
		
		return r + 1;
	}
	
	void debug_print() {
		for (int i = 0; i < 9; i++) {
			if ((bitset & (1 << i)) != 0) {
				cerr << (i + 1);
			} else {
				cerr << "_";
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	vector<vector<int>> grid(9, vector<int>(9, 0));
	vector<pair<int, int>> unknowns;
	
	vector<NeighborSet> row_sets(9, NeighborSet());
	vector<NeighborSet> col_sets(9, NeighborSet());
	vector<NeighborSet> block_sets(9, NeighborSet());
	
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			int n;
			cin >> n;
			
			grid[r][c] = n;
			
			if (n == 0) {
				unknowns.push_back({r, c});
			} else {
				row_sets[r].insert(n);
				col_sets[c].insert(n);
				block_sets[r / 3 * 3 + c / 3].insert(n);
			}
		}
	}
	
	// for (auto set : block_sets) {
	// 	set.debug_print();
	// 	cerr << endl;
	// }
	
	vector<pair<int, int>> next_unknowns;
	
	while (true) {
		for (auto pos : unknowns) {
			auto [r, c] = pos;
				
			// col_sets[c].debug_print();
			// cerr << endl;
			
			auto set = row_sets[r]
				.union_set(col_sets[c])
				.union_set(block_sets[r / 3 * 3 + c / 3]);
			
			int missing = set.missing_element();
			
			if (missing != 0) {
				grid[r][c] = missing;
				
				row_sets[r].insert(missing);
				col_sets[c].insert(missing);
				block_sets[r / 3 * 3 + c / 3].insert(missing);
				
				// cerr << "(" << r << ", " << c << ") = " << missing << endl;
			} else {
				next_unknowns.push_back(pos);
			}
		}
		
		if (unknowns.size() == next_unknowns.size()) {
			break;
		}
		
		swap(unknowns, next_unknowns);
		next_unknowns.clear();
	}
	
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			if (c != 0) cout << " ";
			cout << grid[r][c];
		}
		
		cout << endl;
	}
	
	return 0;
}