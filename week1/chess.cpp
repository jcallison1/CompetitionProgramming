#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		char c_start_x, c_end_x;
		int c_start_y, c_end_y;
		
		cin >> c_start_x >> c_start_y >> c_end_x >> c_end_y;
		
		int start_y = c_start_y - 1;
		int end_y = c_end_y - 1;
		int start_x = 7 - (int) (c_start_x - 'A');
		int end_x = 7 - (int) (c_end_x - 'A');
		
		if ((start_x + start_y) % 2 != (end_x + end_y) % 2) {
			cout << "Impossible" << endl;
			continue;
		}
		
		auto print_pos = [] (int x, int y) {
			cout << char('A' + (char) (7 - x)) << " " << (y + 1);
		};
		
		if (start_x == end_x && start_y == end_y) {
			cout << "0 ";
			print_pos(start_x, start_y);
			cout << endl;
			continue;
		}
		
		int rel_x = end_x - start_x;
		int rel_y = end_y - start_y;
		
		if (abs(rel_x) == abs(rel_y)) {
			cout << "1 ";
			print_pos(start_x, start_y);
			cout << " ";
			print_pos(end_x, end_y);
			cout << endl;
			continue;
		}
		
		auto test = [start_x, start_y, end_x, end_y, &print_pos] (int m) {
			int inter_x = (m * end_x + end_y + m * start_x - start_y) / (2 * m);
			int inter_y = m * inter_x - m * start_x + start_y;
			
			if (0 <= inter_x && inter_x < 8 && 0 <= inter_y && inter_y < 8) {
				cout << "2 ";
				print_pos(start_x, start_y);
				cout << " ";
				print_pos(inter_x, inter_y);
				cout << " ";
				print_pos(end_x, end_y);
				cout << endl;
				
				return true;
			}
			
			return false;
		};
		
		if (test(1)) continue;
		if (test(-1)) continue;
		
		cout << "Impossible" << endl;
	}
	
    return 0;
}