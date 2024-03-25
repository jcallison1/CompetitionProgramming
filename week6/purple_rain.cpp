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

lint max_subarray(string& line, char p, int& start, int& end) {
	lint best_sum = -9999999999;
	lint current_sum = 0;
	
	int current_start = 0;
	int current_end = 0;
	
	for (char c : line) {
		current_sum += (c == p ? 1 : -1);
		// cout << current_sum << endl;
		
		if (current_sum > best_sum) {
			best_sum = current_sum;
			start = current_start;
			end = current_end;
		}
		
		if (current_sum < 0) {
			current_start = current_end + 1;
			current_sum = 0;
		}
		
		current_end++;
	}
	
	return best_sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string line;
	cin >> line;
	cerr << line << endl;
	
	int red_start, red_end;
	lint red_sum = max_subarray(line, 'R', red_start, red_end);
	
	int blue_start, blue_end;
	lint blue_sum = max_subarray(line, 'B', blue_start, blue_end);
	
	// 0 = red, 1 = blue
	int selection = 0;
	
	if (red_sum > blue_sum) {
		selection = 0;
	} else if (blue_sum > red_sum) {
		selection = 1;
	} else {
		selection = red_start < blue_start ? 0 : 1;
	}
	
	if (selection == 0) {
		cout << (red_start + 1) << " " << (red_end + 1) << endl;
	} else {
		cout << (blue_start + 1) << " " << (blue_end + 1) << endl;
	}
	
	return 0;
}