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

using namespace std;

#define lint long long int

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	while (true) {
		int nodes, edges;
		cin >> nodes >> edges;
		
		if (nodes == 0 && edges == 0) break;
		
		vector<vector<int>> graph(nodes, vector<int>());
		vector<pair<int, int>> all_edges;
		
		for (int i = 0; i < edges; i++) {
			int a, b;
			cin >> a >> b;
			
			all_edges.push_back({a, b});
			
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		bool has_bridge = false;
		
		for (auto& removed_edge : all_edges) {
			vector<bool> visited(nodes, false);
			queue<int> queue;
			int found = 0;
			
			queue.push(0);
			
			while (!queue.empty()) {
				int node_id = queue.front();
				queue.pop();
				
				if (visited[node_id]) continue;
				
				visited[node_id] = true;
				
				for (auto other_node_id : graph[node_id]) {
					if (visited[other_node_id]) continue;
					if ((node_id == removed_edge.first && other_node_id == removed_edge.second)) continue;
					if ((node_id == removed_edge.second && other_node_id == removed_edge.first)) continue;
					
					queue.push(other_node_id);
				}
			}
			
			for (auto k : visited) {
				if (k) found++;
			}
			
			if (found != nodes) {
				has_bridge = true;
				break;
			}
		}
		
		cout << (has_bridge ? "Yes" : "No") << endl;
	}
	
	return 0;
}