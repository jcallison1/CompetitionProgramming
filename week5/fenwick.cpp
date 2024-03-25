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

class FenwickTree {
public:
	vector<long long> tree;
	
	FenwickTree(int m) {
		tree.assign(m + 1, 0);
	}
	
	// Sum of ft[1..j] inclusive
	long long rsq(int j) {
		long long sum = 0;
		
		for (; j != 0; j -= (j & -j))
			sum += tree[j];
		
		return sum;
	}
	
	// Sum of ft[i..j] inclusive
	long rsq(int i, int j) {
		return rsq(j) - rsq(i - 1);
	}
	
	// Update ft[i] by v. ft[1] is the first element.
	void update(int i, long long v) {
		for (; i < (int) tree.size(); i += (i & -i))
			tree[i] += v;
	}
};

int main() {
	ios::sync_with_stdio(false);
	
	int size, commands;
	cin >> size >> commands;
	
	FenwickTree fen(size);
	
	for (int i = 0; i < commands; i++) {
		char command;
		cin >> command;
		
		if (command == '+') {
			long index, delta;
			cin >> index >> delta;
			
			fen.update(index + 1, delta);
		} else {
			int index;
			cin >> index;
			
			auto sum = index == 0 ? 0 : fen.rsq(index);
			cout << sum << endl;
		}
	}
	
	return 0;
}