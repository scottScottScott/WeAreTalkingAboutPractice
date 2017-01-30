#include <iostream>
#include <string>
#include <vector>

using namespace std;

int memo[1000][1000][10];
int LCS[1000][1000];

int main() {
	int N, M, K;
	string S, T;
	cin >> N >> M >> K;
	cin >> S >> T;

	for(int s = 0; s < N; s++) {
		for(int t = 0; t < M; t++) {
			if(S[s] == T[t]) {
				int last = (s == 0 or t == 0 ? 0 : LCS[s - 1][t - 1]);
				LCS[s][t] = last + 1;
			} 
		}
	}

	for(int k = 0; k < K; k++) {
		for(int s = 0; s < N; s++) {
			for(int t = 0; t < M; t++) {
				int &curr = memo[s][t][k];
				if(k == 0) {
					int last_1 = (s == 0 ? 0 : memo[s - 1][t][k]);
					int last_2 = (t == 0 ? 0 : memo[s][t - 1][k]);
					curr = LCS[s][t];
					curr = max(curr, last_1);
					curr = max(curr, last_2);
				}	
				else {
					int curr_val = LCS[s][t];
					int last_val = (s - curr_val < 0 or t - curr_val < 0 ? 0 : memo[s - curr_val][t - curr_val][k - 1]);
					curr = curr_val + last_val;
					int last_1 = (s == 0 ? 0 : memo[s - 1][t][k]);
					int last_2 = (t == 0 ? 0 : memo[s][t - 1][k]);
					curr = max(curr, last_1);
					curr = max(curr, last_2);
				}
			}
		}
	}

	cout << memo[N - 1][M - 1][K - 1] << endl;	
}
