#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N, M, Q;
	cin >> N >> M >> Q;
		
	vector<vector<int>> matrix(N, vector<int> (M));
	vector<pii> Instructions;
	
	while(Q--) {
		int T;
		scanf("%d", &T);
		if(T == 1 or T == 2) {
			int A;
			scanf("%d", &A);
			A--;
			if(T == 1) {
				int temp = matrix[A][0];
				for(int c = 1; c < M; c++)
					matrix[A][c - 1] =  matrix[A][c];
				matrix[A][M - 1] = temp;
			}
			else {
				int temp = matrix[0][A];	
				for(int r = 1; r < N; r++)
					matrix[r - 1][A] = matrix[r][A];
				matrix[N - 1][A] = temp;
			}
			Instructions.emplace_back(T, A);
		}
		else {
			int R, C, X;
			scanf("%d %d %d", &R, &C, &X);
			matrix[--R][--C] = X;
		}
	}	

	for(int i = Instructions.size() - 1; i >= 0; i--) {
		pii curr = Instructions[i];
		int A = curr.second;	
		if(curr.first == 1) {
			int temp = matrix[A][M - 1];
			for(int c = M - 1; c >= 1; c--)
				matrix[A][c] = matrix[A][c - 1];
			matrix[A][0] = temp;
		} else {
			int temp = matrix[N - 1][A];
			for(int r = N - 1; r >= 1; r--)
				matrix[r][A] = matrix[r - 1][A];
			matrix[0][A] = temp;
		}
	}

	for(int r = 0; r < N; r++) {
		for(int c = 0; c < M; c++) {
			if(c != 0) printf(" ");
			printf("%d", matrix[r][c]);
		}
		cout << endl;
	}
}
