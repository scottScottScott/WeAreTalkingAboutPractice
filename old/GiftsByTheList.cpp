#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, M, P, C;

int main() {
	cin >> N >> M;
	vector<vector<int>> adjList(N);
	vector<int> gift(N);
	vector<bool> isRoot(N, 1);
	for(int i = 0; i < M; i++) {
		cin >> P >> C;
		P--;
		C--;
		adjList[P].push_back(C);	
		isRoot[C] = 0;
	}
	for(int i = 0; i < N; i++) {
		cin >> gift[i];
		gift[i]--;
	}

	vector<int> top(N, -1);
	bool valid = true;
	deque<int> list;
	for(int i = 0; i < N; i++) {
		if(!isRoot[i]) continue;
		top[i] = gift[i];
		list.push_back(i);
		deque<int> Q{i};
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop_front();
			for(int next : adjList[curr]) {
				Q.push_back(next);
				if(gift[next] == next) {
					top[next] = next;
					list.push_front(next);
				}
				else if(gift[next] == top[curr])
					top[next] = top[curr];
				else valid = false;
			}
		}
	}

	if(valid == false) {
		cout << -1 << endl;
		return 0;
	}

	cout << list.size() << endl;
	for(int val : list)
		printf("%d\n", val + 1);
}
