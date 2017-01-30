#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>

using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<unordered_set<int>> adjList(N + 1);
	for(int i = 0; i < M; i++) {
		int U, V;
		cin >> U >> V; 
		adjList[U].insert(V);
		adjList[V].insert(U);
	}
	unordered_set<int> S;
	for(int i = 2; i <= N; i++) S.insert(i);
	int components = 0;	
	vector<bool> visited(N + 1);
	for(int i = 2; i <= N; i++) {
		if(visited[i]) continue;
		visited[i] = true;
		components++;
		bool toRoot = false;
		deque<int> Q{i};	
		while(!Q.empty()) {
			int curr = Q.front();	
			Q.pop_front();
			if( !adjList[curr].count(1) ) toRoot = true;
			for(auto iter = S.begin(); iter != S.end(); ) {
				if(!adjList[curr].count(*iter)) {
					visited[*iter] = true;
					Q.push_back(*iter);
					iter = S.erase(iter);	
				}
				else iter++;
			}		
		}
		if(toRoot == false) {
			cout << "impossible" << endl;
			return 0;
		}
	}	
	cout << (components <= K and N - 1 - adjList[1].size() >= K ? "possible" : "impossible") << endl;
}
