#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pii>> adjList(n);
	for(int i = 0; i < m; i++) {
		int u, v, x;
		scanf("%d %d %d", &u, &v, &x);
		u--; v--;
		adjList[u].emplace_back(v, x);
		adjList[v].emplace_back(u, x);
	}
	int result = 0;
	vector<int> train(n, -1);
	for(int i = 0; i < k; i++) {
		int s, y;
		scanf("%d %d", &s, &y);
		s--;
		if(train[s] == -1)
			train[s] = y;
		else {
			result++;
			if(y < train[s])
				train[s] = y;
		}
	}
	vector<int> dist(n, -1);
	dist[0] = 0;
	train[0] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> Q;
	for(int i = 0; i < n; i++) {
		if(train[i] == -1) continue;
		for(pll x : adjList[i])
			Q.emplace(train[i] + x.second, x.first);
	}
	while(!Q.empty()) {
		pll curr = Q.top();
		Q.pop();
		if(dist[curr.second] != -1) continue;
		dist[curr.second] = curr.first;
		for(pll next : adjList[curr.second]) {
			if(dist[next.first] != -1) continue;
			Q.emplace(curr.first + next.second, next.first);
		}
	}
	for(int i = 1; i < n; i++) {
		if(train[i] != -1 and dist[i] <= train[i])
			result++;
	}	
	cout << result << endl;
}
