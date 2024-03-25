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

class FenwickTree {
public:
	vector<lint> tree;
	
	FenwickTree(int m) {
		tree.assign(m + 1, 0);
	}
	
	// Sum of ft[1..j] inclusive
	lint rsq(int j) {
		lint sum = 0;
		
		for (; j != 0; j -= (j & -j))
			sum += tree[j];
		
		return sum;
	}
	
	// Sum of ft[i..j] inclusive
	long rsq(int i, int j) {
		return rsq(j) - rsq(i - 1);
	}
	
	// Update ft[i] by v. ft[1] is the first element.
	void update(int i, lint v) {
		if (i == 0) return;
		
		for (; i < (int) tree.size(); i += (i & -i))
			tree[i] += v;
	}
};

class ReverseFenwickTree {
public:
	FenwickTree fen;
	
	ReverseFenwickTree(int m): fen(FenwickTree(m + 1)) {}
	
	lint psq(int i) {
		return fen.rsq(i);
	}
	
	void update(int i, int j, lint v) {
		fen.update(i, v);
		fen.update(j + 1, -v);
	}
	
	void update(int i, lint v) {
		update(i, i, v);
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int size;
	cin >> size;
	
	FenwickTree fen(size);
	vector<int> num_to_index(size + 1);
	
	for (int i = 1; i <= size; i++) {
		lint x;
		cin >> x;
		
		num_to_index[x] = i;
		fen.update(i, 1);
	}
	
	// for (int i = 0; i < size; i++) {
	// 	cout << " " << fen.psq(i + 1);
	// } cout << endl;
	
	// for (int i = 0; i < size; i++) {
	// 	int pos = i / 2;
	// 	if (i % 2) pos = size - pos - 1;
	// 	pos += 1;
		
	// 	auto dist = fen.psq(pos);
		
	// 	cout << abs(dist) << endl;
		
	// 	auto new_pos = pos + dist;
		
	// 	if (dist > 0) {
	// 		fen.update(pos, new_pos, -1);
	// 	} else if (dist < 0) {
	// 		fen.update(new_pos, pos, 1);
	// 	}
	// }
	
	int left = 1;
	int right = size;
	
	for (int i = 1; i <= size; i++) {
		if (i % 2) {
			auto pos = num_to_index[left];
			fen.update(pos, -1);
			left++;
			
			cout << fen.rsq(1, pos) << endl;
		} else {
			auto pos = num_to_index[right];
			fen.update(pos, -1);
			right--;
			
			cout << fen.rsq(pos, size) << endl;
		}
	}
	
	return 0;
}