#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <deque>

using namespace std;

typedef pair<int, int> pii;

pii getRoot(pii curr, vector<vector<pii>> &parent) {
	pii &curr_parent = parent[curr.first][curr.second];
	if(curr != curr_parent)
		curr_parent = getRoot(curr_parent, parent);	
	return curr_parent;
}

void merge(pii A, pii B, vector<vector<pii>> &parent, vector<vector<int>> &rank, vector<vector<int>> &size) {
	if(A == B) return;	
	if(rank[A.first][A.second] > rank[B.first][B.second]) {
		parent[B.first][B.second] = A;
		size[A.first][A.second] += size[B.first][B.second];
	}
	else {
		parent[A.first][A.second] = B;
		size[B.first][B.second] += size[A.first][A.second];
		if(rank[A.first][A.second] == rank[B.first][B.second])
			rank[B.first][B.second]++;
	}
}

void Union(pii A, pii B, vector<vector<pii>> &parent, vector<vector<int>> &rank, vector<vector<int>> &size) {
	merge(getRoot(A, parent), getRoot(B, parent), parent, rank, size);
}

int main() {
	ios::sync_with_stdio(false);
	int N, M;
	long long k;
	cin >> N >> M >> k;

	vector<vector<int>> val(N, vector<int>(M));
	vector<vector<pii>> parent(N, vector<pii>(M));
	vector<vector<int>> rank(N, vector<int>(M));
	vector<vector<int>> size(N, vector<int>(M));
	vector<vector<int>> heights;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> val[i][j];	
			parent[i][j] = make_pair(i, j);
			size[i][j] = 1;
			heights.push_back(vector<int> {val[i][j], i, j});
		}
	}

	sort(heights.rbegin(), heights.rend());

	for(vector<int> height : heights) {
		pii curr { height[1], height[2] };
		vector<pii> adjacent = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };	
		for(pii x : adjacent) {
			pii temp {x.first + curr.first, x.second + curr.second};
			if(temp.first < 0 or temp.first >= N or temp.second < 0 or temp.second >= M) continue;
			pii temp_root = getRoot(temp, parent);
			if(val[temp_root.first][temp_root.second] >= height[0]) {
				Union(curr, temp_root, parent, rank, size);
				pii root = getRoot(curr, parent);
				val[root.first][root.second] = height[0];
			}
		}
		pii root = getRoot(curr, parent);
		if(k % height[0] == 0 and size[root.first][root.second] >= k / height[0]) {
			vector<vector<int>> printOut(N, vector<int> (M));
			int count = k / height[0];
			deque<pii> Q {curr};			
			val[curr.first][curr.second] = 0;
			while(count > 0) {
				pii temp = Q.front();
				Q.pop_front();
				count--;	
				printOut[temp.first][temp.second] = height[0];	
				for(pii x : adjacent) {
					pii next {x.first + temp.first, x.second + temp.second};
					if(next.first < 0 or next.first >= N or next.second < 0 or next.second >= M) continue;
					if(val[next.first][next.second] >= height[0]) {
						val[next.first][next.second] = 0;	
						Q.push_back(next);
					}
				}
			}

			cout << "YES" << endl;
			for(int r = 0; r < N; r++) {
				for(int c = 0; c < M; c++) {
					if(c != 0) cout << " ";
					cout << printOut[r][c];
				}
				cout << endl;
			}
			return 0;
		}
	}

	cout << "NO" << endl;
}
