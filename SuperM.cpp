#include <iostream>
#include <utility>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

#define pb push_back

bool cmp(pii A, pii B) {
	if(A.first > B.first)
		return 1;
	else if(A.first < B.first) 
		return 0;
	else if(A.second < B.second)
		return 1;
	else
		return 0;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adjList(n);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	vector<bool> a(n);
	int root = -1;
	for(int i = 0; i < m; i++) {
		int v;
		scanf("%d", &v);
		v--;
		a[v] = 1;
		if(root == -1) root = v;
	}
	vector<int> children(n);
	for(int i = 0; i < n; i++) {
		children[i] = adjList[i].size() - 1;
		if(i == root) children[i]++;
	}
	deque<int> L;
	deque<int> Q;
	int result = n - 1;
	for(int i = 0; i < n; i++) {
		if(children[i] == 0) {
			if(!a[i]) {
				L.push_back(i);
				result--;
			}
			else
				Q.push_back(i);
		}
	}
	while(!L.empty()) {
		int curr = L.front();
		L.pop_front();
		children[curr]--;
		for(int next : adjList[curr]) {
			children[next]--;
			if(children[next] != 0) continue;
			if(!a[next]) {
				L.push_back(next);
				result--;
			}
			else 
				Q.push_back(next);
		}
	}
	result *= 2;
	int longest = 1;
	int memo = root;
	vector<int> length(n);
	vector<int> endpoint(n);
	while(!Q.empty()) {
		int curr = Q.front();
		children[curr]--;
		Q.pop_front();
		int parent = -1;
		vector<pii> temp;
		for(int next : adjList[curr]) {
			if(children[next] > 0)
				parent = next;
			else if(length[next] > 0)
				temp.emplace_back(length[next], endpoint[next]);	
		}	
		sort(temp.begin(), temp.end(), cmp);
		length[curr] = 1 + (temp.size() == 0 ? 0 : temp.front().first);

		if(temp.size() == 0) endpoint[curr] = curr;
		else endpoint[curr] = temp.front().second;

		if(length[curr] >= longest) {
			if(length[curr] == longest)
				memo = min(memo, min(curr, endpoint[curr]));
			else {
				longest = length[curr];
				memo = min(curr, endpoint[curr]);
			}
		}

		if(temp.size() >= 2) {
			int tempLong = temp[0].first + temp[1].first + 1;
			if(tempLong >= longest) {
				if(longest == tempLong) 
					memo = min(memo, min(temp[0].second, temp[1].second));
				else {
					longest = tempLong;
					memo = min(temp[0].second, temp[1].second);
				}
			}
		}
		if(parent != -1) {
			children[parent]--;	
			if(children[parent] == 0) 
				Q.push_back(parent);
		}
	}	
	cout << memo + 1 << endl;
	cout << result - (longest - 1) << endl;
}
