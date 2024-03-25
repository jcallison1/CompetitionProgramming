#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <sstream>
#include <numeric>
#include <cassert>

using namespace std;

#define lint long long int

struct Point {
	int x;
	int y;
};

bool operator<(const Point& a, const Point& b) {
	return a.x != b.x ? a.x < b.x : a.y < b.y;
}

// struct Move {
// 	int car;
// 	int from_x;
// 	int from_y;
// 	int to_x;
// 	int to_y;
// };

// bool operator<(const Move& a, const Move& b) {
// 	if (a.from_x != b.from_x) return a.from_x < b.from_x;
// 	if (a.from_y != b.from_y) return a.from_y < b.from_y;
	
// 	if (a.to_x != b.to_x) return a.to_x < b.to_x;
// 	if (a.to_y != b.to_y) return a.to_y < b.to_y;
	
// 	return a.car < b.car;
// }

struct SearchState {
	vector<vector<int>>& grid;
	set<Point>& past_moves;
	// set<lint>& past_boards;
	vector<int>& path;
	vector<vector<int>>& found_paths;
	Point target_space;
	int width;
	int height;
};

array<Point, 4> DIRS = {{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
}};

// unsigned int int_hash(unsigned int x) {
//     x = ((x >> 16) ^ x) * 0x45d9f3b;
//     x = ((x >> 16) ^ x) * 0x45d9f3b;
//     x = (x >> 16) ^ x;
//     return x;
// }

// inline lint cell_hash(int car, Point p) {
// 	return int_hash(car) ^ int_hash(p.x) ^ int_hash(p.y);
// }

void search(SearchState& state, Point empty_space, int depth, lint board_hash) {
	assert(state.grid[empty_space.y][empty_space.x] == -1);
	
	if (empty_space.x == state.target_space.x && empty_space.y == state.target_space.y) {
		vector<int> path(state.path);
		state.found_paths.push_back(path);
		return;
	}
	
	// cerr << empty_space.x << " " << empty_space.y << endl;
	
	for (auto search_dir : DIRS) {
		Point cell1 = {empty_space.x + search_dir.x, empty_space.y + search_dir.y};
		Point cell2 = {empty_space.x + search_dir.x * 2, empty_space.y + search_dir.y * 2};
		
		if (!(0 <= cell2.x && cell2.x < state.width && 0 <= cell2.y && cell2.y < state.height)) continue;
		
		int car1 = state.grid[cell1.y][cell1.x];
		int car2 = state.grid[cell2.y][cell2.x];
		
		if (car1 != car2 || car1 < 0 || car2 < 0) continue;
		
		// Move move = {
		// 	car1,
		// 	min(cell1.x, cell2.x),
		// 	min(cell1.y, cell2.y),
		// 	min(cell1.x, empty_space.x),
		// 	min(cell1.y, empty_space.y),
		// };
		
		// lint new_board_hash = board_hash;
		// new_board_hash -= cell_hash(-1, empty_space);
		// new_board_hash -= cell_hash(car1, cell2);
		
		// new_board_hash += cell_hash(car1, empty_space);
		// new_board_hash += cell_hash(-1, cell2);
		
		// cerr << "Move " << cell2.x << " " << cell2.y << " Old Hash: " << board_hash << " New Hash: " << new_board_hash << endl;
		
		if (state.past_moves.find(cell2) != state.past_moves.end()) continue;
		// if (state.past_boards.find(new_board_hash) != state.past_boards.end()) continue;
		
		state.path.push_back(car1);
		state.past_moves.insert(cell2);
		// state.past_boards.insert(new_board_hash);
		
		swap(state.grid[empty_space.y][empty_space.x], state.grid[cell2.y][cell2.x]);
		
		search(state, cell2, depth + 1, board_hash);
		
		swap(state.grid[empty_space.y][empty_space.x], state.grid[cell2.y][cell2.x]);
		
		// state.past_boards.erase(new_board_hash);
		state.past_moves.erase(cell2);
		state.path.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
		
	int width, height;
	cin >> height >> width;
	
	vector<vector<int>> grid(height, vector(width, 0));
	
	Point empty_space = {0, 0};
	
	// lint board_hash = 0;
	
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int v;
			cin >> v;
			
			grid[y][x] = v;
			// board_hash += cell_hash(v, {x, y});
			
			if (v == -1) {
				empty_space = {x, y};
			}
		}
	}
	
	Point target_space;
	cin >> target_space.y >> target_space.x;
	target_space.x--;
	target_space.y--;
	
	// int last_car_to_move = grid[target_space.y][target_space.x];
	
	// vector<vector<int>> grid_copy = grid;
	
	set<Point> past_moves;
	// set<lint> past_boards;
	vector<int> path;
	vector<vector<int>> found_paths;
	
	// past_boards.insert(board_hash);
	
	SearchState params = {
		grid,
		past_moves,
		// past_boards,
		path,
		found_paths,
		target_space,
		width,
		height
	};
	
	search(params, empty_space, 0, 0);
	
	assert(path.empty());
	// assert(grid == grid_copy);
	
	if (params.found_paths.empty()) {
		cout << "impossible" << endl;
	} else {
		// assert(params.found_paths.size() == 1);
		
		sort(params.found_paths.begin(), params.found_paths.end(), [](auto a, auto b) {
			if (a.size() != b.size()) return a.size() < b.size();
			
			for (int i = 0; i < a.size(); i++) {
				if (a[i] != b[i]) return a[i] < b[i];
			}
			
			return false;
		});
		
		auto path = params.found_paths[0];
		bool first = true;
		
		// assert(path.back() == last_car_to_move);
		
		for (auto car : path) {
			if (!first) cout << " ";
			cout << car;
			first = false;
		}
		
		cout << endl;
	}
	
	return 0;
}