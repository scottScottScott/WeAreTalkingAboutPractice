#include <iostream>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
int pascal[4000 + 1][4000 + 1], dp[4000 + 1][4000 + 1];

int main() {
	int n;
	cin >> n;
	pascal[0][0] = 1;
	for(int r = 1; r <= n; r++) {
		for(int c = 0; c <= r; c++) {
			pascal[r][c] = (c > 0 ? pascal[r - 1][c - 1] : 0) + pascal[r - 1][c];	
			pascal[r][c] %= MOD;
		}
	}
	ll result = 0;
	dp[0][0] = 1;
	for(int i = 1; i < n; i++) {
		ll sum = 0;
		for(ll sets = 1; sets <= i; sets++) {
			ll temp = dp[i - 1][sets - 1] + sets * dp[i - 1][sets];
			dp[i][sets] = temp % MOD;
			sum += dp[i][sets];
			sum %= MOD;
		}
		result += sum * pascal[n][i];	
		result %= MOD;
	}		
	cout << result + 1 << endl;
}
