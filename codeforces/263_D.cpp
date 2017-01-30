#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e5;

typedef long long ll;

vector<vector<int>> aL(MAX);
vector<int> p(MAX), isB(MAX);
vector<bool> visit(MAX);
vector<ll> bVal(MAX), wVal(MAX);
int n;

void r_solve(int curr) {
	visit[curr] = true;
	for(int x : aL[curr]) {
		if(!visit[x]) {
			r_solve(x);
			p[x] = curr;
		}
	}
	if(isB[curr]) {
		bVal[curr] = 1;
		for(int x : aL[curr]) {
			if(p[x] != curr or bVal[x] == 0) continue;
			bVal[curr] *= wVal[x] + bVal[x];
			bVal[curr] %= MOD;
		}	
		wVal[curr] = 0;
	}
	else {
		wVal[curr] = 1;
		bool first = true;
		vector<ll> val, forward, backward, bV;
		for(int x : aL[curr]) {
			if(p[x] != curr or bVal[x] == 0) continue;
			wVal[curr] *= (wVal[x] + bVal[x]);
			wVal[curr] %= MOD;
			val.push_back(wVal[x] + bVal[x]);
			bV.push_back(bVal[x]);
		}
		forward = backward = val;
		int N = val.size();
		for(int i = 1; i < N; i++) {
			forward[i] *= forward[i - 1];
			forward[i] %= MOD;
		}
		for(int i = N - 2; i >= 0; i--) {
			backward[i] *= backward[i + 1];
			backward[i] %= MOD;
		}
		for(int i = 0; i < val.size(); i++) {
			ll temp = (bV[i] * (i - 1 >= 0 ? forward[i - 1] : 1)) % MOD;
			temp *= (i + 1 < N ? backward[i + 1] : 1);
			bVal[curr] += temp;
			bVal[curr] %= MOD;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i < n; i++) {
		int a;
		cin >> a;
		aL[i].push_back(a);
		aL[a].push_back(i);
	}
	for(int i = 0; i < n; i++)
		cin >> isB[i];
	r_solve(0);
	cout << bVal[0] << endl;
}
