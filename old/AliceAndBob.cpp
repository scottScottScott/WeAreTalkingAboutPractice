#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int A, int B) {
	while(B != 0) {
		int C = B;
		B = A % B;
		A = C;
	}
	return A;
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++)
		cin >> A[i];
	sort(A.begin(), A.end());
	int maxVal = A[N - 1];
	int memo_gcd = A[0];	
	for(int i = 1; i < N; i++) {
		int curr_gcd = gcd(A[i], A[i - 1]);
		memo_gcd = gcd(curr_gcd, memo_gcd);
	}
	int possible = maxVal / memo_gcd;
	possible -= N;
	cout << (possible % 2 == 1 ? "Alice" : "Bob") << endl;
}
