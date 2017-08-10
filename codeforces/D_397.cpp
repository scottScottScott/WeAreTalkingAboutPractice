#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> f(n), root;
	set<int> S;
	for(int i = 0; i < n; i++)
		cin >> f[i];
	for(int i = 0; i < n; i++) {
		int idx = i + 1;
		if(f[i] == idx) 
			root.push_back(idx);
		S.insert(f[i]);
	}
	if(root.size() < S.size()) {
		cout << -1 << endl;
		return 0;
	}
	int m = root.size();
	vector<int> h(m), g(n);
	for(int i = 0; i < root.size(); i++) {
		h[i] = root[i];
		g[root[i] - 1] = i + 1;
	}
	for(int i = 0; i < n; i++)
		g[i] = g[f[i] - 1];

	cout << m << endl;
	for(int i = 0; i < n; i++) {
		printf("%d", g[i]);
		printf(i + 1 == n ? "\n" : " ");
	}
	for(int i = 0; i < m; i++) {
		printf("%d", h[i]);
		printf(i + 1 == m ? "\n" : " ");
	}
}
