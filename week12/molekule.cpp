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
	
	int color;
};
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int nodes;

	cin >> nodes;
	
	vector<Node> graph(nodes, { vector<int>(), -1 });
	vector<pair<int, int>> all_edges;
	
	for (int i = 0; i < nodes - 1 ; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		
		node1--;
		node2--;
		
		graph[node1].edges.push_back(node2);
		graph[node2].edges.push_back(node1);
		
		all_edges.push_back({ node1, node2 });
	}
	
	graph[0].color = 0;
	
	queue<int> queue;
	queue.push(0);
	
	while (!queue.empty()) {
		int node = queue.front();
		queue.pop();
		
		for(auto other : graph[node].edges) {
			if (graph[other].color == -1) {
				graph[other].color = 1 - graph[node].color;
				queue.push(other);
			}
		}
	}
	
	for (auto edge : all_edges) {
		cout << (graph[edge.first].color) << endl;
	}
	
	return 0;
}