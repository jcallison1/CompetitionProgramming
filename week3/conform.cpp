#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	map<set<int>, int> all_coms;
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		set<int> com;
		
		for (int j = 0; j < 5; j++) {
			int num;
			cin >> num;
			
			com.insert(num);
		}
				
		if (all_coms.find(com) == all_coms.end()) {
			all_coms[com] = 1;
		} else {
			all_coms[com]++;
		}
	}
	
	int big = 0;
	int count = 0;
	
	for (auto entry : all_coms) {
		int l = get<1>(entry);
		
		// cout << l << endl;
		
		if (l > big) {
			big = l;
			count = l;
		} else if (big == l) {
			count += l;
		}
	}
	
	cout << count << endl;
	
	return 0;
}