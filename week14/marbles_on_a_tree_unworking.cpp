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

struct Node {
	int marbles;
	vector<int> edges;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	while (true) {
		int node_count;
		cin >> node_count;
		
		if (node_count == 0) break;
		
		vector<Node> graph(node_count, { 0, vector<int>() });
		queue<int> empty_slots;
		
		for (int i = 0; i < node_count; i++) {
			int ignore, marbles, edge_count;
			cin >> ignore >> marbles >> edge_count;
			
			graph[i].marbles = marbles;
			
			if (marbles == 0) {
				empty_slots.push(i);
			}
			
			for (int j = 0; j < edge_count; j++) {
				int other;
				cin >> other;
				
				other--;
				
				graph[i].edges.push_back(other);
				graph[other].edges.push_back(i);
			}
		}
		
		int steps = 0;
		
		while (!empty_slots.empty()) {
			int node_id = empty_slots.front();
			empty_slots.pop();
			
			auto& node = graph[node_id];
			if (node.marbles != 0) continue;
			
			cerr << "dsa " << node.edges.size();
			
			int best_other_id = -1;
			int best_marbles = 0;
			
			for (int other_id : node.edges) {
				int other_marbles = graph[other_id].marbles;
				
				if (other_marbles > best_marbles) {
					best_other_id = other_id;
					best_marbles = other_marbles;
				}
			}
			
			if (best_marbles == 0) {
				empty_slots.push(node_id);
			} else {
				auto& other = graph[best_other_id];
				
				other.marbles--;
				node.marbles++;
				steps++;
				
				if (other.marbles == 0) {
					empty_slots.push(best_other_id);
				}
			}
		}
		
		cout << steps << endl;
	}
	
	return 0;
}