#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

typedef long long ll;

ll getVal(int val, vector<int> &a, vector<int> &b) {
	ll result = 0;
	for(int x : a) {
		if(x < val)
			result += val - x;	
	}
	for(int x : b) {
		if(x > val)
			result += x - val;
	}
	return result;
}

int main() {
	int n, m;
	cin >> n >> m;
	ll result = LLONG_MAX;	
	vector<int> a(n);
	vector<int> b(m);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	
	ll low = *min_element(a.begin(), a.end());
	ll high = *max_element(b.begin(), b.end());
	if(low >= high) result = 0;
	while(low <= high) {
		int left = low + (high - low) / 3;
		int right = high - (high - low) / 3;

		ll change_l = getVal(left, a, b);
		ll change_r = getVal(right, a, b);
		if(change_l <= change_r)
			high = right - 1;
		else if(change_r < change_l)
			low = left + 1;
		result = min(result, min(change_l, change_r));
	}
	cout << result << endl;
}
