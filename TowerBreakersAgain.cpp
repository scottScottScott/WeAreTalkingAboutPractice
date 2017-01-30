#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	const int MAX = 1e5 + 1;
	vector<int> memo(MAX);
	memo[1] = 0;
	for(int i = 2; i < MAX; i++) {
		int stop = sqrt(i);
		vector<bool> visit(30);
		for(int j = 2; j <= stop; j++) {
			if(i % j == 0) {
				int other = i / j;
				if(j % 2 == 1)
					visit[memo[other]] = 1;
				if(other % 2 == 1)
					visit[memo[j]] = 1;
			}
		}
		for(int x = 1; x < 30; x++) {
			if(visit[x] != 1) {
				memo[i] = x;
				break;
			}
		}
	}

	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int result = 0;
		for(int i = 0; i < N; i++) {
			int height;
			cin >> height;
			result ^= memo[height];
		}
		cout << (result != 0 ? 1 : 2) << endl;
	}
}
