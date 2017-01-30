#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		scanf("%d", &N);
		vector<int> heights(N);
		vector<long long> memo(N);
		for(int i = 0; i < N; i++)	
			scanf("%d", &heights[i]);
		sort(heights.begin(), heights.end());	
		for(int i = N - 1; i >= 0; i--) {
			if(i == N - 1) memo[i] = heights[i];
			else memo[i] = heights[i] + memo[i + 1];
		}
		
		long long exp = 0;
		for(int S = 0; S < N; S++) {
			long long currExp = (S + 1) * memo[S];	
			exp = max(exp, currExp);
		}
		cout << exp << endl;
	}
}
