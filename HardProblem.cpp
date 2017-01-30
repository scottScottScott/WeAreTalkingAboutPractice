#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<vector<ll>> memo(n, vector<ll>(2, LLONG_MAX));
	vector<int> c(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	vector<string> a(n), b(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
		reverse(b[i].begin(), b[i].end());
	}
	memo[0][0] = 0;
	memo[0][1] = c[0];
	for(int i = 1; i < n; i++) {
		if(a[i - 1] <= a[i] and memo[i - 1][0] != LLONG_MAX)
			memo[i][0] = min(memo[i][0], memo[i - 1][0]);
		if(b[i - 1] <= a[i] and memo[i - 1][1] != LLONG_MAX)
			memo[i][0] = min(memo[i][0], memo[i - 1][1]);

		if(a[i - 1] <= b[i] and memo[i - 1][0] != LLONG_MAX)
			memo[i][1] = min(memo[i][1], memo[i - 1][0] + c[i]);
		if(b[i - 1] <= b[i] and memo[i - 1][1] != LLONG_MAX)
			memo[i][1] = min(memo[i][1], memo[i - 1][1] + c[i]);
	}
	ll result = LLONG_MAX;	
	result = min(result, memo[n - 1][0]);	
	result = min(result, memo[n - 1][1]);
	cout << (result == LLONG_MAX ? -1 : result) << endl;
}
