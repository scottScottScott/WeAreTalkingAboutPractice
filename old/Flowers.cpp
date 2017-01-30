#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAX = 1e5;

int main() {
	int t, k;
	cin >> t >> k;
	vector<ll> memo(MAX + 1);
	memo[0] = 1;
	for(int i = 1; i <= MAX; i++) {
		memo[i] += memo[i - 1];	
		if(i - k >= 0) 
			memo[i] += memo[i - k];
		memo[i] %= MOD;
	}
	vector<ll> prefixSum(MAX + 1);
	prefixSum[0] = 0;
	for(int i = 1; i <= MAX; i++)
		prefixSum[i] = prefixSum[i - 1] + memo[i];
	while(t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		ll result = prefixSum[b] - prefixSum[a - 1];
		cout << (result % MOD) << endl;
	}
}
