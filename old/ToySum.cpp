#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<bool> v(1e6 + 1);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);	
		v[a[i]] = 1;
	}
	sort(a.begin(), a.end());
	int pair = 0;
	vector<int> result;
	for(int i = 0; i < n; i++) {
		int curr = a[i];
		int other = 1e6 - a[i] + 1;
		if(v[other] == 0) {
			v[other] = 1;
			result.push_back(other);
		}
		else pair++;
	}
	pair /= 2;
	for(int i = 1; i <= 5 * 1e5; i++) {
		if(pair > 0 and v[i] == 0) {
			result.push_back(i);
			result.push_back(1e6 - i + 1);
			pair--;
		}
	}
	int rs = result.size();
	cout << rs << endl;	
	for(int i = 0; i < rs; i++) {
		printf("%d", result[i]);
		printf(i + 1 != rs ? " " : "\n");
	}
}
