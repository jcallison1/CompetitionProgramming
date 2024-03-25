#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <unordered_set>
#include <sstream>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

#define lint long long int

void multiply_matrix(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& out) {
	int dim = (int) a.size();
	
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			int sum = 0;
			
			for (int k = 0; k < dim; k++) {
				sum += a[i][k] * b[k][j];
			}
			
			out[i][j] = sum;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int dim;
	cin >> dim;
	
	vector<vector<int>> matrix(dim, vector<int>(dim, 0));
	
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cin >> matrix[j][i];
		}
	}
	
	// for (int i = 0; i < dim; i++) {
	// 	for (int j = 0; j < dim; j++) {
	// 		cerr << matrix[j][i] << " ";
	// 	}
		
	// 	cerr << endl;
	// }
	
	vector<vector<int>> square_matrix = matrix;
	multiply_matrix(matrix, matrix, square_matrix);
	
	vector<vector<int>> cube_matrix = matrix;
	multiply_matrix(square_matrix, matrix, cube_matrix);
	
	// for (int i = 0; i < dim; i++) {
	// 	for (int j = 0; j < dim; j++) {
	// 		cerr << cube_matrix[j][i] << " ";
	// 	}
		
	// 	cerr << endl;
	// }
	
	int trace = 0;
	
	for (int i = 0; i < dim; i++) {
		trace += cube_matrix[i][i];
	}
	
	cout << (trace / 6) << endl;
	
	return 0;
}