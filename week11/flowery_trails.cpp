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

struct Edge {
	int to;
	int cost;
};

struct VertexState {
	bool visited;
	int best_dist;
	vector<Edge> prev;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int nodes, edges;
	cin >> nodes >> edges;
	
	vector<vector<Edge>> graph(nodes, vector<Edge>());
	
	for (int i = 0; i < edges; i++) {
		int node1, node2, cost;
		cin >> node1 >> node2 >> cost;
		
		graph[node1].push_back({ node2, cost });
		graph[node2].push_back({ node1, cost });
	}
	
	vector<VertexState> states(nodes, { false, INT_MAX, vector<Edge>() });
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
	
	states[0].best_dist = 0;
	queue.push({ 0, 0 });
	
	while (!queue.empty()) {
		auto [best_dist, node] = queue.top();
		queue.pop();
		
		auto& node_state = states[node];
		
		if (node_state.visited) continue;
		node_state.visited = true;
		
		// cerr << "Took off: " << node << " " << best_dist << endl;
		
		if (node == nodes - 1) break;
		
		for (auto& edge : graph[node]) {
			auto& other_state = states[edge.to];
			
			int new_dist = node_state.best_dist + edge.cost;
			
			if (new_dist < other_state.best_dist) {
				other_state.best_dist = new_dist;
				other_state.prev.clear();
				other_state.prev.push_back({ node, edge.cost });
				
				queue.push({ new_dist, edge.to });
				
				// cerr << "Put on: " << edge.to << " " << new_dist << endl;
			} else if (new_dist == other_state.best_dist) {
				other_state.prev.push_back({ node, edge.cost });
			}
		}
	}
	
	// cerr << endl;
	// cerr << states[nodes - 1].prev.size() << endl;
	
	int total_length = 0;
	vector<bool> visited(nodes, false);
	vector<int> next;
	
	next.push_back(nodes - 1);
	
	while (!next.empty()) {
		int node = next.back();
		next.pop_back();
		
		if (visited[node]) continue;
		visited[node] = true;
		
		for (auto& edge : states[node].prev) {
			total_length += edge.cost;
			// cerr << node << " -> " << edge.to << endl;
			
			if (!visited[edge.to]) {
				next.push_back(edge.to);
			}
		}
	}
	
	cout << (total_length * 2) << endl;
	
	return 0;
}