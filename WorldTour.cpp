#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <deque>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N, M;	
	cin >> N >> M;

	vector<vector<bool>> adjMat(N, vector<bool> (N));
	for(int i = 0; i < M; i++) {
		int U, V;
		cin >> U >> V;
		if(U != V)
			adjMat[--U][--V] = 1;	
	}
	vector<vector<int>> adjList(N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(adjMat[i][j])
				adjList[i].push_back(j);
		}
	}

	vector<vector<int>> dist(N, vector<int> (N, -1));
	for(int start = 0; start < N; start++) {
		deque<int> Q{start};
		dist[start][start] = 0;
		int steps = 1;
		while(!Q.empty()) {
			int A = Q.size();
			for(int a = 0; a < A; a++) {
				int curr = Q.front();
				Q.pop_front();
				for(int next : adjList[curr]) {
					if(dist[start][next] == -1) {
						dist[start][next] = steps;
						Q.push_back(next);
					}
				}	
			}
			steps++;
		}
	}

	vector<vector<pii>> forward(N);
	vector<vector<pii>> backward(N);

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(dist[i][j] != -1) {
				forward[i].emplace_back(dist[i][j], j);
				backward[j].emplace_back(dist[i][j], i);
			}	
		}
	}

	for(int i = 0; i < N; i++) {
		sort(forward[i].rbegin(), forward[i].rend());
		sort(backward[i].rbegin(), backward[i].rend());
	}

	int maxDist = 0;
	vector<int> solution;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(i == j or dist[i][j] == -1) continue;
			for(int k = 0; k < 2; k++) {
				int currDist = dist[i][j];	
				int a = -1;
				int b = -1;
		
				if(k == 0) {
					for(pii x : backward[i]) {
						if(x.second != i and x.second != j) {
							a = x.second;
							currDist += x.first;
							break;
						}
					}
					for(pii x : forward[j]) {
						if(x.second != i and x.second != j and x.second != a) {
							b = x.second;
							currDist += x.first;
							break;
						}
					}
				}
				else {
					for(pii x : forward[j]) {
						if(x.second != i and x.second != j) {
							b = x.second;
							currDist += x.first;
							break;
						}
					}
					for(pii x : backward[i]) {
						if(x.second != i and x.second != j and x.second != b) {
							a = x.second;
							currDist += x.first;
							break;
						}
					}
				}

				if(a != -1 and b != -1 and currDist > maxDist) {
					maxDist = max(currDist, maxDist);
					vector<int> temp {a, i, j, b};
					solution = temp;
				}
			}
		}
	}

	for(int i = 0; i < 4; i++) {
		cout << solution[i] + 1;
		cout << (i == 3 ? "\n" : " ");
	}
}
