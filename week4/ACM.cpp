#include <iostream>
#include <map>
#include <unordered_set>
#include <string>
#include <tuple>
#include <vector>
#include <set>
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
	
	long set_count = 0;
	
	DisjointSets(int capacity) {
		parent.assign(capacity, 0);
		iota(parent.begin(), parent.end(), 0);
		
		rank.assign(capacity, 0);
		sizes.assign(capacity, 1);
		
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
	
	int recipes;
	cin >> recipes;
	
	DisjointSets disjoint_set(500001);
	
	int potions = 0;
	
	for (int i = 0; i < recipes; i++) {
		int ing_count;
		cin >> ing_count;
		
		set<int> temp_set;
		
		for (int j = 0; j < ing_count; j++) {
			int ing;
			cin >> ing;
			
			temp_set.insert(disjoint_set.find_set(ing));
		}
		
		int sum = 0;
		
		for (auto set : temp_set) {
			sum += disjoint_set.size(set);
		}
		
		if (ing_count == sum) {
			auto iter = temp_set.begin();
			int root = *iter;
			
			for (auto set : temp_set) {
				disjoint_set.join(root, set);
			}
			
			potions++;
		}
	}
	
	cout << potions << endl;
	
	return 0;
}