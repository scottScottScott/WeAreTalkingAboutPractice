#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	K--;

	vector<vector<int>> table(N, vector<int> (N));

	int count = 1;
	for(int row = 0; row < N; row++) {
		for(int col = 0; col < K; col++)
			table[row][col] = count++;
	}

	int sum = 0;
	for(int row = 0; row < N; row++) {
		for(int col = K; col < N; col++) {
			table[row][col] = count++;
		}
		sum += table[row][K];
	}

	cout << sum << endl;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%d", table[i][j]);
			printf(j != N - 1 ? " " : "\n");
		}
	}
}
