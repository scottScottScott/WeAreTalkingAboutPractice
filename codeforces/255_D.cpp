#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	int n, m, k, p;	
	cin >> n >> m >> k >> p;
	vector<int> row(n), col(m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int temp;
			scanf("%d", &temp);
			row[i] += temp; 
			col[j] += temp; 
		}
	}
	vector<ll> memo(k + 1);
	memo[0] = 0;
	priority_queue<int, vector<int>, less<int>> Q;
	for(int x : col) Q.push(x);
	for(int i = 1; i <= k; i++) {
		int maxVal = Q.top();
		Q.pop();
		memo[i] = memo[i - 1] + maxVal;
		Q.push(maxVal - p * n);	
	}
	while(!Q.empty()) Q.pop();
	
	for(int x : row) Q.push(x);
	ll curr = 0;
	ll result = memo[k];
	for(int i = 1; i <= k; i++) {
		int maxVal = Q.top();	
		Q.pop();
		curr += maxVal;
		result = max(result, memo[k - i] + curr - (ll) (k - i) * p * i);
		Q.push(maxVal - p * m);
	}
	cout << result << endl;
}
