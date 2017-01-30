#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, a;
	cin >> n >> m >> a;
	vector<int> b(n), p(m);
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0; i < m; i++)
		cin >> p[i];
	sort(b.rbegin(), b.rend());
	sort(p.begin(), p.end());	
	int r = 0;
	long long s = 0;
	int lo = 0;
	int hi = min(n, m);
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		long long spent = 0;
		for(int i = mid - 1, j = 0; i >= 0; i--, j++) {
			if(b[i] < p[j])	
				spent += p[j] - b[i];
		}
		if(spent <= a) {
			r = mid;
			s = max((long long) 0, accumulate(p.begin(), p.begin() + mid, (long long) 0) - a);
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	cout << r << " " << s << endl;
}
