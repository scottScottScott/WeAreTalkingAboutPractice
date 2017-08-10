#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges(n), type(n);
	int colors = 1;
	for(int i = 0; i < n; i++) {
		int s;
		scanf("%d", &s);
		for(int j = 0; j < s; j++) {
			int temp;
			scanf("%d", &temp);
			type[i].push_back(temp);
		}
		colors = max(colors, (int) type[i].size());
	}
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		edges[u].push_back(v);	
		edges[v].push_back(u);
	}
	int start = 0;
	for(int i = 0; i < n; i++) {
		if(edges[i].size() == 1) {
			start = i;
			break;
		}
	}
	vector<int> C(m + 1, -1);
	vector<bool> V(n);
	V[start] = 1;
	deque<int> Q{start};
	while(!Q.empty()) {
		int curr = Q.front();
		Q.pop_front();
		vector<bool> used(colors + 1);
		for(int x : type[curr]) {
			if(C[x] != -1)
				used[C[x]] = 1;
		}
		int j = 1;
		for(int x : type[curr]) {
			if(C[x] == -1) {
				while(used[j]) j++;
				C[x] = j++;
			}
		}
		for(int y : edges[curr]) {
			if(!V[y]) {
				Q.push_back(y);
				V[y] = true;
			}
		}
	}
	cout << colors << endl;
	for(int i = 1; i <= m; i++) {
		if(C[i] == -1) C[i] = 1;
		printf("%d", C[i]);
		printf(i == m ? "\n" : " ");
	}
}
