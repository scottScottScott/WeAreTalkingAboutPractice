#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adjList(N);
	for(int i = 0; i < M; i++) {
		int U, V;
		scanf("%d %d", &U, &V);
		U--; V--;
		adjList[U].push_back(V);
		adjList[V].push_back(U);
	}

	vector<int> color(N);	
	for(int i = 0; i < N; i++) {
		if(color[i] != 0) continue;
		deque<int> Q{i};
		color[i] = 1;
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop_front();
			for(int next : adjList[curr]) {
				if(color[next] != 0) {
					if(color[next] == color[curr]) {
						cout << -1 << endl;
						return 0;
					}	
				}
				else {
					if(color[curr] == 1) color[next] = 2;
					if(color[curr] == 2) color[next] = 1;
					Q.push_back(next);
				}
			}
		}
	}

	vector<vector<int>> C(2);
	for(int i = 0; i < N; i++) {
		if(color[i] == 1) C[0].push_back(i);
		else if(color[i] == 2) C[1].push_back(i);
	}

	for(int i = 0; i < 2; i++) {
		cout << C[i].size() << endl;
		for(int j = 0; j < C[i].size(); j++) {
			if(j != 0) printf(" ");
			printf("%d", C[i][j] + 1);
		}
		printf("\n");
	}
}
