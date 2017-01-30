#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int> A(N); 

	for(int i = 0; i < N; i++)
		cin >> A[i];
	int i;
	for(i = 1; i < N; i++)
		if(A[i] < A[i - 1]) break;
	if(i == N) {
		cout << 0 << endl;
		return 0;
	} 

	double num = 1;
	double denom = 1;

	for(int i = 1; i <= N; i++) 
		denom *= i;

	sort(A.begin(), A.end());
	int count = 1;
	for(int i = 1; i <= N; i++) {
		if(i == N or A[i] != A[i - 1]) {
			for(int j = count; j > 1; j--)
				num *= j;
			count = 1;
		}
		else
			count++;
	} 

	cout << fixed << setprecision(6) << denom / num << endl;
	return 0;
}

