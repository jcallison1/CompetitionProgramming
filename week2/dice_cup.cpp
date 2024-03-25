#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int num1, num2;
	
	cin >> num1 >> num2;
    
    int min_num = min(num1, num2);
    int max_num = max(num1, num2);
    
    for (int i = min_num + 1; i <= max_num + 1; i++) {
        cout << i << endl;
    }
    
    return 0;
}