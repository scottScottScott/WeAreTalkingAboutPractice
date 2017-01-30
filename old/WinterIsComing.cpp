#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<bool> T(n);
	int need = 0;
	for(int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		T[i] = temp < 0;
		if(T[i] == 1) need++;
	}

	if(need > k) {
		cout << -1 << endl;	
		return 0;
	}

	k -= need;

	vector<int> V;
	int count, sTire, lDays;
	count = sTire = lDays = 0;
	int i = 0;
	while(i < n and T[i] == 0) i++;
	for( ; i <= n; i++) {
		if(i < n and T[i] == 1 and (i == 0 or T[i - 1] == 0))
			sTire++;
		if(i < n and T[i] == 0 and T[i - 1] == 1)
			sTire++;

		if(i == n) 
			lDays = count;
		else if(T[i] == 1) {
			if(count != 0) V.push_back(count);
			count = 0;
		}
		else count++;
	}
	sort(V.rbegin(), V.rend());
	while(V.size() > 0 and V.back() <= k) {
		k -= V.back();
		V.pop_back();
		sTire -= 2;
	} 
	if(lDays > 0 and lDays <= k)
		sTire--;
	cout << sTire << endl;
}
