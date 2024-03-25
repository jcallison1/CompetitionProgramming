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

struct Stuff {
	int alternative_count;
	int starting_debt, monthly_payment;
	
	vector<int> binding_times;
	vector<vector<int>> switching_costs;
	
	int months_known;
	vector<vector<double>> interest_rates;
};

void read_test_case(Stuff& stuff) {
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
}

struct TableEntry {
	int remaining_debt;
	int paid;
	int interest;
	int prev_alternative;
	int prev_month;
};

void fill_cell(Stuff& stuff, vector<vector<TableEntry>>& table, TableEntry& best, int month, int prev_alternative) {
	auto& current_entry = table[month][prev_alternative];
	
	if (current_entry.remaining_debt == INT_MAX) return;
	
	if (current_entry.remaining_debt == 0) {
		if (current_entry.interest < best.interest) {
			best = {
				0,
				current_entry.paid,
				current_entry.interest,
				prev_alternative,
				month
			};
		}
		
		return;
	}
	
	for (int new_alter = 0; new_alter < stuff.alternative_count; new_alter++) {
		int binding_time = stuff.binding_times[new_alter];
		
		int new_debt = current_entry.remaining_debt;
		int new_month = month;
		int paid = current_entry.paid;
		int interest = current_entry.interest;
		
		if (prev_alternative != -1) {
			new_debt += stuff.switching_costs[prev_alternative][new_alter];
			interest += stuff.switching_costs[prev_alternative][new_alter];
		}
		
		for (int i = 0; i < binding_time; i++) {
			if (new_month >= stuff.months_known) {
				interest = INT_MAX;
				break;
			}
			
			interest += (int) floor(new_debt * (stuff.interest_rates[new_month][new_alter] - 1.0));
			new_debt = (int) floor(new_debt * stuff.interest_rates[new_month][new_alter]);
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
		
		auto& next_entry = table[new_month][new_alter];
		
		if (interest < next_entry.interest) {
			next_entry = {
				new_debt,
				paid,
				interest,
				prev_alternative,
				month
			};
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int test_cases;
	cin >> test_cases;
	
	for (int test_case = 0; test_case < test_cases; test_case++) {
		Stuff stuff;
		read_test_case(stuff);
		
		vector<vector<TableEntry>> table(stuff.months_known + 2, vector<TableEntry>(stuff.alternative_count, {INT_MAX, INT_MAX, INT_MAX, -1, -1}));
		
		table[0].assign(stuff.alternative_count, {stuff.starting_debt, 0, 0, -1, -1});
		
		TableEntry best = {INT_MAX, INT_MAX, INT_MAX, -1, -1};
		
		for (int month = 0; month <= stuff.months_known; month++) {
			for (int alter = 0; alter < stuff.alternative_count; alter++) {
				fill_cell(stuff, table, best, month, alter);
			}
		}
		
		// for (auto row : table) {
		// 	for (auto x : row) {
		// 		if (x.remaining_debt == INT_MAX)
		// 			cerr << "     .";
		// 		else
		// 			cerr << setw(6) << x.remaining_debt;
		// 	}
			
		// 	cerr << endl;
		// }
		
		vector<int> alternative_chain;
		int current_alter = best.prev_alternative;
		int current_month = best.prev_month;
		
		while (current_month > 0) {
			auto& entry = table[current_month][current_alter];
			
			for (int m = current_month; m > entry.prev_month; m--) {
				alternative_chain.push_back(current_alter);
			}
			
			current_alter = entry.prev_alternative;
			current_month = entry.prev_month;
		}
		
		cout << "Test case " << (test_case + 1) << endl;
		
		current_month = 1;
		
		for (auto i = alternative_chain.rbegin(); i != alternative_chain.rend(); i++) {
			cout << "Month " << (current_month) << ": Alternative " << (*i + 1) << endl;
			
			current_month++;
		}
		
		cout << "Total: " << fixed << setprecision(2) << (best.paid / 100.0) << endl;
	}
	
	return 0;
}