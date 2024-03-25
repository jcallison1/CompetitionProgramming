#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int tests;
	cin >> tests;
	
	for (int test = 0; test < tests; test++) {
		int g, m;
		cin >> g >> m;
		
		vector<int> glist;
		vector<int> mlist;
		
		for (int i = 0; i < g; i++) {
			int n;
			cin >> n;
			glist.push_back(n);
		}
		
		for (int i = 0; i < m; i++) {
			int n;
			cin >> n;
			mlist.push_back(n);
		}
		
		sort(glist.rbegin(), glist.rend());
		sort(mlist.rbegin(), mlist.rend());
		
		while (!glist.empty() && !mlist.empty()) {
			if (glist.back() < mlist.back()) {
				glist.pop_back();
			} else {
				mlist.pop_back();
			}
		}
		
		// cout << glist.back() << endl;
		// cout << mlist.back() << endl;
		
		if (mlist.empty() && glist.empty()) {
			cout << "Godzilla";
		} else if (mlist.empty()) {
			cout << "Godzilla";
		} else if (glist.empty()) {
			cout << "MechaGodzilla";
		} else {
			cout << "uncertain";
		}
		
		// if (mlist.empty() && glist.empty()) {
		// 	cout << "Godzilla";
		// } else if (mlist.empty() || glist.back() > mlist.back()) {
		// 	cout << "Godzilla";
		// } else if (glist.empty() || glist.back() < mlist.back()) {
		// 	cout << "MechaGodzilla";
		// } else {
		// 	cout << "uncertain";
		// }
		
		cout << endl;
	}
    
    return 0;
}