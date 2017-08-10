#include <iostream>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adjList(n);
	vector<bool> loop(n), hasEdge(n);
	ll numLoops = 0;
	int start = 0;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		hasEdge[u] = hasEdge[v] = 1;
		start = u;
		if(u == v) {
			loop[u] = 1;
			numLoops++;
		}
		else {
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
	}

	vector<bool> V(n);
	deque<int> Q{start};
	V[start] = 1;
	while(!Q.empty()) {
		int curr = Q.front();
		Q.pop_front();
		for(int x : adjList[curr]) {
			if(!V[x]) {
				V[x] = 1;
				Q.push_back(x);
			}
		}
	}
	bool valid = true;
	for(int i = 0; i < n; i++) {
		if(V[i] == 0 and hasEdge[i]) 
			valid = false;
	}
	if(!valid) {
		cout << 0 << endl;
		return 0;
	}
	ll result = numLoops * (numLoops - 1) / 2;
	result += numLoops * (m - numLoops);
	for(int i = 0; i < n; i++)
		result += (ll) adjList[i].size() * (adjList[i].size() - 1) / 2;
	cout << result << endl;
}
