#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adjList(n);
	vector<vector<int>> backList(n);
	vector<int> count(n);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		adjList[a].push_back(b);
		count[a]++;
		backList[b].push_back(a);
	}

	int result = 0;
	vector<bool> visit(n);	
	for(int i = 0; i < n; i++) {
		if(visit[i] == 1 or adjList[i].empty()) continue;
		visit[i] = 1;
		deque<int> Q{i};
		vector<int> temp;
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop_front();
			for(vector<int> vec : vector<vector<int>> {adjList[curr], backList[curr]}) {
				for(int next : vec) {
					if(visit[next] == 0) {
						visit[next] = 1;
						Q.push_back(next);
						temp.push_back(next);	
					}
				}
			}
		}
		int t = temp.size();
		vector<bool> seen(n);	
		for(int x : temp) {
			if(seen[x]) continue;	
			if(adjList[x].empty()) {
				deque<int> Q{x};
				seen[x] = 1;				
				while(!Q.empty()) {
					int curr = Q.front();
					Q.pop_front();
					for(int next : backList[curr]) {
						count[next]--;
						if(count[next] == 0) {
							seen[next] = 1;
							Q.push_back(next);
						}
					}
				}
			}
		}
		bool valid = true;
		for(int x : temp)
			if(!seen[x]) valid = false;
		if(!valid) t++;
			result += t;
	}
	cout << result << endl;
}
