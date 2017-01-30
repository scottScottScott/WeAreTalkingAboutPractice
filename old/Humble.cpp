#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream fin("humble.in");
	ofstream fout("humble.out");

	int K, N;
	fin >> K >> N;
	vector<int> primes(K);
	for(int k = 0; k < K; k++) {
		fin >> primes[k];
	}

	vector<long> humble(N + 1);
	vector<int> memo(K);
	humble[0] = 1;
	int nxtIndex = 1;
	while(nxtIndex != N + 1) {
		long min = humble[memo[0]] * primes[0];
		for(int i = 0; i < K; i++) {
			if(primes[i] * humble[memo[i]] < min) {
				min = primes[i] * humble[memo[i]];
			}
		}	
		humble[nxtIndex] = min;
		for(int i = 0; i < K; i++) {
			if(primes[i] * humble[memo[i]] == min)
				memo[i]++;
		}
		nxtIndex++;
	}

	fout << humble[N] << endl;
	cout << humble[N] << endl;
	return 0;
}
