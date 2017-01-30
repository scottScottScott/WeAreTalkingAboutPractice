#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	if(m == 0) {
		ll total = (ll) n * (n - 1) * (n - 2) / 6;
		cout << 3 << " " << total << endl;
		return 0;
	}

	vector<vector<int>> adjList(n);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	vector<bool> V(n);
	bool onlySingle = true;	
	ll total = 0;
	for(int i = 0; i < n; i++) {
		if(V[i] == 1) continue;
		int red, blue;
		red = blue = 0;
		vector<bool> isRed(n);
		deque<int> Q{i};
		blue++;
		int size = 0;
		while(!Q.empty()) {
			size++;
			int curr = Q.front();
			Q.pop_front();
			V[curr] = 1;
			for(int next : adjList[curr]) {
				if(V[next]) {
					bool color = !isRed[curr];
					if(isRed[next] != color) {
						printf("0 1\n");
						return 0;
					}
					continue;
				}
				V[next] = true;
				isRed[next] = !isRed[curr];
				if(isRed[next]) red++;
				else blue++;
				Q.push_back(next);
			}
		}
		total += (ll) red * (red - 1) / 2 + (ll) blue * (blue - 1) / 2;
	}

	if(total == 0) {
		total = (ll) (n - 2) * m;
		cout << 2 << " " << total << endl;
	}
	else
		cout << 1 << " " << total << endl;
}
