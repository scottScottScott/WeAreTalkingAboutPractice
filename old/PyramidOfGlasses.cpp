#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, T;
	cin >> N >> T;
	
	vector<vector<int>> G(N + 1);
	for(int i = 1; i <= N; i++)
		G[i].resize(i);	

	for(int t = 1; t <= T; t++) {
		int denom = 1;
		G[1][0] += 1;
		for(int n = 1; n < N; n++) {
			for(int k = 0; k < n; k++) {
				if(G[n][k] > denom) {
					int extra = G[n][k] - denom;
					G[n][k] -= extra;
					G[n + 1][k] += extra;
					G[n + 1][k + 1] += extra;
				}
			}
			denom *= 2;
		}
	}
	
	int fullCnt = 0;
	int denom = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < i; j++)
			if(G[i][j] >= denom) fullCnt++;
		denom *= 2;
	}

	cout << fullCnt << endl;
}
