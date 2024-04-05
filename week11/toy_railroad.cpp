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
	int out1 = -1;
	int out2 = -1;
	
	bool visited = false;
	int best_dist = INT_MAX;
	int prev = -1;
		
	template<class F> void for_each_edge(F callback) {
		callback(out1);
		callback(out2);
	}
};

void form_link(vector<Node>& graph, char from_type, int from_id, char to_type, int to_id) {
	int from_split = from_id * 2;
	int to_split = to_id * 2;
	int from_merge = from_id * 2 + 1;
	int to_merge = to_id * 2 + 1;
	
	int dest = to_type == 'A' ? to_split : to_merge;
	
	if (from_type == 'A') {
		graph[from_merge].out1 = dest;
	} else if (from_type == 'B') {
		graph[from_split].out1 = dest;
	} else if (from_type == 'C') {
		graph[from_split].out2 = dest;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int nodes, edges;
	cin >> nodes >> edges;
	
	// Even nodes are split, odd are merge
	vector<Node> graph(nodes * 2, Node());
	
	for (int i = 0; i < edges; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		
		char type1 = s1[s1.length() - 1];
		char type2 = s2[s2.length() - 1];
		
		int inter1 = stoi(s1.substr(0, s1.length() - 1)) - 1;
		int inter2 = stoi(s2.substr(0, s2.length() - 1)) - 1;
		
		form_link(graph, type1, inter1, type2, inter2);
		form_link(graph, type2, inter2, type1, inter1);
	}
	
	queue<int> to_do;
	
	graph[0].best_dist = 0;
	to_do.push(0);
	
	int final_dist = INT_MAX;
	int final_prev = -1;
	
	while (!to_do.empty()) {
		auto current_id = to_do.front();
		to_do.pop();
		
		// Reached the end
		if (current_id == -2) break;
		
		auto& current_node = graph[current_id];
		
		if (current_node.visited) continue;
		current_node.visited = true;
		
		int new_dist = current_node.best_dist + 1;
		
		current_node.for_each_edge([&](int other_id) {
			if (other_id == -1) return;
			
			auto& other_node = graph[other_id];
			
			if (new_dist < other_node.best_dist) {
				other_node.best_dist = new_dist;
				other_node.prev = current_id;
				
				to_do.push(other_id);
			}
			
			// Made its way back to the start
			if (other_id == 0 && new_dist < final_dist) {
				final_dist = new_dist;
				final_prev = current_id;
				
				to_do.push(-2);
			}
		});
	}
	
	if (final_prev == -1) {
		cout << "Impossible" << endl;
		return 0;
	}
	
	string final_state(nodes, 'B');
	
	int next = 0;
	int current = final_prev;
	
	while (current != -1) {
		auto& node = graph[current];
		
		// Check if split node
		if (current % 2 == 0) {
			final_state[current / 2] = node.out1 == next ? 'B' : 'C';
		}
		
		next = current;
		current = node.prev;
	}
	
	cout << final_state << endl;
	// cerr << final_dist << endl;
	
	return 0;
}