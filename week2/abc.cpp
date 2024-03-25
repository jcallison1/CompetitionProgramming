#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> nums;
	int num;
	
	cin >> num;
	nums.push_back(num);
	cin >> num;
	nums.push_back(num);
	cin >> num;
	nums.push_back(num);
	
	sort(nums);
    
    return 0;
}