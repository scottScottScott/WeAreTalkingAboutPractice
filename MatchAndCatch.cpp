#include <iostream>
#include <vector>
#include <string>

using namespace std;

int construct(vector<int> &A, string &S) {
	int n = S.size();		
	vector<vector<int>> Z(n, vector<int>(n));
	for(int r = n - 1; r >= 0; r--) {
		for(int c = n - 1; c > r; c--) {
			if(S[r] == S[c])
				Z[r][c] = 1 + (r + 1 < n and c + 1 < n ? Z[r + 1][c + 1] : 0);
		}
	}
	A.resize(n);
	for(int i = 0; i < n; i++) {
		for(int c = i + 1; c < n; c++)
			A[i] = max(A[i], Z[i][c]);
		for(int r = i - 1; r >= 0; r--)
			A[i] = max(A[i], Z[r][i]);
	}
}

int main() {
	string S, T;
	cin >> S >> T;
	vector<int> A, B;
	construct(A, S);
	construct(B, T);
	int n = S.size();
	int m = T.size();
	vector<vector<int>> C(n, vector<int>(m));
	int result = -1;	
	for(int r = n - 1; r >= 0; r--) {
		for(int c = m - 1; c >= 0; c--) {
			if(S[r] == T[c]) {
				C[r][c] = 1 + (r + 1 < n and c + 1 < m ? C[r + 1][c + 1] : 0);
				if(C[r][c] > A[r] and C[r][c] > B[c]) {
					int temp = max(A[r], B[c]) + 1;
					result = (result == -1 ? temp : min(result, temp));
				}
			}
		}
	}	
	cout << result << endl;
}
