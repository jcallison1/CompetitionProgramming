#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <deque>
#include <sstream>

using namespace std;

int main() {
	string attribs_line;
	getline(cin, attribs_line);
	
	stringstream attribs_line_s (attribs_line);
	vector<string> attribs;
	
	while (attribs_line_s) {
		string s;
		attribs_line_s >> s;
		if (attribs_line_s) attribs.push_back(s);
	}
	
	int song_count;
	cin >> song_count;
	
	vector<vector<string>> songs;
	
	for (int i = 0; i < song_count; i++) {
		vector<string> song;
		
		for (int j = 0; j < attribs.size(); j++) {
			string s;
			cin >> s;
			song.push_back(s);
		}
		
		songs.push_back(song);
	}
	
	int sorts;
	cin >> sorts;
	
	for (int i = 0; i < sorts; i++) {
		string sorting_attrib;
		cin >> sorting_attrib;
		
		int attrib_index = find(attribs.begin(), attribs.end(), sorting_attrib) - attribs.begin();
		
		stable_sort(songs.begin(), songs.end(), [attrib_index](auto a, auto b) {
			return a[attrib_index] < b[attrib_index];
		});
		
		cout << attribs_line << endl;
		
		for (auto song : songs) {
			for (int j = 0; j < song.size(); j++) {
				cout << song[j];
				if (j < song.size() - 1) cout << " ";
			}
			
			cout << endl;
		}
		
		if (i < sorts - 1) {
			cout << endl;
		}
	}
	
	return 0;
}