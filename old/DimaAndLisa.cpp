#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int X) {
	for(int i = 2; i * i <= X; i++)	
		if(X % i == 0) return false;
	return true;
}

int main() {
	int N;
	cin >> N;
	
	int curr = N;
	while(!isPrime(curr)) curr--;

	vector<int> P {curr};
	N -= curr;
	if(N == 2) P.push_back(N);		
	else if(N != 0) {
		vector<bool> prime(N + 1, 1);
		prime[1] = prime[0] = 0;
		for(int i = 2; i * i <= N; i++) {
			if(prime[i] == 0) continue;
			for(int j = i + i; j <= N; j += i) 
				prime[j] = 0;
		}
		for(int i = 2; i < N; i++) {
			if(prime[i] and prime[N - i]) {
				P.push_back(i);
				P.push_back(N - i);
				break;
			}
		}
	}

	cout << P.size() << endl;
	for(int i = 0; i < P.size(); i++) {
		cout << P[i];
		if(i + 1 != P.size()) cout << " ";
		else cout << endl;
	}
}
