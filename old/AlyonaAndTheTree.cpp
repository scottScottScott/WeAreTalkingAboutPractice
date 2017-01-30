#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <deque>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	vector<vector<pii>> adjList(N);	
	for(int i = 1; i < N; i++) {
		int P, C;	
		scanf("%d %d", &P, &C);
		P--;
		adjList[i].emplace_back(P, C);
		adjList[P].emplace_back(i, C);
	}

	vector<long long> path(N);	
	vector<bool> visit(N);
	vector<bool> inValid(N);

	deque<int> Q{0};
	visit[0] = true;
	path[0] = 0;
	while(!Q.empty()) {
		int curr = Q.front();
		Q.pop_front();
		for(pii next : adjList[curr]) {
			if(visit[next.first]) continue;
			visit[next.first] = true;
			path[next.first] = max((long long) 0, path[curr] + next.second);
			Q.push_back(next.first);
			if(inValid[curr] or path[next.first] > A[next.first]) inValid[next.first] = true;
		}
	}

	cout << accumulate(inValid.begin(), inValid.end(), 0) << endl;
}
