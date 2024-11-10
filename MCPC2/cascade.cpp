// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

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

double dfs(vector<vector<int>>& graph, vector<bool>& hit, int source, double degree_product) {
	double g = 0.0;
	
	for (int other_vert : graph[source]) {
		if (hit[other_vert]) continue;
		
		hit[other_vert] = true;
		g += dfs(graph, hit, other_vert, degree_product * graph[source].size());
		
		g += 1.0 / (degree_product * graph[source].size());
	}
	
	return g;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int vertexes;
	cin >> vertexes;
	
	if (vertexes == 1) {
		cout << 1 << endl;
		return 0;
	}
	
	int edges = vertexes - 1;
	
	vector<vector<int>> graph(vertexes, vector<int>());
	
	for (int i = 0; i < edges; i++) {
		int a, b;
		cin >> a >> b;
		
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}
	
	double sum = 0.0;
	
	for (int source = 0; source < vertexes; source++) {
		vector<bool> hit(vertexes, false);
		hit[source] = true;
		
		double centrallity = 1 + dfs(graph, hit, source, 1.0);
		sum += centrallity;
	}
	
	cout << setprecision(30) << (sum / vertexes) << endl;
	
	return 0;
}