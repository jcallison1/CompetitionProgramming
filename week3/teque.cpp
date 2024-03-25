#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	deque<int> first_half;
	deque<int> last_half;
	
	int instructions;
	cin >> instructions;
	
	for (int i = 0; i < instructions; i++) {
		string instruction;
		int num;
		
		cin >> instruction >> num;
		
		if (instruction == "push_back") {
			last_half.push_back(num);
			
			if (last_half.size() - first_half.size() > 0) {
				first_half.push_back(last_half.front());
				last_half.pop_front();
			}
		} else if (instruction == "push_front") {
			first_half.push_front(num);
			
			if (first_half.size() - last_half.size() > 1) {
				last_half.push_front(first_half.back());
				first_half.pop_back();
			}
		} else if (instruction == "push_middle") {
			if (first_half.size() == last_half.size()) {
				first_half.push_back(num);
			} else {
				last_half.push_front(num);
			}
		} else if (instruction == "get") {
			cout << (num < first_half.size() ? first_half[num] : last_half[num - first_half.size()]) << endl;
		}
		
		// for_each(first_half.begin(), first_half.end(), [](auto v) { cout << v << " "; });
		// cout << "| ";
		// for_each(last_half.begin(), last_half.end(), [](auto v) { cout << v << " "; });
		// cout << endl;
	}
	
	return 0;
}