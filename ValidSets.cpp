#include <iostream>
#include <deque>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef deque<int> di;
typedef long long ll;

const int MOD = 1e9 + 7;

int d;
vi A, I;
vvi adjList;
vector<bool> V;

int bfs(int curr, int idx) {	
	ll result = 1;
	for(int x : adjList[curr]) {
		if(V[x] or A[x] < A[idx] or (A[x] == A[idx] and I[x] < I[idx]) or (A[x] - A[idx] > d))
			continue;
		V[x] = true;
		result *= bfs(x, idx) + 1;	
		result %= MOD;	
	}
	return result;
}

int main() {
	int n;
	cin >> d >> n;
	A.resize(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	adjList.resize(n);
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;	
		adjList[u].push_back(v);	
		adjList[v].push_back(u);
	}
	int idx = 0;
	I.resize(n, -1);
	I[0] = idx++;
	di Q{0};	
	while(!Q.empty()) {
		int curr = Q.front();
		Q.pop_front();
		for(int x : adjList[curr]) {
			if(I[x] == -1) {
				I[x] = idx++;
				Q.push_back(x);
			}
		}
	}
	ll result = 0;
	for(int i = 0; i < n; i++) {
		V.clear();
		V.resize(n);
		V[i] = true;
		result = (result + bfs(i, i)) % MOD;
	}
	cout << result << endl;
}
