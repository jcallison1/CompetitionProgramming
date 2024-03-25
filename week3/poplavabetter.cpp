#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	long n, x;
	
	cin >> n >> x;
	// n = 4; x = 4;
	
	if (n <= 2 || x > (n - 1) * (n - 2) / 2) {
		cout << -1 << endl;
	} else {
		// Poor man's linked list:
		// The ith element represents the bar with i height. The element itself
		// is the index of the next bar in the list. The 0th element is the head ptr.
		vector<int> nodes;
		nodes.push_back(1);
		
		for (int i = 0; i < n; i++) {
			nodes.push_back(i + 2);
		}
		
		int second_largest_index = n - 1;
		int second_largest_pos = n - 1;
		long remaining = x;
		
		while (remaining > 0) {
			int move_to;
			
			if (remaining >= second_largest_pos) {
				move_to = second_largest_index;
				
				second_largest_pos--;
				remaining -= second_largest_pos;
			} else {
				move_to = nodes[0];
				
				for (int i = 0; i < remaining; i++) {
					move_to = nodes[move_to];
				}
				
				// cout << "Move to: " << move_to << endl;
				remaining = 0;
			}
			
			// Exclude the first
			int first = nodes[0];
			nodes[0] = nodes[first];
			
			// Insert the first after move_to
			int old_next = nodes[move_to];
			nodes[move_to] = first;
			nodes[first] = old_next;
		}
		
		if (remaining != 0) {
			cout << -1 << endl;
		} else {
			int current_index = nodes[0];
			int i = 0;
			
			while (current_index < nodes.size()) {
				cout << current_index;
				if (i != n - 1) cout << " ";
				
				current_index = nodes[current_index];
				i++;
			}
			
			cout << endl;
		}
	}
	
	return 0;
}