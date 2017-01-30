#include <iostream>
#include <cmath>
#include <queue>
#include <climits>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> tpl;

int main() {
	int N, M, K;
    cin >> N >> M >> K;
	vector<int> fishes(N);
	for(int i = 0; i < N; i++) {
		int T;
		cin >> T;
		int& val = fishes[i];
		for(int j = 0; j < T; j++) {
			int F;	
			cin >> F;
			F--;
			val |= (1 << F);
		}
	}
	vector<vector<pii>> adjMat(N);
	for(int i = 0; i < M; i++) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		X--;
		Y--;
		adjMat[X].emplace_back(Y, Z);	
		adjMat[Y].emplace_back(X, Z);
	}
    
	priority_queue<tpl, vector<tpl>, greater<tpl>> Q; 
	vector<vector<int>> memo(N, vector<int>(2048, INT_MAX));
	// distance, node, fish
	Q.emplace(0, 0, fishes[0]);
	memo[0][fishes[0]] = 0;
	while(!Q.empty()) {
		tpl curr = Q.top();
		Q.pop();
		int dist = get<0>(curr);
		int node = get<1>(curr);
		int fish = get<2>(curr);

		if(memo[node][fish] < dist) continue;
		memo[node][fish] = dist;
		for(pii nxt : adjMat[node]) {
			int nxt_fish = fishes[nxt.first] | fish;
			int nxt_dist = dist + nxt.second;
			if(nxt_dist < memo[nxt.first][nxt_fish])
				Q.emplace(nxt_dist, nxt.first, nxt_fish);
		}
	}

	int minDist = INT_MAX;
	int target = 0;
	for(int i = 0; i < K; i++)
		target |= 1 << i;

	for(int i = 0; i < pow(2, K); i++) {
		for(int j = 0; j < pow(2, K); j++) {
			if( (i | j) == target and memo[N - 1][i] != INT_MAX and memo[N - 1][j] != INT_MAX)
				minDist = min(minDist, max(memo[N - 1][i], memo[N - 1][j]));
        }
	}	

	cout << minDist << endl;
}
