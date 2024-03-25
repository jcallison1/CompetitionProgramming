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

using namespace std;

#define lint long long int

struct Point {
	int x;
	int y;
};

#define WIDTH 9
#define HEIGHT 5

bool operator<(const Point& a, const Point& b) {
	return a.x != b.x ? a.x < b.x : a.y < b.y;
}

struct State {
	vector<vector<bool>>& board;
	int peg_count;
	int min_peg_count;
	int min_moves;
	// set<Point>& pegs;
};

array<Point, 4> DIRS = {{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
}};

void search(State& state, int depth) {
	if (state.peg_count < state.min_peg_count) {
		state.min_peg_count = state.peg_count;
		state.min_moves = depth;
	}
	
	if (state.peg_count == state.min_peg_count && depth < state.min_moves) {
		state.min_moves = depth;
	}
	
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (state.board[y][x]) {
				for (auto search_dir : DIRS) {
					Point cell1 = {x + search_dir.x, y + search_dir.y};
					Point cell2 = {x + search_dir.x * 2, y + search_dir.y * 2};
					
					if (!(0 <= cell2.x && cell2.x < WIDTH && 0 <= cell2.y && cell2.y < HEIGHT)) continue;
					if ((cell2.y == 0 || cell2.y == HEIGHT - 1) && (cell2.x < 3 || cell2.x > 5)) continue;
					
					if (state.board[cell1.y][cell1.x] && !state.board[cell2.y][cell2.x]) {
						state.board[cell1.y][cell1.x] = false;
						state.board[y][x] = false;
						state.board[cell2.y][cell2.x] = true;
						state.peg_count--;
						
						search(state, depth + 1);
						
						state.peg_count++;
						state.board[cell1.y][cell1.x] = true;
						state.board[y][x] = true;
						state.board[cell2.y][cell2.x] = false;
					}
				}
			}
		}
	}
	
	// for (auto peg : state.pegs) {
	// 	for (auto search_dir : DIRS) {
	// 		Point cell1 = {peg.x + search_dir.x, peg.y + search_dir.y};
	// 		Point cell2 = {peg.x + search_dir.x * 2, peg.y + search_dir.y * 2};
			
	// 		if (!(0 <= cell2.x && cell2.x < WIDTH && 0 <= cell2.y && cell2.y < HEIGHT)) continue;
			
	// 		if (state.pegs.find(cell1) != state.pegs.end() && state.pegs.find(cell2) == state.pegs.end()) {
				
	// 		}
	// 	}
	// }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int cases = 0;
	cin >> cases;
		
	for (int q = 0; q < cases; q++) {
		vector<vector<bool>> board(HEIGHT, vector(WIDTH, false));
		int peg_count = 0;
		// set<Point> pegs;
		
		for (int y = 0; y < HEIGHT; y++) {
			string line;
			cin >> line;
			
			for (int x = 0; x < WIDTH; x++) {
				if (line[x] == 'o') {
					board[y][x] = true;
					peg_count++;
					// pegs.insert({x, y});
				}
			}
		}
		
		State state = {
			board,
			peg_count,
			99999999,
			99999999
		};
		
		search(state, 0);
		
		cout << state.min_peg_count << " " << state.min_moves << endl;
	}
	
	return 0;
}