#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pll> il(n), b(m);
	deque<vector<ll>> gaps(n - 1);
	for(int i = 0; i < n; i++)
		scanf("%I64d %I64ld", &il[i].first, &il[i].second);
	for(int i = 1; i < n; i++)
		gaps[i - 1] = vector<ll>{il[i].first - il[i - 1].second, il[i].second - il[i - 1].first, i - 1};	
	for(int i = 0; i < m; i++) {
		scanf("%I64ld", &b[i].first);
		b[i].second = i + 1;
	}
	sort(b.begin(), b.end());
	sort(gaps.begin(), gaps.end());
	vector<int> memo(n - 1);
	priority_queue<pll, vector<pll>, greater<pll>> Q;
	for(int i = 0; i < b.size(); i++) {
		while(!gaps.empty() and b[i].first >= gaps.front()[0]) {
			vector<ll> temp = gaps.front();
			Q.emplace(temp[1], temp[2]);
			gaps.pop_front();
		}
		if(Q.empty()) continue;
		if(Q.top().first < b[i].first) {
			cout << "No" << endl;
			return 0;
		}
		pll curr = Q.top();
		Q.pop();
		memo[curr.second] = b[i].second;
	}
	if(!Q.empty() or !gaps.empty()) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for(int i = 0; i < n - 1; i++) {
		printf("%d", memo[i]);
		printf(i + 1 == n - 1 ? "\n" : " ");
	}
}
