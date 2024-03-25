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

struct Flight {
	int to_airport;
	int on_day;
	int capacity;
};

struct Airport {
	vector<Flight> flights_out;
	vector<int> peoples_per_day;
	int people;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int airport_count, window_days, flight_count;
	cin >> airport_count >> window_days >> flight_count;
	
	vector<Airport> airports(airport_count, {
		.flights_out = {},
		.peoples_per_day = vector<int>(window_days, 0),
		.people = 0
	});
	
	for (int i = 0; i < flight_count; i++) {
		int from_airport, to_airport, on_day, capacity;
		cin >> from_airport >> to_airport >> on_day >> capacity;
		
		from_airport--;
		to_airport--;
		on_day--;
		
		airports[from_airport].flights_out.push_back({ to_airport, on_day, capacity });
	}
	
	for (int i = 0; i < airport_count * window_days; i++) {
		int airport, day, peoples;
		cin >> airport >> day >> peoples;
		
		airport--;
		day--;
		
		airports[airport].peoples_per_day[day] = peoples;
	}
	
	vector<int> people_coming_in (airport_count, 0);
	
	bool optimal = true;
	
	for (int day = 0; day < window_days; day++) {
		for (auto& airport : airports) {
			airport.people += airport.peoples_per_day[day];
			
			for (auto& flight : airport.flights_out) {
				if (flight.on_day != day) continue;
				
				if (flight.capacity > airport.people) {
					optimal = false;
					break;
				}
				
				airport.people -= flight.capacity;
				people_coming_in[flight.to_airport] += flight.capacity;
			}
			
			if (!optimal) break;
		}
		
		if (!optimal) break;
		
		for (int i = 0; i < airport_count; i++) {
			airports[i].people += people_coming_in[i];
			people_coming_in[i] = 0;
		}
	}
	
	cout << (optimal ? "optimal" : "suboptimal") << endl;
	
	return 0;
}