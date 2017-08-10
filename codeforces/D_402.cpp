#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string T, P;
	cin >> T >> P;
	int n = T.size();
	int m = P.size();
	vector<int> A(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		A[i]--;
	}
	int lo = 0;
	int hi = n;
	int result = 0;
	while(lo <= hi) {
		int curr = lo + (hi - lo) / 2;
		
		vector<bool> V(n, 1);
		for(int i = 0; i < curr; i++)
			V[A[i]] = 0;
		int j = 0;
		for(int i = 0; i < n; i++) {
			if(!V[i]) continue;	
			if(T[i] == P[j]) j++;
			if(j == m)
				break;
		}

		if(j == m) {
			result = curr;	
			lo = curr + 1;
		}
		else
			hi = curr - 1;
	}
	cout << result << endl;
}
