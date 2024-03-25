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
	lint query(int j) {
		lint sum = 0;
		
		for (; j != 0; j -= (j & -j))
			sum += tree[j];
		
		return sum;
	}
	
	// Sum of ft[i..j] inclusive
	long query(int i, int j) {
		return query(j) - query(i - 1);
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
	
	lint query(int i) {
		return fen.query(i);
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
	
	int gem_count, queries;
	cin >> gem_count >> queries;
	
	array<lint, 6> gem_values;
	
	for (int i = 0; i < 6; i++) {
		cin >> gem_values[i];
	}
	
	string gems_str;
	cin >> gems_str;
	
	vector<int> gems_type;
	gems_type.assign(gem_count, 0);
	
	vector<FenwickTree> gems_by_type;
	
	for (int i = 0; i < 6; i++) {
		gems_by_type.push_back(FenwickTree(gem_count));
	}
		
	for (int i = 0; i < gem_count; i++) {
		int gem_type = (int) (gems_str[i] - '1');
		
		gems_type[i] = gem_type;
		gems_by_type[gem_type].update(i + 1, 1);
	}
	
	for (int i = 0; i < queries; i++) {
		int command;
		cin >> command;
		
		if (command == 1) {
			int index, new_type;
			cin >> index >> new_type;
			new_type -= 1;
			
			int old_type = gems_type[index - 1];
			gems_type[index - 1] = new_type;
			
			gems_by_type[old_type].update(index, -1);
			gems_by_type[new_type].update(index, 1);
		} else if (command == 2) {
			int gem_type;
			lint new_value;
			cin >> gem_type >> new_value;
			
			gem_values[gem_type - 1] = new_value;
		} else if (command == 3) {
			int start, end;
			cin >> start >> end;
			
			lint sum = 0;
			
			for (int i = 0; i < 6; i++) {
				sum += gems_by_type[i].query(start, end) * gem_values[i];
			}
			
			cout << sum << endl;
		}
	}
	
	return 0;
}