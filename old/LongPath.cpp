#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);	
	vector<int> memo(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}

	for(int i = 0; i < n; i++) {
		if(a[i] == i)
			memo[i] = 2;
		else {
			ll curr = accumulate(memo.begin() + a[i], memo.begin() + i, (ll) 0);
			curr += 2;
			memo[i] = curr % MOD;
		}
	}
	ll result = accumulate(memo.begin(), memo.end(), (ll) 0); 
	cout << result % MOD << endl;
}
