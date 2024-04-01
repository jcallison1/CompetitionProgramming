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
	vector<int> edges;
	
	int dist;
	bool visited;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int movies, horror_count, edges;
	cin >> movies >> horror_count >> edges;
	
	vector<Node> graph(movies, { vector<int>(), INT_MAX, false });
	vector<int> horror_nodes;
	
	for (int i = 0; i < horror_count; i++) {
		int horror_id;
		cin >> horror_id;
		
		horror_nodes.push_back(horror_id);
	}
	
	for (int i = 0; i < edges; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		
		graph[node1].edges.push_back(node2);
		graph[node2].edges.push_back(node1);
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
	
	for (int horror_id : horror_nodes) {
		graph[horror_id].dist = 0;
		queue.push({ 0, horror_id });
	}
	
	while (!queue.empty()) {
		auto [best_dist, node_id] = queue.top();
		queue.pop();
		
		auto& node = graph[node_id];
		
		if (node.visited) continue;
		node.visited = true;
		
		int new_dist = node.dist + 1;
		
		for (int other_id : node.edges) {
			auto& other = graph[other_id];
			
			if (new_dist < other.dist) {
				other.dist = new_dist;
				queue.push({ new_dist, other_id });
			}
		}
	}
	
	int biggest_dist = 0;
	int biggest_node = 0;
	
	for (int i = 0; i < movies; i++) {
		int dist = graph[i].dist;
		
		if (dist > biggest_dist) {
			biggest_dist = dist;
			biggest_node = i;
		}
	}
	
	cout << biggest_node << endl;
	
	return 0;
}