#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> P, S, R;

int getP(int x) {
	if(P[x] != x)
		P[x] = getP(P[x]);	
	return P[x];
}

void merge(int x, int y) {
	if(R[x] > R[y]) {
		P[y] = x;
		S[x] += S[y];
	}
	else {
		if(R[x] == R[y])
			R[y]++;
		P[x] = y;
		S[y] += S[x];
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	priority_queue<pii, vector<pii>, less<pii>> Q;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);	
		Q.emplace(a[i], i);
	}
	vector<vector<int>> adjList(n);
	for(int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--; y--;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}
	P.resize(n);
	S.resize(n, 1);
	R.resize(n);
	for(int i = 0; i < n; i++)
		P[i] = i;
	double total = 0;
	double denom = (ll) n * (n - 1) / 2;
	while(!Q.empty()) {
		pii curr = Q.top();
		Q.pop();
		ll temp = S[getP(curr.second)];
		ll temp2 = (ll) S[getP(curr.second)] * S[getP(curr.second)];
		for(int x : adjList[curr.second]) {
			if(a[x] >= curr.first and getP(x) != getP(curr.second)) {
				temp += S[getP(x)];
				temp2 += (ll) S[getP(x)] * S[getP(x)];
				merge(getP(x), getP(curr.second));
			}
		}
		ll result = (temp * temp - temp2) / 2;
		total += (curr.first / denom) * result;
	}
	printf("%.10f\n", total);
}
