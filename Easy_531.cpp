#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long, long> pll;

const int MOD = 1e9 + 7;	

class NoRepeatPlaylist {
public:
	int numPlaylists(int, int, int);
};

long getVal(long N, long M, long P) {
	long total = N;
	for(int i = 1; i <= M and i < P; i++)
		total = (total * (N - i) ) % MOD;
	for(int i = M + 1; i < P; i++)
		total =	(total * (N - M) ) % MOD;
	return total;
}

int NoRepeatPlaylist::numPlaylists(int N, int M, int P) {	
	vector<vector<int>> choose(N + 1, vector<int> (N + 1));
	choose[0][0] = 1;
	for(int row = 1; row <= N; row++) {
		choose[row][0] = choose[row - 1][0];
		for(int col = 1; col < row; col++) {
			choose[row][col] = (choose[row - 1][col - 1] + choose[row - 1][col]) % MOD;
		}
		choose[row][row] = choose[row - 1][row - 1];
	}

	bool sign = 0;
	long total = getVal(N, M, P);
	for(int k = N - 1; k >= M; k--) {
		if(sign == 1)
			total = (total + choose[N][k] * getVal(k, M, P)) % MOD;
		else {
			total = (total - choose[N][k] * getVal(k, M, P)) % MOD;
			total = (total + MOD) % MOD;
		}
		sign = !sign;
	}	
	return total;
}
