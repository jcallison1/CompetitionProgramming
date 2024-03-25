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

struct Week {
	vector<int> prices;
	vector<int> sold;
};

lint search(vector<vector<lint>>& cache, vector<Week>& weeks, int week_index, int remaining_seats) {
	if (week_index >= weeks.size() || remaining_seats <= 0) return 0;
	
	if (cache[week_index][remaining_seats] != -1) return cache[week_index][remaining_seats];
	
	auto& week = weeks[week_index];
	lint max = 0;
	
	for (int i = 0; i < week.prices.size(); i++) {
		int ticket_price = week.prices[i];
		int tickets_sold = min(week.sold[i], remaining_seats);
		lint result = search(cache, weeks, week_index + 1, remaining_seats - tickets_sold) + tickets_sold * ticket_price;
		
		if (result > max) {
			max = result;
		}
	}
	
	cache[week_index][remaining_seats] = max;
	return max;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int total_seats, week_count;
	cin >> total_seats >> week_count;
	
	vector<Week> weeks;
	
	for (int i = 0; i <= week_count; i++) {
		int count;
		cin >> count;
		
		Week& week = weeks.emplace_back();
		
		for (int j = 0; j < count; j++) {
			int price;
			cin >> price;
			
			week.prices.push_back(price);
		}
		
		for (int j = 0; j < count; j++) {
			int sold;
			cin >> sold;
			
			week.sold.push_back(sold);
		}
	}
	
	vector<vector<lint>> cache(weeks.size(), vector<lint>(total_seats + 1, -1));
	
	auto& first_week = weeks[0];
	
	int first_ticket_price = 0;
	lint max_revenue = 0;
	
	// lint max = search(weeks, 0, total_seats);
	
	// cout << max << endl;
	
	for (int i = 0; i < first_week.prices.size(); i++) {
		int ticket_price = first_week.prices[i];
		int tickets_sold = min(first_week.sold[i], total_seats);
		lint result = search(cache, weeks, 1, total_seats - tickets_sold) + tickets_sold * ticket_price;
		
		if (result > max_revenue) {
			max_revenue = result;
			first_ticket_price = ticket_price;
		} else if (result == max_revenue && ticket_price < first_ticket_price) {
			first_ticket_price = ticket_price;
		}
	}
	
	cout << max_revenue << endl;
	cout << first_ticket_price << endl;
	
	return 0;
}