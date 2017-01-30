#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adjList(n);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		adjList[a].push_back(b);
	}
	
	ll result = 0;
	for(int i = 0; i < n; i++) {
		vector<ll> count(n);
		for(int x : adjList[i]) {
			for(int y : adjList[x])
				count[y]++;
		}
		for(int j = 0; j < n; j++) {
			if(j == i) continue;
			result += count[j] * (count[j] - 1) / 2;
		}
	}
	cout << result << endl;
}
