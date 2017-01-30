#include <iostream>
#include <vector>
	
using namespace std;

typedef pair<int, int> pii;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<pii> rows(N);
	vector<pii> columns(M);

	for(int k = 1; k <= K; k++) {
		int type;
		cin >> type;
		if(type == 1) {
			int R, color;
			cin >> R >> color;
			rows[--R] = make_pair(k, color); 
		}
		else {
			int C, color;
			cin >> C >> color;
			columns[--C] = make_pair(k, color);
		}
	}	

	for(int r = 0; r < N; r++) {
		for(int c = 0; c < M; c++) {
			if(rows[r].first > columns[c].first)			
				cout << rows[r].second;
			else
				cout << columns[c].second;

			if(c != M - 1) 
				cout << " ";
		}
		cout << endl;
	}
}
