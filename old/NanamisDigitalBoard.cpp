#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 1000 + 2;
int grid[MAX][MAX];
int D[2][MAX][MAX];
int R[2][MAX][MAX];
int n, m, q;

void calculate() {
	for(pii temp : vector<pii> {make_pair(m, -1), make_pair(1, 1)}) {
		int idx = temp.second == -1 ? 0 : 1;
		for(int c = temp.first; c > 0 and c <= m; c += temp.second) {
			for(int r = 1; r <= n; r++) {
				R[idx][r][c] = 0;
				if(grid[r][c])	
					R[idx][r][c] = 1 + R[idx][r][c - temp.second];	
			}
		}
	}
	for(pii temp : vector<pii> {make_pair(n, -1), make_pair(1, 1)}) {
		int idx = temp.second == -1 ? 0 : 1;
		for(int r = temp.first; r > 0 and r <= n; r += temp.second) {
			for(int c = 1; c <= m; c++) {
				D[idx][r][c] = 0;
				if(grid[r][c])
					D[idx][r][c] = 1 + D[idx][r - temp.second][c];
			}
		}
	}
}

void calculate(int x, int y) {
	for(pii temp : vector<pii> {make_pair(m, -1), make_pair(1, 1)}) {
		int idx = temp.second == -1 ? 0 : 1;
		for(int c = temp.first; c > 0 and c <= m; c += temp.second) {
			R[idx][x][c] = 0;
			if(grid[x][c])	
				R[idx][x][c] = 1 + R[idx][x][c - temp.second];	
		}
	}
	for(pii temp : vector<pii> {make_pair(n, -1), make_pair(1, 1)}) {
		int idx = temp.second == -1 ? 0 : 1;
		for(int r = temp.first; r > 0 and r <= n; r += temp.second) {
			D[idx][r][y] = 0;
			if(grid[r][y])
				D[idx][r][y] = 1 + D[idx][r - temp.second][y];
		}
	}
}


int main() {
	cin >> n >> m >> q;
	for(int r = 1; r <= n; r++) {
		for(int c = 1; c <= m; c++)
			scanf("%d", &grid[r][c]);
	}
	calculate();
	while(q--) {
		int op, x, y;
		cin >> op >> x >> y;
		if(op == 1) {
			grid[x][y] = !grid[x][y];
			calculate(x, y);
		}
		else {
			int result = 0;
			for(int i = 0; i <= 1; i++) {
				int top = x - 1;
				int bottom = x + 1;
				int width = 1;
				int length = R[i][x][y];
				result = max(result, width * length);
				while(top >= 1 or bottom <= n) {
					width++;
					if(top >= 1 and (bottom > n or R[i][top][y] > R[i][bottom][y])) {
						length = min(length, R[i][top][y]);		
						top--;
					}
					else {
						length = min(length, R[i][bottom][y]);
						bottom++;
					}
					result = max(result, width * length);
				}
			}
			for(int i = 0; i <= 1; i++) {
				int back = y - 1;
				int front = y + 1;
				int width = 1;
				int length = D[i][x][y];
				result = max(result, width * length);
				while(back >= 1 or front <= m) {
					width++;
					if(back >= 1 and (front > m or D[i][x][back] > D[i][x][front])) {
						length = min(length, D[i][x][back]);	
						back--;
					}
					else {
						length = min(length, D[i][x][front]);
						front++;
					}
					result = max(result, width * length);
				}
			}
			printf("%d\n", result);
		}
	}
}
