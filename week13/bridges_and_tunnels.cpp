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
	
	DisjointSets sets(9999999);
	map<string, int> mapping;
	int next_set_id = 0;
	
	int edges;
	cin >> edges;
	
	for (int i = 0; i < edges; i++) {
		string a, b;
		cin >> a >> b;
		
		int a_id, b_id;
		
		if (mapping.find(a) == mapping.end()) {
			a_id = next_set_id++;
			mapping[a] = a_id;
		} else {
			a_id = mapping[a];
		}
		
		if (mapping.find(b) == mapping.end()) {
			b_id = next_set_id++;
			mapping[b] = b_id;
		} else {
			b_id = mapping[b];
		}
		
		sets.join(a_id, b_id);
		
		cout << sets.size(a_id) << endl;
	}
	
	return 0;
}