#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int climb, fall, total;
	cin >> climb >> fall >> total;
	
	int dist = 0;
	int n = 0;
	
	while (true) {
		dist += climb;
		n += 1;
		
		if (dist >= total) break;
		dist -= fall;
	}
	
	cout << n << endl;
	
    return 0;
}