#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, L, s, t;
vector<vector<int>> adjList;	
map<pii, ll> edges;
set<pii> S;

ll dijkstra() {
	vector<ll> dist(n, -1);	
	vector<int> prev(n, -1);
	priority_queue<pll, vector<pll>, greater<pll>> Q;
	Q.emplace(0, s);
	dist[s] = 0;
	while(!Q.empty()) {
		pll curr = Q.top();
		Q.pop();
		int node = curr.second;
		ll curr_dist = curr.first;
		if(curr_dist != dist[node])
			continue;
		for(int next : adjList[node]) {
			int edge_val = edges[make_pair(min(node, next), max(node, next))];
			if(dist[next] == -1 or curr_dist + edge_val < dist[next]) {
				dist[next] = curr_dist + edge_val;
				Q.emplace(curr_dist + edge_val, next);
				prev[next] = node;
			}
		}
	}
	if(dist[t] == -1 or dist[t] > L) 
		return -1;
	if(dist[t] == L)
		return 0;

	vector<pll> path;
	int curr = t;
	while(prev[curr] != -1) {
		pii temp = make_pair(min(curr, prev[curr]), max(curr, prev[curr]));
		if(S.count(temp))
			path.push_back(temp);	
		curr = prev[curr];
	}
	if(path.size() == 0)
		return -1;
	int val = L - dist[t];
	for(pll temp : path) {
		edges[temp] += val;
		break;
	}
	set<pll> not_S(path.begin(), path.end());
	for(pll curr : S) {
		if(!not_S.count(curr))
			edges[curr] = 1e10;
	}
	return dist[t];
}

int main() {
	cin >> n >> m >> L >> s >> t;
	adjList.resize(n);
	for(int i = 0; i < m; i++) {
		int u, v, w;	
		cin >> u >> v >> w;
		pii temp = make_pair(min(u, v), max(u, v));
		if(w == 0) {
			S.insert(temp);
			w++;
		}
		edges[temp] = w;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	while(true) {
		ll length = dijkstra();
		if(length == -1) {
			cout << "NO" << endl;
			return 0;
		}
		if(length == 0)
			break;
	}
	cout << "YES" << endl;
	for(auto x : edges)
		cout << x.first.first << " " << x.first.second << " " << x.second << endl;
}
