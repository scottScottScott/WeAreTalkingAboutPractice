#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

int r_solve(vector<int> a) {
	if(a.empty()) return 0;
	int n = a.size();
	int minVal = *min_element(a.begin(), a.end());
	int total = 0;
	vector<int> b;
	for(int i = 0; i <= n; i++) {
		if(i == n or a[i] - minVal == 0) {
			total += r_solve(b);	
			b.clear();
		}
		else
			b.push_back(a[i] - minVal);
	}
	int result = min(total + minVal, n);
	return result;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	cout << r_solve(a) << endl;
}
