#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;

int main() {
	int n, h;
	cin >> n >> h;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<ll>> memo(n, vector<ll>(2000));	
	for(int i = 0; i < n; i++) {
		int open = h - a[i];
		if(i == 0) {
			if(open == 0) memo[i][0] = 1;
			else if(open == 1) {
				memo[i][0] = 1;
				memo[i][1] = 1;
			}
			continue;
		}
		if(open >= 0) {
			memo[i][open] = memo[i - 1][open]; // do nothing
			if(open - 1 >= 0)
				memo[i][open] += memo[i - 1][open - 1]; // open a new one
			if(open - 2 >= 0)
				memo[i][open - 1] += memo[i - 1][open - 2] * (open - 2); // close and open
			memo[i][open] %= MOD;
		}
		if(open - 1 >= 0) {
			memo[i][open - 1] = memo[i - 1][open] * open; // close existing open
			memo[i][open - 1] += memo[i - 1][open - 1] * open; // open and close
			memo[i][open - 1] %= MOD;
		}
	}

	cout << memo[n - 1][0] << endl;
}
