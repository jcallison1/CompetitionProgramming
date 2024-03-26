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
	
	int test_cases;
	cin >> test_cases;
	
	for (int i = 0; i < test_cases; i++) {
		int nodes, edges;
		cin >> nodes >> edges;
		
		for (int i = 0; i < edges; i++) {
			int a, b;
			cin >> a >> b;
		}
		
		// All minimum spanning trees of a graph with n vertexes will have n - 1 edges.
		int mst_edges = nodes - 1;
		
		cout << mst_edges << endl;
	}
	
	return 0;
}