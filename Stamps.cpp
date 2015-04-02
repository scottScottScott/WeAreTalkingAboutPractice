#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("stamps.in");
	ofstream fout("stamps.out");

	int K, N;
	fin >> K >> N;
	vector<int> stampVal(N);
	for(int i = 0; i < N; i++) {
		fin >> stampVal[i];
	}
	int M = 0;
	vector<int> memo = {0};
	while(true) {
		M++;
		int minCoins = -1;
		for(int i = 0; i < N; i++) {
			int beforeCoinVal = M - stampVal[i];
			if(beforeCoinVal >= 0 && memo[beforeCoinVal] < K) {
				if(memo[beforeCoinVal] + 1 < minCoins || minCoins == -1) {
					minCoins = memo[beforeCoinVal] + 1;
				}
			}
		}
		if(minCoins == -1) {
			fout << M - 1 << endl;
			return 0;
		}
		memo.push_back(minCoins);
	}


	return 0;
}
