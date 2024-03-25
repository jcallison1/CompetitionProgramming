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

using namespace std;

#define lint long long int

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
    int datasets;
    cin >> datasets;

    for (int dataset = 0; dataset < datasets; dataset++)
    {
        int teams;
        cin >> teams;
		
        vector<int> scores(3 * teams);

        for (int j = 0; j < teams * 3; j++)
        {
            cin >> scores[j];
        }
        
		sort(scores.begin(), scores.end());
		
		lint sum = accumulate(scores.begin() + teams, scores.begin() + teams * 2, 0);
		
		cout << sum << endl;
    }
    
}