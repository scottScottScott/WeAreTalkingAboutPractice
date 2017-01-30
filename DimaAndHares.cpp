#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0; i < n; i++)
		cin >> c[i];
	vector<vector<int>> memo(n, vector<int>(2, -1));
	memo[0][0] = a[0];
	for(int i = 1; i < n; i++) {
		memo[i][1] = max(memo[i - 1][1], memo[i - 1][0]) + b[i];
		int pval = i - 2 < 0 ? 0 : max(memo[i - 2][0], memo[i - 2][1]);
		memo[i][0] = pval + a[i] + (i == 1 ? b[i - 1] : c[i - 1]);
		if(memo[i - 1][1] != -1)
			memo[i][0] = max(memo[i][0], memo[i - 1][1] - b[i - 1] + c[i - 1] + a[i]);		
		memo[i][0] = max(memo[i][0], memo[i - 1][0] - a[i - 1] + b[i - 1] + a[i]);		
	}
	cout << max(memo[n - 1][0], memo[n - 1][1]) << endl;
}
