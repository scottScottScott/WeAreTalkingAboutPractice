#include <iostream>
#include <vector>

using namespace std;

int N, K, A, M;

int main() {
	cin >> N >> K >> A >> M;
	vector<int> moves(M);
	for(int i = 0; i < M; i++) {
		cin >> moves[i];
		moves[i]--;
	}
	
	int low = 1;
	int high = M + 1;
	while(low < high) {
		int mid = low + (high - low) / 2;	

		int ships = 0;
		vector<bool> board(N);
		for(int i = 0; i < mid; i++)
			board[moves[i]] = 1;
		int free = 0;
		for(int i = 0; i <= N; i++) {
			if(i != N and board[i] == 0)
				free++;
			else {
				if(free >= A) {
					ships++;
					free -= A;
				}
				ships += free / (A + 1);
				free = 0;
			}
		}
	
		if(ships < K)
			high = mid;
		else low = mid + 1;
	}

	cout << (low == M + 1 ? -1 : low) << endl;
}
