#include <iostream>
#include <vector>
#include <deque> 

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adjList(N + 1);
	for(int i = 0; i < M; i++) {
		int U, V;
		cin >> U >> V;
		adjList[U].push_back(V);
		adjList[V].push_back(U);
	}		
	
	int separated = 0;
	vector<bool> visited(N + 1);
	vector<int> prev(N + 1, -1);
	for(int i = 1; i <= N; i++) {
		if(visited[i]) continue;
		bool isTree = true;	
		deque<int> Q{i};
		visited[i] = 1;
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop_front();
			for(int x : adjList[curr]) {
				if(visited[x]) {
					if(prev[curr] != x) 
						isTree = false;
				}
				else {
					Q.push_back(x);
					visited[x] = true;
					prev[x] = curr;
				}
			}
		}
		separated += isTree;
	}

	cout << separated << endl;
}
