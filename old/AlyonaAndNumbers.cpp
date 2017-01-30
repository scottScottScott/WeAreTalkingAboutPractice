#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int full_N = N / 5;
	vector<long long> A(5, full_N);
	for(int i = 1; i <= 4; i++)
		if(N % 5 >= i) A[i]++;

	int full_M = M / 5;
	vector<long long> B(5, full_M);
	for(int i = 1; i <= 4; i++)
		if(M % 5 >= i) B[i]++;

	long long total = 0;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if( (i + j) % 5	== 0)
				total += A[i] * B[j];
		}
	}
	cout << total << endl;
}
