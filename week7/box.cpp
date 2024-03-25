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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int cases;
	cin >> cases;
	
	for (int the_case = 0; the_case < cases; the_case++) {
		double width, height;
		cin >> width >> height;
		
		double a = 12.0;
		double b = -4.0 * (width + height);
		double c = width * height;
		
		double m = sqrt(b*b - 4.0 * a * c);
		
		double root1 = (-b + m) / (2.0 * a);
		double root2 = (-b - m) / (2.0 * a);
		
		double vol1 = 4.0 * root1*root1*root1 - 2.0 * root1*root1 * (width + height) + root1 * width * height;
		double vol2 = 4.0 * root2*root2*root2 - 2.0 * root2*root2 * (width + height) + root2 * width * height;
		
		cout << setprecision(11) << max(vol1, vol2) << endl;
	}
	
	return 0;
}