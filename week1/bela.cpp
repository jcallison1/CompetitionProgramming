#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<char, int> dominant {
        {'A', 11},
        {'K', 4},
        {'Q', 3},
        {'J', 20},
        {'T', 10},
        {'9', 14},
        {'8', 0},
        {'7', 0},
    };
    
    map<char, int> nondominant {
        {'A', 11},
        {'K', 4},
        {'Q', 3},
        {'J', 2},
        {'T', 10},
        {'9', 0},
        {'8', 0},
        {'7', 0},
    };
    
    int points = 0;
    
    int hands;
    char dom;
    
    cin >> hands >> dom;
    
    for (int i = 0; i < hands * 4; i++) {
        string card;
		cin >> card;
		
		if (card[1] == dom) {
			points += dominant[card[0]];
		} else {
			points += nondominant[card[0]];
		}
    }
    
	cout << points << endl;
	
    return 0;
}