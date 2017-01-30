#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> A;
vector<pii> range;
int n, m;

int getPath(int L, int R) {
	priority_queue<pii, vector<pii>, less<pii>> Q;
	Q.emplace(R, 0);
	vector<int> memo(n, 0);
	while(!Q.empty()) {
		pii P = Q.top();
		Q.pop();
		int curr = P.second;
		R = P.first;
		if(memo[curr] != 0) continue;
		memo[curr] = R;
		if(curr == n - 1) break;
		for(pii nP : A[curr]) {
			int next = nP.first;	
			int i = nP.second;
			if(range[i].first > L or range[i].second < L) continue;
			int nR = min(R, range[i].second);
			Q.emplace(nR, next);
		}
	}
	return memo[n - 1] - L + 1;
}

int main() {
	cin >> n >> m;
	A.resize(n);
	for(int i = 0; i < m; i++) {
		int a, b, l, r;	
		scanf("%d %d %d %d", &a, &b, &l, &r);
		a--; b--;
		A[a].emplace_back(b, i);
		A[b].emplace_back(a, i);
		range.emplace_back(l, r);
	}
	int result = 0;
	for(pii curr : range) {
		int temp = getPath(curr.first, curr.second);	
		result = max(result, temp);
	}
	cout << (result == 0 ? "Nice work, Dima!" : to_string(result)) << endl;
}
