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
	vector<int> debts;
	
	long set_count = 0;
	
	DisjointSets(int capacity) {
		parent.assign(capacity, 0);
		iota(parent.begin(), parent.end(), 0);
		
		rank.assign(capacity, 0);
		// sizes.assign(capacity, 1);
		
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
		debts[b_set] += debts[a_set];
		
		set_count--;
	}
	
	bool same_set(int a, int b) {
		return find_set(a) == find_set(b);
	}
};


int main() {
	int friends, friendships;
	cin >> friends >> friendships;
	
	DisjointSets disjoint_set(friends);
	
	for (int i = 0; i < friends; i++) {
		int num;
		scanf(" %d", &num);
		
		disjoint_set.debts.push_back(num);
	}
	
	for (int i = 0; i < friendships; i++) {
		int a, b;
		scanf(" %d %d", &a, &b);
		
		disjoint_set.join(a, b);
	}
	
	for (int i = 0; i < friends; i++) {
		if (disjoint_set.parent[i] == i && disjoint_set.debts[i] < 0) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}
	
	cout << "POSSIBLE" << endl;
	
	return 0;
}