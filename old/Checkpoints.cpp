#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, a;
	cin >> n >> a;
	if(n == 1) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> x(n);
	for(int i = 0; i < n; i++)
		cin >> x[i];
	sort(x.begin(), x.end());
	
	if(a <= x[0])
		cout << x[n - 2] - a << endl;
	else if(a >= x[n - 1])
		cout << a - x[1] << endl;
	else {
		int d1 = a <= x[n - 2] ? 2 * (a - x[0]) + x[n - 2] - a : INT_MAX;
		int d2 = a <= x[1] ? x[n - 1] - a : 2 * (a - x[1]) + x[n - 1] - a;
		int d3 = a >= x[1] ? 2 * (x[n - 1] - a) + a - x[1] : INT_MAX;
		int d4 = a >= x[n - 2] ? a - x[0] : 2 * (x[n - 2] - a) + a - x[0];
		cout << min(d1, min(d2, min(d3, d4))) << endl;
	}	
}
