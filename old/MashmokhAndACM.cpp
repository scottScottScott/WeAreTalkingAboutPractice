#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<ll>> memo(k, vector<ll>(n + 1));
	for(int i = 0; i < k; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == 0) memo[i][j] = 1;
			else {
				for(int k = j; k <= n; k += j) {
					memo[i][k] += memo[i - 1][j];	
					memo[i][k] %= MOD;
				}
			}
		}
	}
	ll solution = accumulate(memo[k - 1].begin(), memo[k - 1].end(), (ll) 0);
	cout << solution % MOD << endl;
}
