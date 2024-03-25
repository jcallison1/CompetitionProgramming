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

struct Params {
	int month, debt, last_alternate;
	
	inline bool operator==(const Params& other) const {
		return month == other.month && debt == other.debt && last_alternate == other.last_alternate;
	}
};

namespace std {
	template<>
	struct hash<Params> {
		inline size_t operator()(const Params& x) const {
			return x.month ^ x.debt ^ x.last_alternate;
		}
	};
}

struct CacheEntry {
	int paid;
	int chosen_alternative;
	int months_paid;
	Params next;
};

struct Stuff {
	int alternative_count;
	int starting_debt, monthly_payment;
	
	vector<int> binding_times;
	vector<vector<int>> switching_costs;
	
	int months_known;
	vector<vector<double>> interest_rates;
};

int search(Stuff& stuff, unordered_map<Params, CacheEntry>& cache, Params params) {
	// cerr << "month: " << month << endl;
	
	auto [month, debt, last_alternate] = params;
	
	if (month >= stuff.months_known) return 99999999;
	
	auto iter = cache.find(params);
	if (iter != cache.end()) return iter->second.paid;
	
	CacheEntry result;
	result.paid = INT_MAX;
	
	for (int alter = 0; alter < stuff.alternative_count; alter++) {
		int binding_time = stuff.binding_times[alter];
		
		int new_debt = debt;
		int new_month = month;
		int paid = 0;
		
		if (last_alternate != -1) {
			new_debt += stuff.switching_costs[last_alternate][alter];
		}
		
		for (int i = 0; i < binding_time; i++) {
			if (new_month >= stuff.months_known) {
				paid = INT_MAX;
				new_debt = 0;
				break;
			}
			
			new_debt = (int) floor(new_debt * stuff.interest_rates[new_month][alter]);
			// cerr << new_debt << endl;
			
			new_month++;
			
			if (new_debt <= stuff.monthly_payment) {
				paid += new_debt;
				new_debt = 0;
				break;
			} else {
				paid += stuff.monthly_payment;
				new_debt -= stuff.monthly_payment;
			}
		}
		
		Params new_params = {-1, -1, -1};
		
		if (new_debt > 0) {
			new_params = {new_month, new_debt, alter};
			paid += search(stuff, cache, new_params);
		}
		
		if (paid < result.paid) {
			result = {
				paid,
				alter,
				new_month - month,
				new_params
			};
		}
	}
	
	cache[params] = result;	
	return result.paid;
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
		
		unordered_map<Params, CacheEntry> cache;
		
		Params params = {0, stuff.starting_debt, -1};
		int best_cost = search(stuff, cache, params);
		
		cout << "Test case " << (test_case + 1) << endl;
		
		while (params.month != -1) {
			// if (cache.find(params) == cache.end()) break;
			auto& entry = cache[params];
			
			for (int i = 0; i < entry.months_paid; i++) {
				cout << "Month " << (params.month + 1 + i) << ": Alternative " << (entry.chosen_alternative + 1) << endl;
			}
			
			params = entry.next;
		}
		
		cout << "Total: " << fixed << setprecision(2) << (best_cost / 100.0) << endl;
	}
	
	return 0;
}