#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int n, m;
	cin >> n;
	vector<vector<int>> P, A;
	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		P.push_back(vector<int>{a, b, i});
	}
	sort(P.begin(), P.end());
	cin >> m;
	for(int i = 0; i < m; i++) {
		int c, d, k;
		scanf("%d %d %d", &c, &d, &k);
		A.push_back(vector<int> {c, d, k, i});	
	}
	sort(A.begin(), A.end());
	
	vector<int> memo(n);
	map<int, vector<pii>> M; 
	int a = 0;
	for(int p = 0; p < P.size(); p++) {
		vector<int> V = P[p];
		while(a < A.size() and A[a][0] <= V[0]) {
			vector<int> &temp = A[a++];
			M[temp[1]].emplace_back(temp[2], temp[3]);
		}
		int right = V[1];
		auto temp = M.lower_bound(right);
		if(temp == M.end()) {
			cout << "NO" << endl;
			return 0;
		}
		vector<pii> &W = temp->second;	
		memo[V[2]] = W.back().second;
		W.back().first--;
		if(W.back().first == 0) {
			W.pop_back();
			if(W.empty())
				M.erase(temp->first);
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++)	
		cout << memo[i] + 1 << (i + 1 == n ? "\n" : " ");
}
