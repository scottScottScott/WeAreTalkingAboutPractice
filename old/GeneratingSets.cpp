#include <iostream>
#include <algorithm>
#include <vector>
#include <set> 

using namespace std;

int main() {
	int n;	
	cin >> n;
	vector<int> Y(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &Y[i]);
	sort(Y.rbegin(), Y.rend());

	int lo = 1;
	int hi = 1e9;
	vector<int> result;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		bool valid = true;

		set<int> S;
		vector<int> X;
		for(int i = 0; i < n; i++) {
			int curr = Y[i];
			while(curr > mid)
				curr /= 2;

			while(curr > 0) {
				if(!S.count(curr)) {
					X.push_back(curr);
					S.insert(curr);
					break;
				}
				curr /= 2;
			}
			if(curr == 0) {
				valid = false;
				break;
			}
		}

		if(valid) {
			hi = mid - 1;
			result = X;
		}
		else
			lo = mid + 1;	
	}

	for(int i = 0; i < n; i++) {
		printf("%d", result[i]);
		printf(i != n - 1 ? " " : "\n");
	}
}
