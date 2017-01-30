#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> rows(N);
	vector<int> columns(M);
	vector<vector<int>> matrix(N, vector<int> (M));
	vector<vector<int>> row_adjList(N);
	vector<vector<int>> col_adjList(M);
	
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	for(int i = 0; i < N * M; i++) {
		int A;
		cin >> A;
		Q.emplace(A, i);			
	}

	while(!Q.empty()) {
		pii curr = Q.top();
		Q.pop();
		int A = curr.first;
		vector<pii> Same { {curr.second / M, curr.second % M} };
		while(!Q.empty() and Q.top().first == A) {
			Same.emplace_back(Q.top().second / M, Q.top().second % M);	
			Q.pop();
		}

		vector<bool> visited(Same.size());
		for(int i = 0; i < Same.size(); i++) {
			pii X = Same[i];
			row_adjList[X.first].push_back(i);
			col_adjList[X.second].push_back(i);	
		}
			
		for(int i = 0; i < Same.size(); i++) {
			if(visited[i] == 1) continue;
			visited[i] = 1;
			vector<pii> component {Same[i]};
			deque<int> Q {i};
			while(!Q.empty()) {
				int curr_i = Q.front();
				Q.pop_front();
				pii X = Same[curr_i];
				for(int Y : row_adjList[X.first]) {
					if(visited[Y] == 0) {
						visited[Y] = 1;
						component.push_back(Same[Y]);
						Q.push_back(Y);
					}
				}
				row_adjList[X.first].clear();
				for(int Y : col_adjList[X.second]) {
					if(visited[Y] == 0) {
						visited[Y] = 1;
						component.push_back(Same[Y]);
						Q.push_back(Y);
					}
				}
				col_adjList[X.second].clear();
			}	
			int maxVal = 0;
			for(pii X : component) {
				maxVal = max(maxVal, rows[X.first] + 1);
				maxVal = max(maxVal, columns[X.second] + 1);
			}
			for(pii X : component) {
				matrix[X.first][X.second] = maxVal;
				columns[X.second] = rows[X.first] = maxVal;
			}
		}
	}

	for(int r = 0; r < N; r++) {
		for(int c = 0; c < M; c++) {
			if(c != 0) cout << " ";
			cout << matrix[r][c];
		}
		cout << '\n';
	}
}
