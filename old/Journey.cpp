#include <iostream>
#include <deque>
#include <utility>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> pii;
int n, m, T;	
vector<map<int, pii>> memo; // #nodes, ( cost, prev node )

void insert(int node, int length, int cost, int prev) {
	if(!memo[node].count(length) or memo[node][length].first > cost)
		memo[node][length] = make_pair(cost, prev);
}

int main() {
	cin >> n >> m >> T;
	vector<vector<pii>> adjList(n);
	vector<int> E(n);
	for(int i = 0; i < m; i++) {
		int u, v, t;		
		cin >> u >> v >> t;
		u--; v--;
		adjList[v].emplace_back(u, t);
		E[u]++;
	}
	memo.resize(n);
	deque<int> Q;
	for(int i = 0; i < n; i++)
		if(E[i] == 0) Q.push_back(i);
	while(!Q.empty()) {
		int curr = Q.front();
		Q.pop_front();
		for(pii prev : adjList[curr]) {
			int node = prev.first;
			int val = prev.second;
			if(curr == n - 1 and val <= T)
				insert(node, 1, val, curr);
			for(auto pair : memo[curr]) {
				if(pair.second.first + val <= T)
					insert(node, pair.first + 1, pair.second.first + val, curr);
			}
			if(--E[node] == 0)
				Q.push_back(node);			
		}
	}

	auto best = *(--memo[0].end());
	cout << best.first + 1 << endl;
	int numNodes = best.first;
	pii curr = best.second;
	int currNode = 0;
	while(numNodes--) {
		cout << currNode + 1 << " ";
		currNode = curr.second;
		curr = memo[currNode][numNodes];
	}
	cout << currNode + 1 << endl;
}
