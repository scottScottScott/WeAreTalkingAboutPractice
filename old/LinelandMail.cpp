#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> C(N);
	for(int i = 0; i < N; i++)
		cin >> C[i];
	int minVal = C[0];
	int maxVal = C[N - 1];
	for(int i = 0; i < N; i++) {
		int A, B;
		if(i == 0) {
			A = C[1] - C[0];
			B = maxVal - C[0];
		}
		else if(i == N - 1) {
			A = C[N - 1] - C[N - 2];
			B = C[N - 1] - minVal;
		}
		else {
			A = min(C[i + 1] - C[i], C[i] - C[i - 1]);
			B = max(C[i] - minVal, maxVal - C[i]);
		}
		printf("%d %d\n", A, B);
	}
}
