#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

void printV(vector<int> &temp) {
	for(int i = 0; i < temp.size(); i++) {
		printf("%d", temp[i]);
		printf(i + 1 != temp.size() ? " " : "\n");
	}
}

int main() {
	int n, m;	
	cin >> n >> m;
	unordered_map<int, vector<int>> M;	
	vector<int> computer(n);
	for(int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		M[temp].push_back(i);
	}
	deque<pii> S(m);
	vector<int> socket(m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &S[i].first);
		S[i].second = i;
	}
	int maxC, minA, cost;
	maxC = minA = cost = 0;
	while(!S.empty()) {
		int sizeS = S.size();
		while(sizeS--) {
			pii curr = S.front();
			S.pop_front();
			if(M[curr.first].size() > 0) {
				socket[curr.second] = cost;
				int C = M[curr.first].back();
				M[curr.first].pop_back();
				computer[C] = curr.second + 1;
				maxC++;
				minA += cost;
			}
			else {
				int next = (curr.first + 1) / 2;
				if(curr.first != 1)
					S.emplace_back(next, curr.second);
			}
		}
		cost++;
	}
	cout << maxC << " " << minA << endl;
	printV(socket);
	printV(computer);
}
