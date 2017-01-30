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

class DropCoins {
public:
	int getMinimum(vector <string>, int);
};

int DropCoins::getMinimum(vector <string> board, int K) {
	int minMoves = -1;
	int M = board.size();
	int N = board[0].size();	
	for(int up = 0; up < M; up++) {
		for(int right = 0; right < N; right++) {
			for(int down = 0; down < M - up; down++) {
				for(int left = 0; left < N - right; left++) {
					int moves = up + right + down + left;
					moves += min(up, down);
					moves += min(right, left);
					
					int remain = 0;
					for(int r = up; r < M - down; r++) {
						for(int c = left; c < N - right; c++) {
							if(board[r][c] == 'o') remain++;
						}
					}

					if(remain == K) {
						if(minMoves == -1 or moves < minMoves) minMoves = moves;
					}
				}
			}
		}
	}
	return minMoves;	
}
