#include <iostream>
#include <queue>
#include <set>
#include <deque>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	int n, m, p, q;
	cin >> n >> m >> p >> q;
	vector<vector<pii>> adjList(n);
	for(int i = 0; i < m; i++) {
		int x, y, l;
		cin >> x >> y >> l;
		x--; y--;
		adjList[x].emplace_back(y, l);
		adjList[y].emplace_back(x, l);
	}
	priority_queue<pll, vector<pll>, greater<pll>> regions;
	vector<bool> V(n);	
	vector<int> temp;
	for(int i = 0; i < n; i++) {
		if(V[i] == 1) continue;
		V[i] = 1;
		deque<int> Q{i};
		ll dist = 0;	
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop_front();
			for(pii e : adjList[curr]) {
				if(temp.size() == 0) {
					temp.push_back(i);
					temp.push_back(e.first);
				}
				if(!V[e.first]) {
					V[e.first] = true;
					Q.push_back(e.first);
				}
				dist += e.second;
			}
		}
		regions.emplace(dist / 2, i);
	}
	
	int z = regions.size();
	if(q > z or q < z - p or (q == z and temp.empty() and p > 0)) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	while(z > q) {
		pll A = regions.top();
		regions.pop();
		pll B = regions.top();
		regions.pop();
		ll newPath = min((ll) 1e9, A.first + B.first + 1);
		regions.emplace(A.first + B.first + newPath, A.second);
		printf("%d %d\n", (int) A.second + 1, (int) B.second + 1);
		if(temp.size() == 0) {
			temp.push_back(A.second);
			temp.push_back(B.second);
		}
		z--;
		p--;	
	}
	while(p--)
		printf("%d %d\n", temp[0] + 1, temp[1] + 1);
	return 0;
}
