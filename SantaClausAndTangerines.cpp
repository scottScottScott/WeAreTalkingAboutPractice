#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int n, k;	
vector<int> A;

bool valid(int val) {
	ll count = 0;
	for(int i = 0; i < n; i++) {
		if(A[i] < val) break;
		int curr = A[i];
		int temp = 1;	
		while( (curr + 1) / 2 >= val) {
			curr = (curr + 1) / 2;
			if(curr == val) {
				temp = max(temp, A[i] - 2 * temp * (val - 1));	
				break;	
			}
			temp *= 2;	
		}
		count += temp;
	}
	return count >= k;
}

int main() {
	cin >> n >> k;
	A.resize(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A.rbegin(), A.rend());
	int lo = 1;
	int hi = 1e7;
	int result = 0;
	while(lo <= hi) {
		int curr = lo + (hi - lo) / 2;
		if(valid(curr)) {
			result = curr;
			lo = curr + 1;
		}
		else
			hi = curr - 1;
	}
	if(result == 0) result = -1;
	cout << result << endl;
}
