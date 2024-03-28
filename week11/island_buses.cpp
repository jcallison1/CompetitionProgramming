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

using Pos = pair<int, int>;

struct Tile {
	char tile_type;
	int island_id;
	bool part_of_bridge;
};

template<class F> void floodfill(vector<vector<Tile>>& grid, int start_x, int start_y, F callback) {
	int width = grid[0].size();
	int height = grid.size();
	
	queue<Pos> queue;
	queue.push({ start_x, start_y });
	
	while (!queue.empty()) {
		auto pos = queue.front();
		queue.pop();
		
		auto [x, y] = pos;
		
		if (0 <= x && x < width && 0 <= y && y < height) {
			auto& tile = grid[y][x];
			
			if (!callback(x, y, tile)) continue;
			
			queue.push({ x - 1, y });
			queue.push({ x + 1, y });
			queue.push({ x, y - 1 });
			queue.push({ x, y + 1 });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int map_num = 1;
	
	while (cin) {
		vector<vector<Tile>> grid;
		
		string line;
		
		while (cin) {
			getline(cin, line);
			if (!cin || line.empty()) break;
			
			vector<Tile> row;
			
			for (auto c : line) {
				row.push_back({ c, -1, false });
			}
			
			grid.push_back(row);
		}
		
		int width = grid[0].size();
		int height = grid.size();
		
		// cerr << map.size() << endl;
		
		int island_count = 0;
		
		for (int seed_y = 0; seed_y < height; seed_y++) {
			for (int seed_x = 0; seed_x < width; seed_x++) {
				auto& seed_tile = grid[seed_y][seed_x];
				
				if (seed_tile.island_id == -1 && (seed_tile.tile_type == '#' || seed_tile.tile_type == 'X')) {
					int new_island_id = island_count;
					
					island_count++;
					
					floodfill(grid, seed_x, seed_y, [&](int x, int y, Tile& tile) {
						if (tile.island_id != -1) return false;
						if (tile.tile_type != '#' && tile.tile_type != 'X') return false;
						
						tile.island_id = new_island_id;
						
						return true;
					});
				}
			}
		}
		
		vector<vector<int>> graph(island_count);
		int bridge_count = 0;
		
		for (int seed_y = 0; seed_y < height; seed_y++) {
			for (int seed_x = 0; seed_x < width; seed_x++) {
				auto& seed_tile = grid[seed_y][seed_x];
				
				if (!seed_tile.part_of_bridge && seed_tile.tile_type == 'B') {
					int island1 = -1;
					int island2 = -1;
					
					bridge_count++;
					
					floodfill(grid, seed_x, seed_y, [&](int x, int y, Tile& tile) {
						if (tile.tile_type == 'X') {
							if (island1 == -1) {
								island1 = tile.island_id;
							} else {
								island2 = tile.island_id;
							}
							
							return false;
						}
						
						if (tile.part_of_bridge || tile.tile_type != 'B') return false;
						
						tile.part_of_bridge = true;
						
						return true;
					});
					
					assert(island1 != -1 && island2 != -1);
					
					graph[island1].push_back(island2);
					graph[island2].push_back(island1);
				}
			}
		}
		
		vector<bool> visited(island_count, false);
		int connected_comps = 0;
		
		for (int starting_node = 0; starting_node < island_count; starting_node++) {
			if (!visited[starting_node]) {
				connected_comps++;
				
				queue<int> queue;
				queue.push(starting_node);
				
				while(!queue.empty()) {
					int node = queue.front();
					queue.pop();
					
					if (visited[node]) continue;
					visited[node] = true;
					
					for (int other : graph[node]) {
						if (!visited[other]) queue.push(other);
					}
				}
			}
		}
		
		cout << "Map " << map_num << endl;
		cout << "islands: " << island_count << endl;
		cout << "bridges: " << bridge_count << endl;
		cout << "buses needed: " << connected_comps << endl;
		
		// for (int y = 0; y < height; y++) {
		// 	for (int x = 0; x < width; x++) {
		// 		cerr << setw(3);
				
		// 		if (grid[y][x].part_of_bridge)
		// 			cerr << 'B';
		// 		else if (grid[y][x].island_id == -1)
		// 			cerr << '.';
		// 		else
		// 			cerr << grid[y][x].island_id;
		// 	}
			
		// 	cerr << endl;
		// }
		
		cout << endl;
		
		map_num++;
	}
	
	return 0;
}