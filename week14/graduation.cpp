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

class DisjointSets {
public:
	vector<int> parent;
	vector<int> rank;
	vector<int> sizes;
	
	long set_count = 0;
	
	DisjointSets(int capacity) {
		parent.assign(capacity, 0);
		iota(parent.begin(), parent.end(), 0);
		
		rank.assign(capacity, 0);
		sizes.assign(capacity, 1);
		
		set_count = capacity;
	}
	
	int new_set() {
		auto index = parent.size();
		
		parent.push_back(index);
		rank.push_back(0);
		sizes.push_back(1);
		
		return index;
	}
	
	int find_set(int x) {
		if (parent[x] == x) {
			return x;
		}
		
		auto set = find_set(parent[x]);
		parent[x] = set;
		return set;
	}
	
	void join(int a, int b) {
		int a_set = find_set(a);
		int b_set = find_set(b);
		
		if (a_set == b_set) return; // Same set already
		
		if (rank[a_set] > rank[b_set]) swap(a_set, b_set); // Make b_set be the tallest
		parent[a_set] = b_set;
		
		if (rank[a_set] == rank[b_set]) rank[b_set]++;
		sizes[b_set] += sizes[a_set];
		
		set_count--;
	}
	
	bool same_set(int a, int b) {
		return find_set(a) == find_set(b);
	}
	
	int size(int x) {
		return sizes[find_set(x)];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int rows, columns, classes;
	cin >> rows >> columns >> classes;
	
	DisjointSets sets(classes);
	
	vector<string> grid;
	
	for (int r = 0; r < rows; r++) {
		string line;
		cin >> line;
		
		grid.push_back(line);
	}
		
	for (int c = 0; c < columns; c++) {
		int root_class_id = (int) (grid[0][c] - 'A');
		
		for (int r = 0; r < rows; r++) {
			int class_id = (int) (grid[r][c] - 'A');
			
			sets.join(root_class_id, class_id);
		}
	}
	
	cout << sets.set_count << endl;
	
	return 0;
}