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

using namespace std;

#define lint long long int

struct Shield {
	int lower, upper;
	double factor;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int x, y;
	cin >> x >> y;
	
	int shield_count;
	cin >> shield_count;
	
	vector<Shield> shields;
	
	for (int i = 0; i < shield_count; i++) {
		Shield shield;
		cin >> shield.lower >> shield.upper >> shield.factor;
				
		shields.push_back(shield);
	}
	
	sort(shields.rbegin(), shields.rend(), [](auto a, auto b) {
		return a.upper < b.upper;
	});
	
	double sum = 0.0;
	int height = y;
	
	for (auto shield : shields) {
		sum += (height - shield.upper);
		sum += (double) (shield.upper - shield.lower) * shield.factor;
		
		// cout << (height - shield.upper) << endl;
		// cout << (shield.upper - shield.lower) << endl;
		height = shield.lower;
	}
	
	sum += height;
	
	double answer = (double) x / sum;
	cout << setprecision(10) << answer << endl;
	
	return 0;
}