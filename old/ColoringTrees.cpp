#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

void set(ll &x, ll val) {
	if(x == -1)
		x = val;
	else if(val != -1)
		x = min(x, val);
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int C[n];
	for(int i = 0; i < n; i++)
		cin >> C[i];
	int cost[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cin >> cost[i][j];
	}
	ll memo[n][m + 1][k + 1];
	memset(memo, -1, sizeof(memo));
	for(int i = 0; i < n; i++) {
		int color = C[i];
		if(color == 0) {
			for(int c = 1; c <= m; c++) {
				if(i == 0) {
					memo[i][c][1] = cost[i][c - 1];
					continue;
				}
				for(int a = 1; a <= k; a++) {
					for(int b = 1; b <= m; b++) {
						if(b == c and memo[i - 1][b][a] != -1)
							set(memo[i][c][a], memo[i - 1][b][a] + cost[i][c - 1]);
						else if(b != c  and memo[i - 1][b][a - 1] != -1)
							set(memo[i][c][a], memo[i - 1][b][a - 1] + cost[i][c - 1]);
					}
				}
			}
		}
		else {
			if(i == 0)
				memo[i][color][1] = 0;
			else {
				for(int a = 1; a <= k; a++) {
					for(int b = 1; b <= m; b++) {
						if(b == color and memo[i - 1][b][a] != -1)
							set(memo[i][color][a], memo[i - 1][b][a]);
						else if(b != color and memo[i - 1][b][a - 1] != -1)
							set(memo[i][color][a], memo[i - 1][b][a - 1]);
					}
				}
			}
		}
	}
	ll result = -1;
	for(int color = 1; color <= m; color++) {
		if(memo[n - 1][color][k] != -1)
			set(result, memo[n - 1][color][k]);
	}
	cout << result << endl;
}
