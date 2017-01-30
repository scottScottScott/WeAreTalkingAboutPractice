#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for(int i = 0; i < N; i++) 
		cin >> A[i];

	int error[N][N];
	memset(error, 0, sizeof(error));

	for(int i = 0; i < N; i++) {
		priority_queue<int, vector<int>, less<int>> lower;
		priority_queue<int, vector<int>, greater<int>> upper;
		int sumLower = 0;
		int sumUpper = 0;
		for(int j = i; j < N; j++) {
			int curr = A[j];
			if(lower.size() == upper.size()) {
				lower.push(curr);
				sumLower += curr;
				int temp = lower.top();		
				sumLower -= temp;
				lower.pop();
				upper.push(temp);
				sumUpper += temp;
			}	
			else if(upper.size() > lower.size()) {
				upper.push(curr);
				sumUpper += curr;
				int temp = upper.top();
				sumUpper -= temp;
				upper.pop();
				lower.push(temp);
				sumLower += temp;
			}
			long median = upper.top();
			error[i][j] = (median * lower.size() - sumLower) + (sumUpper - median * upper.size());
		}
	}

	int memo[N][K];
	memset(memo, 0, sizeof(memo));
	for(int k = 0; k < K; k++) {
		for(int n = 0; n < N; n++) {
			if(k == 0)
				memo[n][0] = error[0][n];
			else {
				memo[n][k] = memo[n][k - 1];
				for(int j = 0; j < n; j++)
					memo[n][k] = min(memo[n][k], memo[j][k - 1] + error[j + 1][n]);
			}
		}
	}
	cout << memo[N - 1][K - 1] << endl;
}
