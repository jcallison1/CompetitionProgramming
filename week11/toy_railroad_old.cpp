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
	int a = -1;
	int b = -1;
	int c = -1;
	
	bool visited_merge = false;
	int best_dist_merge = INT_MAX;
	
	bool visited_split = false;
	int best_dist_split = INT_MAX;
		
	void make_link(char link, int other_node) {
		if (link == 'A') {
			a = other_node;
		} else if (link == 'B') {
			b = other_node;
		} else if (link == 'C') {
			c = other_node;
		}
	}
	
	bool& visited(int incoming) {
		return incoming == a ? visited_split : visited_merge;
	}
	
	int& best_dist(int incoming) {
		return incoming == a ? best_dist_split : best_dist_merge;
	}
	
	template<class F> void for_each_edge(int incoming, F callback) {
		if (incoming == a) {
			callback(b);
			callback(c);
		} else {
			callback(a);
		}
	}
};

struct ToDoEntry {
	int node;
	int prev;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int nodes, edges;
	cin >> nodes >> edges;
	
	vector<Node> graph(nodes, Node());
	
	for (int i = 0; i < edges; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		
		char type1 = s1[s1.length() - 1];
		char type2 = s2[s2.length() - 1];
		
		int inter1 = stoi(s1.substr(0, s1.length() - 1)) - 1;
		int inter2 = stoi(s2.substr(0, s2.length() - 1)) - 1;
		
		graph[inter1].make_link(type1, inter2);
		graph[inter2].make_link(type2, inter1);
	}
	
	graph[0].a = -2; // -2 is the fake starting node
	
	string final_state(nodes, 'B');
	queue<ToDoEntry> to_do;
	
	to_do.push({ 0, -2 });
	
	while (!to_do.empty()) {
		auto [ current_id, prev_id ] = to_do.front();
		to_do.pop();
		
		if (current_id < 0) continue;
		
		auto& current_node = graph[current_id];
		
		if (current_node.visited(prev_id)) continue;
		current_node.visited(prev_id) = true;
		
		int new_dist = current_node.best_dist(prev_id) + 1;
		
		current_node.for_each_edge(prev_id, [&](int other_id) {
			auto& other_node = graph[other_id];
			
			if (new_dist < other_node.best_dist(current_id)) {
				other_node.best_dist(current_id) = new_dist;
				to_do.push({ other_id, current_id });
				
				if (other_id == current_node.b) {
					final_state[current_id] = 'B';
				} else if (other_id == current_node.c) {
					final_state[current_id] = 'C';
				}
			}
		});
	}
	
	cout << final_state << endl;
	
	return 0;
}