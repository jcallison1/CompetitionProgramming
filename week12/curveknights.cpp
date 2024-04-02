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
	lint amount;
};

struct Node {
	vector<Edge> edges;
	int incoming_edges;
	
	lint needed;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int node_count, edge_count;
	cin >> node_count >> edge_count;
	
	vector<Node> graph(node_count, { vector<Edge>(), 0, 0 });
	
	for (int i = 0; i < node_count; i++) {
		int needed;
		cin >> needed;
		
		graph[i].needed = needed;
	}
	
	for (int i = 0; i < edge_count; i++) {
		int from, to, amount;
		cin >> to >> from >> amount;
		
		graph[from].edges.push_back({ to, amount });
		graph[to].incoming_edges++;
	}
	
	vector<int> to_do;
	
	for (int i = 0; i < node_count; i++) {
		if (graph[i].incoming_edges == 0) {
			to_do.push_back(i);
		}
	}
	
	while (!to_do.empty()) {
		int node_id = to_do.back();
		to_do.pop_back();
		
		auto& node = graph[node_id];
		
		for (auto edge : node.edges) {
			auto& other = graph[edge.to];
			
			other.needed += node.needed * edge.amount;
			other.incoming_edges--;
			
			if (other.incoming_edges == 0) {
				to_do.push_back(edge.to);
			}
		}
	}
	
	bool first = true;
	
	for (auto& node : graph) {
		if (!first) cout << " ";
		cout << node.needed;
		
		first = false;
	}
	
	cout << endl;
	
	return 0;
}