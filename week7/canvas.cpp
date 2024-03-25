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

lint get_sum(vector<lint>& sums, int start, int end) {
	lint sum = sums[end - 1];
	if (start > 0) sum -= sums[start - 1];
	
	return sum;
}

lint find_ink(vector<int>& canvases, vector<lint>& sums, int start, int end, int depth = 0) {
	// cerr << start << ", " << end << endl;
	
	if (end - start <= 1) return 0;
	// if (start + 1 == end) return canvases[start];
	
	// int mid = (start + end) / 2;
	int mid = start;
	lint best_diff = 9999999999999;
	
	for (int i = start; i < end; i++) {
		lint diff = abs(get_sum(sums, start, i) - get_sum(sums, i, end));
		
		if (diff < best_diff) {
			mid = i;
			best_diff = diff;
		}
	}
	
	// lint ink_cost = accumulate(canvases.begin() + start, canvases.begin() + end, 0);
	lint ink_cost = get_sum(sums, start, end);
	
	if (end - start == 2) return ink_cost;
	
	ink_cost += find_ink(canvases, sums, start, mid, depth + 1);
	ink_cost += find_ink(canvases, sums, mid, end, depth + 1);
	
	return ink_cost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int cases;
	cin >> cases;
	
	for (int the_case = 0; the_case < cases; the_case++) {
		int canvas_count;
		cin >> canvas_count;
		
		// vector<int> canvases;
		// vector<lint> sums;
		priority_queue<lint, vector<lint>, greater<lint>> canvases;
		
		// lint current_sum = 0;
		
		for (int i = 0; i < canvas_count; i++) {
			lint canvas_size;
			cin >> canvas_size;
			
			// current_sum += canvas_size;
			
			canvases.push(canvas_size);
			// sums.push_back(current_sum);
		}
		
		// lint ink = find_ink(canvases, sums, 0, canvases.size());
		
		// sort(canvases.begin(), canvases.end());
		
		// deque<int> canvases_queue;
		
		// for (auto i : canvases) {
		// 	canvases_queue.push_back(i);
		// }
		
		lint ink = 0;
		// lint group = canvases.front();
		
		// for (int i = 1; i < canvases.size(); i++) {
		// 	group += canvases[i];
		// 	ink += group;
		// }
		
		while (canvases.size() > 1) {
			lint first = canvases.top();
			canvases.pop();
			lint second = canvases.top();
			canvases.pop();
			
			auto sum = first + second;
			
			ink += sum;
			canvases.push(sum);
		}
		
		cout << ink << endl;
	}
	
	return 0;
}