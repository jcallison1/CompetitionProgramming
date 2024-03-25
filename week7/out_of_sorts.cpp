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

using namespace std;

#define lint long long int

bool custom_binary_search(vector<lint>& vec, int start, int end, lint needle) {
	if (end < start) return false;
	
	if (start == end) {
		return vec[start] == needle;
	}
	
	int mid_index = (start + end) / 2;
	auto mid = vec[mid_index];
	
	if (needle < mid) {
		return custom_binary_search(vec, start, mid_index - 1, needle);
	} else if (needle > mid) {
		return custom_binary_search(vec, mid_index + 1, end, needle);
	}
	
	return true;
	
	// int size = vec.size();
	// int left = 0;
	// int right = size;
	
	// while (left < right) {
	// 	int mid_index = left + size / 2;
	// 	int mid = vec[mid_index];
		
	// 	if (mid < needle) left = mid + 1;
	// 	if (mid > needle) right = mid;
		
	// 	if (mid == needle) return true;
		
	// 	size = right - left;
	// 	if (size == 0) break;
	// }
	
	// return false;
}

// void count_bin(vector<lint>& vec, int& found, int start, int end, lint min, lint max) {
// 	int mid_index = (start + end) / 2;
// 	auto mid_value = vec[mid_index];
	
// 	if (min <= mid_value && mid_value <= max) found++;
	
// 	if (end - start <= 1) return;
	
// 	count_bin(vec, found, start, mid_index, min, std::min(max, mid_value));
// 	count_bin(vec, found, mid_index + 1, end, std::max(min, mid_value), max);
// }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	lint term_count;
	lint m, a, c, x0;
	cin >> term_count >> m >> a >> c >> x0;
	
	lint last_term = x0;
	vector<lint> terms;
	
	for (int i = 0; i < term_count; i++) {
		last_term = (a * last_term + c) % m;
		terms.push_back(last_term);
	}
	
	int found = 0;
	
	// count_bin(terms, found, 0, terms.size(), LONG_MIN, LONG_MAX);
	
	for (auto term : terms) {
		// cout << term << endl;
		
		if (custom_binary_search(terms, 0, terms.size() - 1, term)) {
			found++;
		}
	}
	
	cout << found << endl;
	
	return 0;
}