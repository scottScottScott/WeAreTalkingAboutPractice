#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> A(n, vector<int> (m));
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++)
			scanf("%d", &A[r][c]);	
	}
	vector<vector<vector<int>>> M(4, A);
	int idx = 0;
	for(int x : vector<int> {1, -1}) {
		for(int y : vector<int> {1, -1}) {
			int r = y == 1 ? 0 : n - 1;
			for( ; r < n and r >= 0; r += y) {
				for(int c = (x == 1 ? 0 : m - 1) ; c < m and c >= 0; c += x) {
					int t1 = c - x >= 0 and c - x < m ? M[idx][r][c - x] : 0;
					int t2 = r - y >= 0 and r - y < n ? M[idx][r - y][c] : 0;
					M[idx][r][c] += max(t1, t2);
				}
			}
			idx++;
		}
	}
	int result = 0;
	for(int r = 1; r < n - 1; r++) {
		for(int c = 1; c < m - 1; c++) {
			int val1 = M[0][r][c - 1] + M[3][r][c + 1] + M[1][r + 1][c] + M[2][r - 1][c];
			int val2 = M[0][r - 1][c] + M[3][r + 1][c] + M[1][r][c - 1] + M[2][r][c + 1];
			result = max(result, val1);
			result = max(result, val2);
		}
	}
	cout << result << endl;
}
