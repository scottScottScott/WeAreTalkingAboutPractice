#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string eat;
	getline(cin, eat);
	vector<string> grid;
	for(int r = 0; r < n; r++) {
		string temp;
		getline(cin, temp);
		grid.push_back(temp);
	}

	int total = 0;
	vector<int> rowC(n);
	vector<int> colC(m);
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++) {
			if(grid[r][c] == '*') {
				rowC[r]++;
				colC[c]++;
				total++;
			}
		}
	}

	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++) {
			if(rowC[r] + colC[c] - (grid[r][c] == '*' ? 1 : 0) == total) {
				cout << "YES" << endl;
				cout << r + 1 << " " << c + 1 << endl;
				return 0;
			}
		}
	}

	cout << "NO" << endl;
}
