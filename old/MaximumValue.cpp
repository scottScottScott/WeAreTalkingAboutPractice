#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a;
	vector<bool> seen(1e6 + 1);
	for(int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if(seen[temp]) continue;
		seen[temp] = true;
		a.push_back(temp);
	}
	n = a.size();
	sort(a.begin(), a.end());	
	int i = 0;	
	int result = 0;
	for( ; i < n and a[i] < 1e3; i++) {
		for(int j = i + 1; j < n; j++)
			result = max(result, a[j] % a[i]);	
	}
	for( ; i < n; i++) {
		for(int j = 2 * a[i]; j <= 1e6 + a[i]; j += a[i]) {
			auto temp = lower_bound(a.begin(), a.end(), j);
			temp--;	
			result = max(result, *temp % a[i]);
		}
	}
	cout << result << endl;
}
