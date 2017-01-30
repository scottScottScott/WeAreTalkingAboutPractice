#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++)
		cin >> A[i];
	sort(A.begin(), A.end());	
	int result = 0;
	int lastVal = 0;
	for(int i = 0; i < N; i++) {
		if(A[i] <= lastVal) {
			result += lastVal + 1 - A[i];	
			A[i] = lastVal + 1;
		}
		lastVal = A[i];
	}
	cout << result << endl;
}
