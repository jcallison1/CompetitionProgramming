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

#define lint long long int

double search(vector<vector<double>>& cache, int k, int prev, int remaining_length) {
	if (remaining_length <= 0) return 1;
	
	if (cache[prev][remaining_length] != -1) return cache[prev][remaining_length];
	
	double sum = 0;
	
	if (prev > 0) sum += search(cache, k, prev - 1, remaining_length - 1);
	sum += search(cache, k, prev, remaining_length - 1);
	if (prev < k) sum += search(cache, k, prev + 1, remaining_length - 1);
	
	cache[prev][remaining_length] = sum;
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	while (true) {
		int k, n;
		cin >> k >> n;
		if (!cin) break;
		
		vector<vector<double>> cache(10, vector<double>(n + 1, -1));
		
		double sum = 0;
		
		if (k == 0) {
			sum = 1;
		} else {
			for (int i = 0; i <= k; i++) {
				sum += search(cache, k, i, n - 1);
			}
		}
		
		double all = pow((double) k + 1, (double) n);
		
		cout << setprecision(12) << (sum / all * 100.0) << endl;
	}
	
	return 0;
}