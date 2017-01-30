#include <iostream>
#include <vector>

using namespace std;

int main() {
	const int MAX = 5e6;
	vector<bool> isPrime(MAX + 1, 1);
	vector<int> numPF(MAX + 1);	
	isPrime[1] = isPrime[0] = 0;
	for(int i = 2; i * i <= MAX; i++) {
		if(!isPrime[i]) continue;	
		for(int j = i + i; j <= MAX; j += i) {
			if(isPrime[j] == 1) {
				isPrime[j] = 0;
				numPF[j] = i;
			}
		}
	}
	for(int i = 2; i <= MAX; i++) {
		if(isPrime[i]) numPF[i] = 1;
		else {
			int fstP = numPF[i];
			numPF[i] = 1 + numPF[i / fstP];
		}
	}

	vector<int> count(MAX + 1);
	for(int i = 2; i <= MAX; i++)
		count[i] += count[i - 1] + numPF[i];

	int T;
	cin >> T;
	while(T--) {
		int A, B;
		scanf("%d %d", &A, &B);
		printf("%d\n", count[A] - count[B]);
	}
}
