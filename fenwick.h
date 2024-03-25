#include <vector>

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
