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
	
	if (n <= 2 || x > (n - 1) * (n - 2) / 2) {
		cout << -1 << endl;
	} else {
		vector<int> bars;
		
		for (int i = 0; i < n; i++) {
			bars.push_back(i + 1);
		}
		
		int second_largest = n - 1;
		int cursor = 0;
		long remaining = x;
		
		while (remaining > 0) {
			swap(bars[cursor], bars[cursor + 1]);
			
			if (bars[cursor] == second_largest) {
				cursor = 0;
			} else {
				cursor++;
			}
			
			remaining--;
		}
		
		if (remaining != 0) {
			cout << -1 << endl;
		} else {
			for (int i = 0; i < n; i++) {
				cout << bars[i];
				if (i != n - 1) cout << " ";
			}
			
			cout << endl;
		}
	}
	
	return 0;
}