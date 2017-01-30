#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, long long> pil;

vector<vector<pil>> adjList;
int N;

void getSum(int start, vector<long long> &dist) {
	vector<bool> V(N);
	deque<int> Q {start};
	V[start] = 1;
	while(!Q.empty()) {
		int curr = Q.front();
		Q.pop_front();
		for(pil next : adjList[curr]) {
			if(V[next.first]) continue;
			dist[next.first] = dist[curr] + next.second;
			V[next.first] = 1;
			Q.push_back(next.first);
		}
	}
}

int main() {
	cin >> N;
	adjList.resize(N);
	for(int i = 1; i < N; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		A--;
		B--;
		adjList[A].emplace_back(B, C);
		adjList[B].emplace_back(A, C);
	}

	vector<long long> dist_f(N);
	getSum(0, dist_f);	
	vector<long long> dist_b(N);
	getSum(N - 1, dist_b);	
	
	long long result = dist_f[N - 1];	
	long long need = 0;	
	long long extra = 0;
	for(int i = 1; i + 1 < N; i++) {
		if(dist_f[i] <= dist_b[i]) {
			result += dist_f[i];
			extra += dist_b[i] - dist_f[i];
		}
		else {
			result += dist_b[i];
			need += dist_f[i] - dist_b[i];
		}
	}
	result += min(need, extra);
	cout << result << endl;
}
