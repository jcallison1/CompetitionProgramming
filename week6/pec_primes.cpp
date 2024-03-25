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

void stuff(vector<lint>& primes, set<lint>& all_the_values, int prime_index, lint value, lint start, lint end) {
	if (prime_index == primes.size()) {
		if (start <= value && value <= end) {
			all_the_values.insert(value);
		}
		
		return;
	}
	
	lint prime = primes[prime_index];
	lint mult = 1;
	
	while (true) {
		lint x = value * mult;
		if (x > end) break;
		
		stuff(primes, all_the_values, prime_index + 1, x, start, end);
		
		mult *= prime;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	while (true) {
		int prime_count;
		vector<lint> primes;
		
		cin >> prime_count;
		if (prime_count == 0) break;
		
		for (int i = 0; i < prime_count; i++) {
			lint prime;
			cin >> prime;
			primes.push_back(prime);
		}
		
		lint start, end;
		cin >> start >> end;
		
		set<lint> all_the_values;
		stuff(primes, all_the_values, 0, 1, start, end);
		
		if (all_the_values.empty()) {
			cout << "none" << endl;
		} else {
			bool first = true;
			
			for (auto v : all_the_values) {
				if (!first) cout << ",";
				cout << v;
				first = false;
			}
			
			cout << endl;
		}
	}
	
	return 0;
}