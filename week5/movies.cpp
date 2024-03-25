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

int main() {
	ios::sync_with_stdio(false);
	
	int test_cases;
	cin >> test_cases;
	
	for (int test_case = 0; test_case < test_cases; test_case++) {
		int movie_count, requests;
		cin >> movie_count >> requests;
		
		FenwickTree fen(movie_count + requests + 10);
		vector<int> mapping(movie_count);
		
		int head = 1;
		
		for (int i = 0; i < movie_count; i++) {
			mapping[movie_count - i - 1] = head;
			fen.update(head, 1);
			head++;
		}
		
		for (int i = 0; i < requests; i++) {
			int movie_id;
			cin >> movie_id;
			
			auto loc = mapping[movie_id - 1];
			
			if (i != 0) cout << " ";
			
			if (loc == head - 1) {
				cout << 0;
				continue;
			}
			
			cout << fen.query(loc + 1, fen.tree.size() - 1);
			
			fen.update(loc, -1);
			fen.update(head, 1);
			mapping[movie_id - 1] = head;
			head++;
		}
		
		cout << endl;
	}
	
	return 0;
}