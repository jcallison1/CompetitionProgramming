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

using Pos = pair<int, int>;

void do_test_case() {
	int width, height;
	cin >> width >> height;
	
	vector<string> grid;
	
	for (int y = 0; y < height; y++) {
		string line;
		cin >> line;
		
		grid.push_back(line);
	}
	
	queue<Pos> fire_incoming;
	queue<Pos> fire_outgoing;
	
	queue<Pos> player_incoming;
	queue<Pos> player_outgoing;
	
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			auto& c = grid[y][x];
			
			if (c == '*') {
				fire_incoming.push({ x, y });
			} else if (c == '@') {
				player_incoming.push({ x, y });
				c = '.';
			}
		}
	}
	
	// cerr << player_incoming.size() << " " << fire_incoming.size() << endl;
	
	vector<vector<bool>> player_visited(height, vector<bool>(width, false));
	
	int steps = 0;
	bool reached_edge = false;
	
	auto player_explore = [&](int x, int y) {
		if (0 <= x && x < width && 0 <= y && y < height) {
			if (!player_visited[y][x] && grid[y][x] == '.') {
				player_outgoing.push({ x, y });
			}
		} else {
			reached_edge = true;
		}
	};
	
	auto fire_explore = [&](int x, int y) {
		if (0 <= x && x < width && 0 <= y && y < height) {
			if (grid[y][x] == '.') {
				fire_outgoing.push({ x, y });
			}
		}
	};
	
	while (true) {
		if (reached_edge || player_incoming.empty()) break;
		
		while (!fire_incoming.empty()) {
			auto pos = fire_incoming.front();
			fire_incoming.pop();
			
			auto [x, y] = pos;
			
			grid[y][x] = '*';
			
			fire_explore(x - 1, y);
			fire_explore(x + 1, y);
			fire_explore(x, y - 1);
			fire_explore(x, y + 1);
		}
		
		while (!player_incoming.empty()) {
			auto pos = player_incoming.front();
			player_incoming.pop();
			
			auto [x, y] = pos;
			
			if (grid[y][x] != '.') continue;
			
			player_visited[y][x] = true;
			
			player_explore(x - 1, y);
			player_explore(x + 1, y);
			player_explore(x, y - 1);
			player_explore(x, y + 1);
		}
		
		swap(player_incoming, player_outgoing);
		swap(fire_incoming, fire_outgoing);
		
		steps++;
		
		// for (int y = 0; y < height; y++) {
		// 	for (int x = 0; x < width; x++) {
		// 		cerr << grid[y][x];
		// 	}
			
		// 	cerr << endl;
		// }
		
		// cerr << endl;
	}
	
	// cerr << steps << endl;
	
	if (reached_edge) {
		cout << steps << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int test_cases;
	cin >> test_cases;
	
	for (int i = 0; i < test_cases; i++) {
		do_test_case();
	}
	
	return 0;
}