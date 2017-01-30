#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;

int main() {
	int r, g;	
	cin >> r >> g;
	int level = 1;
	int total = 0;
	vector<ll> memo(r + 1);
	memo[0] = 1;
	while(true) {
		bool valid = false;
		vector<ll> nmemo(r + 1, 0);
		for(int used = max(0, total - g); used <= min(total, r); used++) {
			memo[used] %= MOD;
			if(memo[used] == 0) continue;
			if(used + level <= r) {
				nmemo[used + level] += memo[used];
				valid = true;
			}
			if( (total - used) + level <= g) {
				nmemo[used] += memo[used];
				valid = true;
			}
		}
		if(valid == false) break;
		memo = move(nmemo);
		total += level;
		level++;
	}

	ll result = accumulate(memo.begin(), memo.end(), (ll) 0);
	cout << (result % MOD) << endl;
}
