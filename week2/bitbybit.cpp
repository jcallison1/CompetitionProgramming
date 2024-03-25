#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int numCommands;
	cin >> numCommands;

	while (numCommands != 0) {
		vector<char> registers(32, '?');

		for (int cmd_i = 0; cmd_i < numCommands; cmd_i++) {
			string command;
			int numBits;
			cin >> command;
			
			int i, j;

			if (command == "SET") {
				cin >> i;
				
				registers[i] = '1';
			}

			if (command == "OR") {
				cin >> i >> j;
				
				if (registers[i] == '?' || registers[j] == '?') {
					registers[i] = registers[i] == '1' || registers[j] == '1' ? '1' : '?';
				} else {
					registers[i] = registers[i] == '1' || registers[j] == '1' ? '1' : '0';
				}
			}

			if (command == "AND") {
				cin >> i >> j;
				
				if (registers[i] == '?' || registers[j] == '?') {
					registers[i] = registers[i] == '0' || registers[j] == '0' ? '0' : '?';
				} else {
					registers[i] = registers[i] == '1' && registers[j] == '1' ? '1' : '0';
				}
			}

			if (command == "CLEAR") {
				cin >> i;
				
				registers[i] = '0';
			}
		}

		for (int i = 31; i >= 0; i--) {
			cout << registers[i];
		}
		cout << endl;

		cin >> numCommands;
	}

	return 0;
}