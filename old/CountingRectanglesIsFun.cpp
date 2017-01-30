#include <iostream>
#include <vector>

using namespace std;

int memo[40][40][40][40];

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	string temp;
	getline(cin, temp);
	vector<vector<int>> grid(n, vector<int>(m)), left(n, vector<int>(m));	
	for(int r = 0; r < n; r++) {
		getline(cin, temp);
		for(int c = 0; c < m; c++) {
			grid[r][c] = !(temp[c] - '0');
			if(grid[r][c] != 0)
				left[r][c] = 1 + (c == 0 ? 0 : left[r][c - 1]);
		}
	}

	for(int r1 = 0; r1 < n; r1++) {
		for(int r2 = r1; r2 < n; r2++) {
			for(int l = 0; l < m; l++) {
				for(int c1 = 0; c1 + l < m; c1++) {
					int c2 = c1 + l;
					int &count = memo[r1][c1][r2][c2];
					if(l == 0) {
						if(r1 == r2) count = grid[r1][c1];	
						else {
							count += memo[r1][c1][r2 - 1][c1];
							for(int r = r2; r >= r1; r--) {
								if(grid[r][c1] == 0) break;
								count++;
							}
						}
					}
					else {
						count += memo[r1][c1][r2][c2 - 1];
						count += memo[r1][c2][r2][c2];
						for(int R1 = r1; R1 <= r2; R1++) {
							int L = min(left[R1][c2 - 1], l);
							for(int R2 = R1; R2 <= r2; R2++) {
								L = min(L, left[R2][c2 - 1]);
								if(!grid[R2][c2]) break;
								count += L;
							}
						}
					}
				}
			}
		}
	}

	while(q--) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", memo[a - 1][b - 1][c - 1][d - 1]);
	}
}
