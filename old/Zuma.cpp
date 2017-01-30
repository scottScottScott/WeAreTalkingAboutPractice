#include <iostream>
#include <vector>

using namespace std;

int solve(int A, int B, vector<vector<int>> &memo, vector<int> &colors) {
	if(A > B) return 0;
	if(memo[A][B] != -1) return memo[A][B];

	int &val = memo[A][B];
	val = B - A + 1;
		
	if(A + 1 < B and colors[A] == colors[B])
		val = min(val, solve(A + 1, B - 1, memo, colors));

	if(A != B and colors[A] == colors[A + 1]) {
		val = min(val, 1 + solve(A + 2, B, memo, colors));
	}

	val = min(val, 1 + solve(A + 1, B, memo, colors));

	for(int j = A + 2; j < B; j++) {
		if(colors[A] == colors[j]) {
			val = min(val, solve(A + 1, j - 1, memo, colors) + solve(j + 1, B, memo, colors));
		}
	}

	return val;
}

int main() {
	int N;
	cin >> N;
	vector<int> colors(N);
	for(int i = 0; i < N; i++) 
		cin >> colors[i];

	vector<vector<int>> memo(N, vector<int>(N, -1));

	cout << solve(0, N - 1, memo, colors) << endl;
}
