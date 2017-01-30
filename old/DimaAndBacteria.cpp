#include <iostream>
#include <deque>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> count, type;
	for(int i = 0; i < k; i++) {
		int temp;
		scanf("%d", &temp);
		count.push_back(temp);
		for(int j = 0; j < temp; j++)
			type.push_back(i);
	}
	vector<vector<int>> al(n);
	vector<vector<int>> dist(k, vector<int>(k, -1));
	for(int i = 0; i < m; i++) {
		int u, v, x;
		scanf("%d %d %d", &u, &v, &x);
		u--, v--;
		if(x == 0) {
			al[u].push_back(v);
			al[v].push_back(u);
		}

		u = type[u];
		v = type[v];
		if(dist[u][v] == -1 or x < dist[u][v]) {
			dist[u][v] = x;
			dist[v][u] = x;
		}
	}
	vector<bool> V(n);	
	for(int i = 0; i < n; i++) {
		if(V[i]) continue;
		V[i] = 1;
		unordered_set<int> S;
		count[type[i]]--;
		S.insert(type[i]);
		deque<int> Q{i};
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop_front();
			for(int next : al[curr]) {
				if(V[next]) continue;
				V[next] = 1;
				Q.push_back(next);
				count[type[next]]--;
				S.insert(type[next]);
			}
		}
		for(int x : S) {
			if(count[x] != 0) {
				cout << "No" << endl;
				return 0;
			}
		}
	}

	for(int i = 0; i < k; i++)	
		dist[i][i] = 0;
	for(int K = 0; K < k; K++) {
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < k; j++) {
				if(dist[i][K] == -1 or dist[K][j] == -1) continue;
				if(dist[i][j] == -1 or dist[i][j] > dist[i][K] + dist[K][j])
					dist[i][j] = dist[i][K] + dist[K][j];
			}
		}
	}

	cout << "Yes" << endl;
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < k; j++)
			cout << dist[i][j] << (j + 1 == k ? "\n" : " ");
	}
}
