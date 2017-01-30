#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	int n, m;	
	cin >> n >> m;
	ll total = (ll) n * n;	
	vector<bool> rows(n);
	vector<bool> columns(n);
	int rowC, colC;
	rowC = colC = n;
	vector<ll> result;
	while(m--) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--; y--;
		if(rows[x] == 0) {
			rows[x] = 1;
			total -= colC;
			rowC--;
		}
		if(columns[y] == 0) {
			columns[y] = 1;
			total -= rowC;
			colC--;
		}
		result.push_back(total);
	}
	for(int i = 0; i < result.size(); i++) {
		if(i != 0) cout << " ";
		cout << result[i];
	}
	cout << endl;
}
