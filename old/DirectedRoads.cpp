#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
vector<int> nxt;
vector<bool> V;

int dfs(int i) {
	map<int, int> M;
	M[i] = 0;
	V[i] = 1;
	int dist = 0;
	while(!V[nxt[i]]) {
		i = nxt[i];
		V[i] = 1;
		M[i] = ++dist;
	}
	if(M.count(nxt[i])) {
		int length = dist - M[nxt[i]] + 1;
		return length;
	}
	else return -1;
}

int main() {
	int n;
	cin >> n;
	nxt.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> nxt[i];
		nxt[i]--;
	}
	vector<int> info;
	V.resize(n);
	for(int i = 0; i < n; i++) {
		if(V[i] == 1) continue;	
		int result = dfs(i);
		if(result != -1)
			info.push_back(result);
	}
	ll total = 1;
	int m = n - accumulate(info.begin(), info.end(), 0);
	for(int i = 0; i < m; i++)
		total = (total * 2) % MOD;
	for(int x : info) {
		ll temp = 1;
		for(int i = 0; i < x; i++)
			temp = (temp * 2) % MOD;
		temp -= 2;
		total = (total * temp) % MOD;
	}	
	cout << total << endl;
}
