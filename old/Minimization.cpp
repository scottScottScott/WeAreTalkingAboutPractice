#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	int length = n / k;
	int hiCnt = n % k;
	int loCnt = k - hiCnt;
	vector<vector<ll>> memo(hiCnt + 1, vector<ll> (loCnt + 1, LLONG_MAX));
	memo[0][0] = 0;
	for(int i = 0; i <= hiCnt; i++) {
		for(int j = 0; j <= loCnt; j++) {
			int start = i * (length + 1) + j * length;
			if(i != hiCnt)
				memo[i + 1][j] = min(memo[i + 1][j], memo[i][j] + a[start + length] - a[start]);
			if(j != loCnt)
				memo[i][j + 1] = min(memo[i][j + 1], memo[i][j] + a[start + length - 1] - a[start]);
		}
	}
	cout << memo[hiCnt][loCnt] << endl;
}
