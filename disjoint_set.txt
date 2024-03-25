#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

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
