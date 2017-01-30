#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

typedef long long ll;
		
int cost[3][3];
vector<vector<ll>> memo, P;

void dijkstra(int start) {
	vector<vector<ll>> state(3, vector<ll>(3, -1));
	deque<vector<ll>> Q; 
	Q.push_back( vector<ll> {0, start, start});
	state[start][start] = 0;
	while(!Q.empty()) {
		vector<ll> curr = Q.front();
		ll val = curr[0];
		int top = curr[1];
		int bottom = curr[2];
		Q.pop_front();
		if(state[top][bottom] != val)
			continue;
		if(top == bottom) memo[start][top] = val;
		for(int i = 0; i < 3; i++) {
			if(state[i][bottom] == -1 or val + P[top][i] < state[i][bottom]) {
				state[i][bottom] = val + P[top][i]; 
				Q.push_back(vector<ll> {state[i][bottom], i, bottom});
			}
			if(i != top and bottom != top and (state[top][i] == -1 or val + cost[bottom][i] < state[top][i])) {
				state[top][i] = val + cost[bottom][i];
				Q.push_back(vector<ll> {state[top][i], top, i});
			}
		}
		sort(Q.begin(), Q.end());
	}
}

int main() {
	memo.resize(3, vector<ll>(3));
	for(int r = 0; r < 3; r++) {
		for(int c = 0; c < 3; c++) {
			cin >> memo[r][c];
			cost[r][c] = memo[r][c];
		}
	}

	int n;
	cin >> n;

	if(n == 1) {
	for(int d = 0; d < 3; d++) {
		for(int s = 0; s < 3; s++) {
			for(int t = 0; t < 3; t++) {
				if(cost[s][t] > cost[s][d] + cost[d][t]) {
					cost[s][t] = cost[s][d] + cost[d][t]; 	
					memo[s][t] = cost[s][t];
				}
			}
		}
	}
	}

	for(int i = 2; i <= n; i++) {
		P = memo;
		for(int start = 0; start < 3; start++)
			dijkstra(start);
	}
	cout << memo[0][2] << endl;
}
