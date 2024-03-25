#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int s, v1, v2;
	cin >> s >> v1 >> v2;
	
	for (int b1 = s / v1; b1 >= 0; b1--) {
		int leftover = s - b1 * v1;
		
		if (leftover == 0 || leftover % v2 == 0) {
			int b2 = leftover / v2;
			
			cout << b1 << " " << b2 << endl;
			return 0;
		}
	}
	
	cout << "Impossible" << endl;
	
	return 0;
}