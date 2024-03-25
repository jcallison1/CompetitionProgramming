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
#include <iomanip>
#include <cmath>
#include <queue>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int N; cin >> N;
	priority_queue<long, vector<long>, greater<long>> canvas;
	bool notFirst = false;
	while(N--) {
		long testCaseSize; cin >> testCaseSize;
		long temp;
		for (long i = 0; i < testCaseSize; ++i) {
			cin >> temp;
			canvas.push(temp);
		}
		
		while (!canvas.empty()) {
			cout << canvas.top() << endl;
			canvas.pop();
		}
		
		continue;
		
		long counter = 0;
		while (canvas.size() != 1) {
			long a = canvas.top(); canvas.pop();
			long b = canvas.top(); canvas.pop();
			counter+= (a+b);
			canvas.push(a+b);
		}
		if (notFirst)
			cout << "\n";
		notFirst = true;
		cout << counter;
		canvas.pop();
	}
	return 0;
	
}