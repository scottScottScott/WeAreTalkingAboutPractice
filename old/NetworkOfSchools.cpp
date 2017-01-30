#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int N;
vector<vector<bool>> adj;
vector<int> visited;		
int min_notify;
stack<int> visitOrder;
map<int, int> node_to_scc;
int n;

void dfs(int x) {
	if(visited[x] == 2)
		min_notify--;
	visited[x] = 1;
	for(int i = 0; i < N; i++) {
		if(adj[x][i] && visited[i] != 1)
			dfs(i);
	}
}

void dfs_scc(int x) {
	visited[x] = 1;
	for(int i = 0; i < N; i++) {
		if(adj[x][i] && !visited[i]) 
			dfs_scc(i);
	}
	visitOrder.emplace(x);
}

void dfs_scc_reverse(int x) {
	visited[x] = 1;
	node_to_scc[x]= n;
	for(int i = 0; i < N; i++) {
		if(adj[i][x] && !visited[i]) 
			dfs_scc_reverse(i);
	}
}

int main() {
	ifstream fin("schlnet.in");
	ofstream fout("schlnet.out");

	fin >> N;
	adj.resize(N, vector<bool>(N));
	for(int i = 0; i < N; i++) {
		int next;
		fin >> next;
		while(next) {
			adj[i][next - 1] = 1;
			fin >> next;
		}
	}

	visited.resize(N);
	for(int i = 0; i < N; i++) {
		if(!visited[i]) {
			dfs(i);
			visited[i] = 2;
			for(int j = 0; j < N; j++) {
				if(visited[j] == 1)
					visited[j] = 3;
			}
			min_notify++;
		}
	}

	for(int i = 0; i < N; i++) {
		if(visited[i] == 2)
			cout << i + 1 << endl;
	}

	fill(visited.begin(), visited.end(), 0);
	for(int i = 0; i < N; i++) {
		if(!visited[i]) {
			dfs_scc(i);
		}
	}	

	fill(visited.begin(), visited.end(), 0);
	while(!visitOrder.empty()) {
		int curr_node = visitOrder.top();
		if(!visited[curr_node]) {
			dfs_scc_reverse(curr_node);
			n++;
		}
		visitOrder.pop();
	}

	vector<vector<int>> scc_adj(n, vector<int> (n));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(adj[i][j]) {
				int a = node_to_scc[i];
				int b = node_to_scc[j];
				scc_adj[a][b] = 1;
			}	
		}
	}	

	int startNodes = 0;
	int finishNodes = 0;
	for(int i = 0; i < n; i++) {
		bool isStart = true;
		for(int j = 0; j < n; j++) {
			if(scc_adj[j][i] && i != j)
				isStart = false;
		}
		startNodes += isStart;
	}
	for(int i = 0; i < n; i++) {
		bool isFinish = true;
		for(int j = 0; j < n; j++) {
			if(scc_adj[i][j] && i != j)
				isFinish = false;
		}
		finishNodes += isFinish;
	}

	fout << min_notify << endl;
	if(n == 1)
		fout << 0 << endl;
	else
		fout << max(startNodes, finishNodes) << endl;
}
