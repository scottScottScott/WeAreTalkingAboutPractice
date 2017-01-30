#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> aM(n, vector<int>(n, -1));
	vector<vector<int>> aL(n);
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		aM[a][b] = 1;
		aM[b][a] = 1;
		aL[a].push_back(b);
		aL[b].push_back(a);
	}
	int s1, s2, t1, t2, l1, l2;
	cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
	s1--; t1--; s2--; t2--;
	for(int i = 0; i < n; i++) {
		vector<bool> v(n);
		deque<int> Q{i};
		v[i] = 1;
		int dist = 0;
		while(!Q.empty()) {
			int n = Q.size();
			while(n--) {
				int curr = Q.front();
				aM[i][curr] = dist;
				Q.pop_front();
				for(int nxt : aL[curr]) {
					if(v[nxt]) continue;
					Q.push_back(nxt);
					v[nxt] = 1;
				}
			}
			dist++;
		}
	}

	if(aM[s1][t1] > l1 or aM[s2][t2] > l2) {
		cout << -1 << endl;	
		return 0;
	}
	int result = aM[s1][t1] + aM[s2][t2];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int temp = aM[i][j];
			if(aM[s1][i] + temp + aM[j][t1] <= l1 and aM[s2][i] + temp + aM[j][t2] <= l2)
				result = min(result, aM[s1][i] + aM[s2][i] + aM[j][t1] + aM[j][t2] + temp);
			if(aM[s1][i] + aM[i][j] + aM[j][t1] <= l1 and aM[t2][i] + aM[i][j] + aM[j][s2] <= l2)
				result = min(result, aM[s1][i] + aM[j][t1] + aM[t2][i] + aM[j][s2] + temp);
		}
	}
	cout << m - result << endl;
}
