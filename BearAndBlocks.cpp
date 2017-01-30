#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int n;
	cin >> n;
	vector<bool> V(n);
	priority_queue<pii, vector<pii>, greater<pii>> Q;	
	for(int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		Q.emplace(min(temp - 1, min(i, n - i - 1)), i);
	}
	int moves = 0;	
	while(!Q.empty()) {
		pii curr = Q.top();
		Q.pop();
		if(V[curr.second]) continue;
		if(curr.first > moves) 
			moves = curr.first;
		V[curr.second] = 1;
		vector<int> next_vec{curr.second - 1, curr.second + 1};
		for(int next : next_vec) {
			if(next < 0 or next >= n or V[next]) continue;
			Q.emplace(moves + 1, next);
		}
	}
	cout << moves + 1 << endl;
}
