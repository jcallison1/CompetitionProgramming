#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

tuple<int, int> letter_pos(char letter) {
	string rows[] = {
		"qwertyuiop",
		"asdfghjkl",
		"zxcvbnm"
	};
	
	for (int y = 0; y < 3; y++) {
		auto x = rows[y].find_first_of(letter);
		
		if (x != string::npos) {
			return {x, y};
		}
	}
	
	throw 0;
}

int score_word(string typed_word, string word) {
	int score = 0;
	
	for (int i = 0; i < typed_word.size(); i++) {
		char a = typed_word[i];
		char b = word[i];
		
		auto a_pos = letter_pos(a);
		auto b_pos = letter_pos(b);
		
		score += abs(get<0>(a_pos) - get<0>(b_pos)) + abs(get<1>(a_pos) - get<1>(b_pos));
	}
	
	return score;
}

int main() {
	int tests;
	cin >> tests;
	
	for (int test = 0; test < tests; test++) {
		string typed_word;
		int l;
		cin >> typed_word >> l;
		
		vector<string> list;
		
		for (int i = 0; i < l; i++) {
			string n;
			cin >> n;
			list.push_back(n);
		}
		
		stable_sort(list.begin(), list.end(), [&typed_word] (auto a, auto b) {
			auto a_score = score_word(typed_word, a);
			auto b_score = score_word(typed_word, b);
			
			return a_score == b_score ? a < b : a_score < b_score;
		});
		
		for (auto word : list) {
			cout << word << " " << score_word(typed_word, word) << endl;
		}
	}
    
    return 0;
}