#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int main() {
	int a, b, k, t;	
	cin >> a >> b >> k >> t;
	int start = a - b;
	int maxIdx = 2 * k * 2 * t;
	vector<int> memo(maxIdx + 1);
	const int zero = k * 2 * t;
	memo[zero] = 1;
	for(int turn = 1; turn <= 2 * t; turn++) {
		vector<int> prev = memo;	
		ll sum = 0;
		for(int i = zero - k * turn; i <= zero + k * turn; i++) {
			memo[i] = (memo[i] + sum) % MOD;
			sum += prev[i];
			if(i >= k) sum -= prev[i - k];	
			sum = (sum + MOD) % MOD;
		}
		for(int i = zero + k * turn; i >= zero - k * turn; i--) {
			memo[i] = (memo[i] + sum) % MOD;
			sum += prev[i];
			if(i <= maxIdx - k) sum -= prev[i + k];
			sum = (sum + MOD) % MOD;
		}
	}
	ll result = 0;
	for(int i = zero - start + 1; i <= maxIdx; i++)
		result = (result + memo[i]) % MOD;
	cout << result << endl;
}
