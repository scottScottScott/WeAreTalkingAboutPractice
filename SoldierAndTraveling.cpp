#include <iostream>
#include <deque>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
int N, M;
vector<int> A, B;

int maxFlow(vector<vector<int>> &adjList, vector<vector<int>> &residual) {
	int result = 0;
	bool hasFlow = true;
	while(hasFlow) {
		hasFlow = false;
		int last = -1;
		deque<int> Q;
		vector<int> prev(200, -1);
		for(int i = 0; i < N; i++) {
			if(A[i] > 0) {
				Q.push_back(i);
				prev[i] = i;
			}
		}
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop_front();
			if(curr < 100) {
				for(int x : adjList[curr]) {
					if(prev[x + 100] == -1) {
						prev[x + 100] = curr;
						Q.push_back(x + 100);
					}
				}
			}
			else {
				for(int x : adjList[curr - 100]) {
					if(residual[x][curr - 100] > 0 and prev[x] == -1) {
						prev[x] = curr;	
						Q.push_back(x);	
					}
				}
				if(B[curr - 100] > 0) {
					last = curr;
					hasFlow = true;
					break;
				}
			}
		}
		if(hasFlow) {
			int curr = last;
			int minVal = B[curr - 100];
			while(prev[curr] != curr) {
				if(prev[curr] >= 100)
					minVal = min(minVal, residual[curr][prev[curr] - 100]);
				curr = prev[curr];	
			}
			minVal = min(minVal, A[curr]);

			curr = last;
			B[curr - 100] -= minVal;
			while(prev[curr] != curr) {
				if(prev[curr] >= 100) residual[curr][prev[curr] - 100] -= minVal;
				else residual[prev[curr]][curr - 100] += minVal;
				curr = prev[curr];
			}
			A[curr] -= minVal;
			result += minVal;
		}
	}
	return result;
}

int main() {
	cin >> N >> M;
	A.resize(N);
	B.resize(N);
	for(int i = 0; i < N; i++)
		cin >> A[i];
	for(int i = 0; i < N; i++)
		cin >> B[i];

	vector<vector<int>> adjList(N);
	for(int i = 0; i < M; i++) {
		int U, V;
		cin >> U >> V;
		U--; V--;
		adjList[U].push_back(V);
		adjList[V].push_back(U);
	}
	for(int i = 0; i < N; i++)
		adjList[i].push_back(i);
	vector<vector<int>> residual(200, vector<int> (200));

	int result = accumulate(B.begin(), B.end(), 0);
	if(result == maxFlow(adjList, residual) and accumulate(A.begin(), A.end(), 0) == 0) {
		cout << "YES" << endl;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				printf("%d", residual[i][j]);
				printf(j + 1 == N ? "\n" : " ");
			} 
		}
	}
	else cout << "NO" << endl;
}
