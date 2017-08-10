#include <iostream>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int x[2][400][400], y[2][400][400];
int grid[400][400], cnt[2][2];

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);
	for(int r = 0; r < n; r++) {
		string S;
		getline(cin, S);
		for(int c = 0; c < m; c++)
			grid[r][c] = S[c] == '0';
	}

	// x[0] for left count; x[1] for right count
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++) {
			if(grid[r][c] != 0)			
				x[0][r][c] = 1 + (c == 0 ? 0 : x[0][r][c - 1]);
		}
		for(int c = m - 1; c >= 0; c--) {
			if(grid[r][c] != 0) 
				x[1][r][c] = 1 + (c + 1 == m ? 0 : x[1][r][c + 1]);	
		}
	}
	// y[0] for above count; y[1] for below count
	for(int c = 0; c < m; c++) {
		for(int r = 0; r < n; r++) {
			if(grid[r][c] != 0)	
				y[0][r][c] = 1 + (r == 0 ? 0 : y[0][r - 1][c]);
		}
		for(int r = n - 1; r >= 0; r--) {
			if(grid[r][c] != 0)
				y[1][r][c] = 1 + (r + 1 == n ? 0 : y[1][r + 1][c]);
		}
	}

	int repeat = 0;
	int unique = 0;
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++) {
			if(!grid[r][c]) continue;
			for(int v : {0, 1} ) {
				for(int h : {0, 1} ) {
					int yD = v == 0 ? -1 : 1;
					int xD = h == 0 ? -1 : 1;
					int &C = cnt[v][h];
					cnt[v][h] = 0;
					int newR, newC;
					while( (newR = r + yD * (C + 1)) >= 0 and newR < n and 
						(newC = c + xD * (C + 1)) >= 0 and newC < m ) {
						if(!grid[newR][newC]) break;
						C++;
						if(y[v][r][newC] >= C and x[!h][r][newC] >= C)
							repeat++;
						if(y[!v][newR][c] >= C and x[h][newR][c] >= C)
							repeat++;
					}
				}
			}
			for(int i : {0, 1}) {
				int d = i == 0 ? -1 : 1;
				for(int j = 1; j <= min(cnt[0][i], cnt[1][i]); j++) {
					if(y[0][r][c + d * j] >= j + 1 and y[1][r][c + d * j] >= j + 1)
						unique++;
				}
				for(int j = 1; j <= min(cnt[i][0], cnt[i][1]); j++) {
					if(x[0][r + d * j][c] >= j + 1 and x[1][r + d * j][c] >= j + 1)
						unique++;
				}
			}
		}
	}
	cout << unique + repeat / 2 << endl;
}
