#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<bool>> V(n, vector<bool> (m));	
	int result = 0;
	vector<pii> nodes;
	for(int i = 0; i < k; i++) {
		pii start{0, 0};
		deque<pii> Q{start};
		int length = 1;
		while(!Q.empty()) {
			set<pii> S;
			while(!Q.empty()) {
				pii curr = Q.front();
				Q.pop_front();
				if(V[curr.first][curr.second] == 0) {
					V[curr.first][curr.second] = 1;
					result += length;
					nodes.push_back(curr);
					S.clear();
					break;
				}
				if(curr.second + 1 < m)
					S.emplace(curr.first, curr.second + 1);
				if(curr.first + 1 < n)
					S.emplace(curr.first + 1, curr.second);
			}
			length++;
			Q.assign(S.begin(), S.end());
		}
	}

	reverse(nodes.begin(), nodes.end());	
	cout << result << endl;
	for(pii curr : nodes) {
		for(int j = 0; j <= curr.first; j++)
			printf("(%d, %d) ", j + 1, 1);
		for(int j = 1; j <= curr.second; j++)
			printf("(%d, %d) ", curr.first + 1, j + 1);
		cout << endl;
	}
}
