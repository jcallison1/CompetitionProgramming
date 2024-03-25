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

using namespace std;

#define lint long long int

struct Line {
	int start_x, start_y;
	int end_x, end_y;
};

struct Vec {
	double x, y;
};

int main() {
	lint ascending_segments_count;
	lint descending_segments_count;
	
	cin >> ascending_segments_count >> descending_segments_count;
	
	// Vector to store positive change in elevation and time taken during ascent
	vector<Line> ascending_lines;

	// Vector to store negative change in elevation and time taken during descent
	vector<Line> descending_lines;
	
	int current_altitude = 0;
	int current_time = 0;
	
	// Input positive changes and ascent times
	for (lint i = 0; i < ascending_segments_count; i++) {
		int height, time;
		cin >> height >> time;
		
		ascending_lines.push_back({
			current_time, current_altitude,
			current_time + time, current_altitude + height,
		});
		
		current_time += time;
		current_altitude += height;
	}
	
	current_time = 0;
	
	// Input negative changes and descent times
	for (lint i = 0; i < descending_segments_count; i++) {
		int height, time;
		cin >> height >> time;
		
		descending_lines.push_back({
			current_time, current_altitude,
			current_time + time, current_altitude - height,
		});
		
		current_time += time;
		current_altitude -= height;
	}
	
	// Output the current altitude
	// cout << current_altitude << endl;
	
	double first_time = 1.0 / 0.0;
	
	for (auto line1 : ascending_lines) {
		for (auto line2 : descending_lines) {
			Vec dir1 = { (double) line1.end_x - line1.start_x, (double) line1.end_y - line1.start_y };
			Vec dir2 = { (double) line2.end_x - line2.start_x, (double) line2.end_y - line2.start_y };
			
			Vec c = { (double) line2.start_x - line1.start_x, (double) line2.start_y - line1.start_y };
			
			double d = dir1.x * -dir2.y - -dir2.x * dir1.y;
			double d1 = c.x * -dir2.y - -dir2.x * c.y;
			double d2 = dir1.x * c.y - c.x * dir1.y;
			
			if (d == 0.0) continue;
			
			double t = d1 / d;
			double s = d2 / d;
			
			if (t < 0.0 || t > 1.0 || s < 0.0 || s > 1.0) continue;
			
			// cerr << t << " " << s << endl;
			
			// cout << setprecision(12) << (line1.start_x + dir1.x * t) << endl;
			
			double sect_time = line1.start_x + dir1.x * t;
			
			if (sect_time < first_time) first_time = sect_time;
		}
	}
	
	cout << setprecision(12) << first_time << endl;

	return 0;
}