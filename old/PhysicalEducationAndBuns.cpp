#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());

	int lo = 0;
	int hi = 1e4;
	int buns, start, step;
	buns = start = step = -1;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		vector<int> low(n), high(n);
		for(int i = 0; i < n; i++) {
			low[i] = a[i] - mid;
			high[i] = a[i] + mid;
		}
		int x = 0;	
		int y = 2e4 + 1;
		bool found = false;
		while(x <= y) {
			int z = x + (y - x) / 2;
			bool valid = true;	
			pii curr {low[0], high[0]};
			for(int i = 1; i < n; i++) {
				curr.first += z; 
				curr.second += z;
				if(curr.second < low[i]) {
					valid = false;
					x = z + 1;
					break;
				}
				else if(curr.first > high[i]) {
					valid = false;
					y = z - 1;
					break;
				}
				curr.first = max(curr.first, low[i]);
				curr.second = min(curr.second, high[i]);
			}
			if(valid) {
				found = true;
				buns = mid;
				for(int i = n - 1; i >= 1; i--)
					curr.first -= z;
				start = curr.first;
				step = z;
				break;
			}
		}
		if(found)
			hi = mid - 1;
		else 
			lo = mid + 1;
	}
	cout << buns << endl;
	cout << start << " " << step << endl;
}
