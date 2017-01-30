#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, k;
vector<int> a;

bool isValid(ll c) {
	vector<int> memo(n, 100000);
	int result = n;
	for(int i = 0; i < n; i++) {
		memo[i] = i;
		for(int j = 0; j < i; j++) {
			if(abs(a[j] - a[i]) <= c * (i - j))
				memo[i] = min(memo[i], memo[j] + (i - j - 1));
		}
		result = min(result, memo[i] + (n - 1 - i));
	}
	result = min(result, memo[n - 1]);
	return result <= k;
}

int main() {
	cin >> n >> k;
	a.resize(n);
	for(int i = 0; i < n; i++) 
		cin >> a[i];
	int lo = 0;
	int hi = 2e9 + 1;
	int result = hi;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if(isValid(mid)) {
			result = mid;
			hi = mid - 1;
		}	
		else 
			lo = mid + 1;
	}
	cout << result << endl;	
}
