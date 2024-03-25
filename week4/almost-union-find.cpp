#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <deque>
#include <sstream>
#include <numeric>

using namespace std;

class DisjointSets {
public:
	vector<int> parent;
	vector<int> rank;
	vector<int> sizes;
	vector<int> sums;
	
	long set_count = 0;
	
	DisjointSets(int capacity) {
		parent.assign(capacity, 0);
		iota(parent.begin(), parent.end(), 0);
		
		rank.assign(capacity, 0);
		sizes.assign(capacity, 1);
		
		sums.assign(capacity, 0);
		iota(sums.begin(), sums.end(), 0);
		
		set_count = capacity;
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
		sums[b_set] += sums[a_set];
		
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
	
	while (true) {
		int n, lines;
		cin >> n >> lines;
		
		if (!cin) break;
		
		DisjointSets disjoint_set(n + 1);
		vector<int> mapping;
		
		mapping.assign(n + 1, 0);
		iota(mapping.begin(), mapping.end(), 0);
		
		for (int i = 0; i < lines; i++) {
			int op;
			int a, b;
			cin >> op >> a;
			
			if (op == 1) {
				cin >> b;
				
				disjoint_set.join(mapping[a], mapping[b]);
			} else if (op == 2) {
				cin >> b;
				
				int a_set = disjoint_set.find_set(mapping[a]);
				int b_set = disjoint_set.find_set(mapping[b]);
				
				if (a_set == b_set) continue;
				
				mapping[a] = b_set;
				
				disjoint_set.sizes[a_set] -= 1;
				disjoint_set.sums[a_set] -= a;
				
				disjoint_set.sizes[b_set] += 1;
				disjoint_set.sums[b_set] += a;
				
				// if (disjoint_set.sizes[a_set] != 1) {
				// 	int new_a_set = disjoint_set.new_set();
				// 	disjoint_set.sums.push_back(a);
					
				// 	disjoint_set.sizes[a_set] -= 1;
				// 	disjoint_set.sums[a_set] -= a;
					
				// 	mapping[a] = new_a_set;
				// 	disjoint_set.join(new_a_set, b_set);
				// } else {
				// 	disjoint_set.join(a_set, b_set);
				// }
			} else if (op == 3) {
				auto set = disjoint_set.find_set(mapping[a]);
				
				cout << disjoint_set.sizes[set] << " " << disjoint_set.sums[set] << endl;
			}
		}
	}
	
	return 0;
}