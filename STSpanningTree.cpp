#include <iostream>
#include <utility>
#include <vector>
#include <deque>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adjList(n + 1);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	int s, t, ds, dt;
	cin >> s >> t >> ds >> dt;
	bool isAdj = false;
	for(int x : adjList[s])
		if(x == t) isAdj = true;
	vector<bool> V(n + 1);	
	vector<int> fst, snd;
	vector<pii> both, memo;
	for(int i = 1; i <= n; i++) {
		if(V[i] or i == s or i == t) continue;
		int touchS = -1, touchT = -1;
		deque<int> Q{i};
		V[i] = true;
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop_front();	
			for(int x : adjList[curr]) {
				if(x == s)
					touchS = curr;
				if(x == t)
					touchT = curr;
				if(!V[x] and x != s and x != t) {
					V[x] = true;
					Q.push_back(x);
					memo.emplace_back(curr, x);
				}
			}
		}
		if(touchS != -1 and touchT != -1)
			both.emplace_back(touchS, touchT);
		else if(touchS != -1)
			fst.push_back(touchS);	
		else
			snd.push_back(touchT);
	}

	bool valid = true;
	if(fst.size() > ds - 1 or snd.size() > dt - 1 or fst.size() + snd.size() + both.size() > ds + dt - 1) valid = false;

	if(!valid) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	if(!both.empty()) {
		cout << s << " " << both.back().first << endl;
		cout << t << " " << both.back().second << endl;
		both.pop_back();
	}
	else
		cout << s << " " << t << endl;
	ds -= fst.size() + 1;	
	dt -= snd.size() + 1;
	for(int x : fst)
		cout << s << " " << x << endl;
	for(int x : snd)
		cout << t << " " << x << endl;
	while(ds and !both.empty()) {
		cout << s << " " << both.back().first << endl;
		both.pop_back();
		ds--;
	}	
	while(dt and !both.empty()) {
		cout << t << " " << both.back().second << endl;
		both.pop_back();
		dt--;
	}
	for(pii curr : memo)
		cout << curr.first << " " << curr.second << endl;
}
