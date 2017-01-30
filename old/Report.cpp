#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> report(N);
	for(int i = 0; i < N; i++) 
		cin >> report[i];

	priority_queue<pii, vector<pii>, less<pii>> Q;
	vector<bool> sort_type(M + 1);
	for(int i = 0; i < M; i++) {
		int T, R;
		cin >> T >> R;
		sort_type[i] = --T;
		Q.emplace(R, i);
	}
	Q.emplace(0, M);

	vector<int> new_report(N);
	int currTop = 0;
	int currBottom = N - 1;
	bool isReversed;
	int lastManager = -1;
	int numNodes;
	while(!Q.empty()) {
		pii curr = Q.top();
		Q.pop();

		if(lastManager == -1) {
			for(int i = N - 1; i >= curr.first; i--)				
				new_report[i] = report[currBottom--];
			sort(report.begin(), report.begin() + curr.first);
		}
		else if(curr.second < lastManager) continue;
		else {
			if(isReversed) {
				for(int i = numNodes - 1; i >= curr.first; i--)
					new_report[i] = report[currTop++];	
			}	 
			else {
				for(int i = numNodes - 1; i >= curr.first; i--)
					new_report[i] = report[currBottom--];
			}
		}

		numNodes = curr.first;
		isReversed = sort_type[curr.second];
		lastManager = curr.second;
	}

	for(int i = 0; i < N; i++) {
		if(i != 0) cout << " ";
		cout << new_report[i];
	}
	cout << endl;
}
