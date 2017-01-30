#include <iostream>
#include <cstring>

using namespace std;

int n, m;
char grid[2000][2000];
char output[2000][2000];

bool draw(int R, int C, int l) {
	if(R < 0 or R + l > n) return false;
	if(C < 0 or C + l > m) return false;
	memcpy(output, grid, sizeof(grid));
	for(int c = C; c < C + l; c++) {
		if(output[R][c] != 'w') output[R][c] = '+';
		if(output[R + l - 1][c] != 'w') output[R + l - 1][c] = '+';
	}	
	for(int r = R; r < R + l; r++) {
		if(output[r][C] != 'w') output[r][C] = '+';
		if(output[r][C + l - 1] != 'w') output[r][C + l - 1] = '+';
	}

	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++) {
			if( (r == R or r == R + l - 1) and c >= C and c < C + l) continue;
			if( (c == C or c == C + l - 1) and r >= R and r < R + l) continue;
			if(output[r][c] == 'w') return false;
		}
	}

	return true;
}

int main() {
	cin >> n >> m;
	int t, b, l, r;
	t = b = l = r = -1;	
	for(int row = 0; row < n; row++) {
		for(int col = 0; col < m; col++) {
			cin >> grid[row][col];
			if(grid[row][col] == 'w') {
				if(t == -1) t = row;
				b = row;
				if(l == -1 or l > col) l = col;
				if(r == -1 or r < col) r = col;
			}
		}
	}

	int H = b - t + 1;	
	int W = r - l + 1;
	bool result = false;
	if(H == W)
		result = draw(t, l, H);
	else if(H > W) {
		result = draw(t, l, H);
		if(!result)
			result = draw(t, max(r - H + 1, 0), H);	
	}
	else {
		result = draw(t, l, W);
		if(!result)
			result = draw(max(b - W + 1, 0), l, W);
	}

	if(!result) {
		cout << -1 << endl;
		return 0;
	}
	for(int row = 0; row < n; row++) {
		for(int col = 0; col < m; col++)
			printf("%c", output[row][col]);
		printf("\n");
	}
}
