#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	const int MAX = 1e6 + 1;
	vector<int> memo(MAX);
	memo[1] = 0;
	for(int i = 2; i <= MAX; i++) {
		memo[i] = 1;
		for(int j = 2; j <= sqrt(i); j++) {
			if(i % j == 0) { 
				memo[i] = memo[i / j] + 1;
				break;
			}
		}
	}

	while(T--) {
		int N;
		cin >> N;
		int result = 0;
		for(int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			result ^= memo[temp];	
		}
		cout << (result != 0 ? 1 : 2) << endl;
	}
}
