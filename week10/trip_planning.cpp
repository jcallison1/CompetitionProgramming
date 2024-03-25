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

struct Edge {
	int to_city;
	int edge_index;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int nodes, edges;
	cin >> nodes >> edges;
	
	vector<vector<Edge>> graph(nodes, vector<Edge>());
	
	for (int i = 0; i < edges; i++) {
		int city1, city2;
		cin >> city1 >> city2;
		
		city1--;
		city2--;
		
		graph[city1].push_back({ city2, i + 1 });
		graph[city2].push_back({ city1, i + 1 });
	}
	
	vector<int> path;
		
	for (int current_city = 0; current_city < nodes; current_city++) {
		int next_city = (current_city + 1) % nodes;
		
		auto& places = graph[current_city];
		bool found = false;
		
		for (auto& edge : places) {
			if (edge.to_city == next_city) {
				path.push_back(edge.edge_index);
				found = true;
				break;
			}
		}
		
		if (!found) {
			path.clear();
			break;
		}
	}
	
	if (path.empty()) {
		cout << "impossible" << endl;
	} else {
		for (auto edge_index : path) {
			cout << edge_index << endl;
		}
	}
	
	return 0;
}