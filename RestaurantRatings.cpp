#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

long memo[15 + 1][30 + 1];

long getWorse(int numCritics, int totalVal) {		
	if(numCritics == 0 or totalVal == 0)
		return 1;

	if(memo[numCritics][totalVal] != -1)
		return memo[numCritics][totalVal];

	long &count = memo[numCritics][totalVal];
	count = 0;

	for(int t = 0; t <= totalVal; t++) {
		count += getWorse(numCritics - 1, totalVal - t);
	}	

	return count;
}

int main() {
	int N;
	while(cin >> N) {
		if(N == 0)
			break;

		memset(memo, -1, sizeof(memo));
		
		vector<int> rating(N);
		for(int n = 0; n < N; n++) {
			cin >> rating[n];
		}
		int total = accumulate(rating.begin(), rating.end(), 0.0);	

		long count = 0;

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < rating[i]; j++) {
				count += getWorse(N - i - 1, total - j);
			}
			for(int j = rating[i] + 1; j < total; j++) {
				count += getWorse(N - i - 1, total - j - 1);
			}	

			total -= rating[i];
		}

		cout << count + 1 << endl;
	}
}
