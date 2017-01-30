#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);

	for(int i = 0; i < N; i++)
		cin >> A[i];
	for(int i = 0; i < N; i++)
		cin >> B[i];
	
	long long maxSum = 0;
	for(int l = 0; l < N; l++) {
		long long A_val = 0;	
		long long B_val = 0;
		for(int r = l; r < N; r++) {
			A_val |= A[r];
			B_val |= B[r];
			maxSum = max(maxSum, A_val + B_val);
		}
	}	
	cout << maxSum << endl;
}
