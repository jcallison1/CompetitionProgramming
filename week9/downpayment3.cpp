#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <unordered_set>
#include <sstream>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

#define lint long long int

int to_cents(double n) {
	return (int) floor(n * 100.0);
}

struct CacheEntry {
	int debt;
	int chosen_alternative;
	int months_paid;
};

struct Stuff {
	int alternative_count;
	int starting_debt, monthly_payment;
	
	vector<int> binding_times;
	vector<vector<int>> switching_costs;
	
	int months_known;
	vector<vector<double>> interest_rates;
};

int search(Stuff& stuff, vector<vector<CacheEntry>>& cache, int month, int last_alternate) {
	// cerr << "month: " << month << endl;
	
	if (month >= stuff.months_known) return 0;
	
	if (cache[month][last_alternate].debt != -1) {
		return cache[month][last_alternate].debt;
	}
	
	CacheEntry result;
	result.debt = INT_MAX;
	
	for (int alter = 0; alter < stuff.alternative_count; alter++) {
		int binding_time = stuff.binding_times[alter];
		
		int end_month = min(month + binding_time, stuff.months_known);
		int debt = search(stuff, cache, end_month, alter);
		
		// if (last_alternate != -1) {
		// 	new_debt += stuff.switching_costs[last_alternate][alter];
		// }
		
		for (int new_month = end_month - 1; new_month >= month; new_month--) {
			debt += stuff.monthly_payment;
			debt = (int) floor(debt / stuff.interest_rates[new_month][alter]);
			// cerr << new_month << endl;
		}
		
		if (month > 0) {
			debt -= stuff.switching_costs[last_alternate][alter];
		}
		
		if (debt < result.debt) {
			result = {
				debt,
				alter,
				end_month - month
			};
		}
	}
	
	cache[month][last_alternate] = result;
	return result.debt;
}

int reconstruct_path(Stuff& stuff, vector<vector<CacheEntry>>& cache) {
	int paid = 0;
	int debt = stuff.starting_debt;
	
	int last_alternate = 0;
	int current_month = 0;
	
	while (current_month <= stuff.months_known && debt > 0) {
		// if (cache.find(params) == cache.end()) break;
		auto& entry = cache[current_month][last_alternate];
		
		if (current_month > 0) {
			debt += stuff.switching_costs[last_alternate][entry.chosen_alternative];
		}
		
		for (int i = 0; i < entry.months_paid; i++) {
			cout << "Month " << (current_month + 1) << ": Alternative " << (entry.chosen_alternative + 1) << endl;
			
			debt = (int) floor(debt * stuff.interest_rates[current_month][entry.chosen_alternative]);
			// cerr << new_debt << endl;
			
			current_month++;
			
			if (debt <= stuff.monthly_payment) {
				paid += debt;
				debt = 0;
				break;
			} else {
				paid += stuff.monthly_payment;
				debt -= stuff.monthly_payment;
			}
		}
		
		last_alternate = entry.chosen_alternative;
	}
	
	return paid;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int test_cases;
	cin >> test_cases;
	
	for (int test_case = 0; test_case < test_cases; test_case++) {
		Stuff stuff;
		
		double loan_amount, monthly_payment;
		cin >> stuff.alternative_count >> loan_amount >> monthly_payment;
		stuff.starting_debt = to_cents(loan_amount);
		stuff.monthly_payment = to_cents(monthly_payment);
		
		for (int i = 0; i < stuff.alternative_count; i++) {
			int binding_time;
			cin >> binding_time;
			stuff.binding_times.push_back(binding_time);
		}
		
		for (int i = 0; i < stuff.alternative_count; i++) {
			auto& row = stuff.switching_costs.emplace_back();
			
			for (int j = 0; j < stuff.alternative_count; j++) {
				double switching_cost;
				cin >> switching_cost;
				row.push_back(to_cents(switching_cost));
			}
		}
		
		cin >> stuff.months_known;
		
		for (int i = 0; i < stuff.months_known; i++) {
			auto& row = stuff.interest_rates.emplace_back();
			
			for (int j = 0; j < stuff.alternative_count; j++) {
				double interest_rate;
				cin >> interest_rate;
				row.push_back(interest_rate / 100.0 + 1.0);
			}
		}
		
		vector<vector<CacheEntry>> cache(stuff.months_known + 2, vector<CacheEntry>(stuff.alternative_count, {-1, -1, -1}));
		
		int min_debt = search(stuff, cache, 0, 0);
		
		cout << "Test case " << (test_case + 1) << endl;
		
		for (auto& row : cache) {
			for (auto& x : row) {
				if (x.debt == -1)
					cerr << "     .";
				else
					cerr << setw(6) << x.debt;
			}
			
			cerr << endl;
		}
		
		int best_cost = reconstruct_path(stuff, cache);
		
		cout << "Total: " << fixed << setprecision(2) << (best_cost / 100.0) << endl;
	}
	
	return 0;
}