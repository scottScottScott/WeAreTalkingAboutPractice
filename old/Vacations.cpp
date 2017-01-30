#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> memo(n + 1, vector<int> (3, INT_MAX));
	memo[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		int best = memo[i - 1][0];
		best = min(best, memo[i - 1][1]);
		best = min(best, memo[i - 1][2]);
		memo[i][0] = best != INT_MAX ? best + 1 : INT_MAX;

		if(a == 1 or a == 3) {
			int best = memo[i - 1][0];
			best = min(best, memo[i - 1][2]);
			memo[i][1] = best;
		}
		if(a == 2 or a == 3) {
			int best = memo[i - 1][0];
			best = min(best, memo[i - 1][1]);
			memo[i][2] = best;
		}
	}
	int result = memo[n][0];
	result = min(result, memo[n][1]);
	result = min(result, memo[n][2]);
	cout << result << endl;
}
