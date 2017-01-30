#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("bigbrn.in");
	ofstream fout("bigbrn.out");

	int N, T;
	fin >> N >> T;
	vector<vector<char>> grid(N, vector<char>(N, '.'));
	for(int i = 0; i < T; i++) {
		int a, b;
		fin >> a >> b;
		grid[--a][--b] = '#';
	}

	vector<vector<int>> below(N, vector<int>(N));
	for(int i = N - 1; i >= 0; i--) {
		for(int j = 0; j < N; j++) {
			if(grid[i][j] == '#')
				below[i][j] = 0;
			else if(i == N - 1)
				below[i][j] = 1;	
			else 
				below[i][j] = below[i + 1][j] + 1;
		}
	}

	vector<vector<int>> right(N, vector<int>(N));
	for(int i = 0; i < N; i++) {
		for(int j = N - 1; j >= 0; j--) {
			if(grid[i][j] == '#')
				right[i][j] = 0;
			else if(j == N - 1)
				right[i][j] = 1;	
			else 
				right[i][j] = right[i][j + 1] + 1;
		}
	}

	int maxSquare = 0;
	vector<vector<int>> square_size(N, vector<int>(N));
	for(int i = N - 1; i >= 0 ; i--) {
		for(int j = N - 1; j >= 0; j--) {
			if(i + 1 >= N || j + 1 >= N) {
				if(grid[i][j] == '#')
					square_size[i][j] = 0;
				else
					square_size[i][j] = 1;
			}
			else {
				int square_val = square_size[i + 1][j + 1] + 1;
				square_val = min(right[i][j], square_val);
				square_val = min(below[i][j], square_val);
				square_size[i][j] = square_val;
			}
			maxSquare = max(maxSquare, square_size[i][j]);
		}
	}

	fout << maxSquare << endl;
}
