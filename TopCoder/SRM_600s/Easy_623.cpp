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

class UniformBoard {
public:
	int getBoard(vector <string>, int);
};

int UniformBoard::getBoard(vector <string> board, int K) {
	int N = board.size();	
	int result = 0;
	
	int A = 0;
	int F = 0;
	for(int r = 0; r < N; r++) {
		for(int c = 0; c < N; c++) {
			if(board[r][c] == 'A') A++;
			else if(board[r][c] == '.') F++;
		}
	}
	for(int r1 = 0; r1 < N; r1++) {
		for(int c1 = 0; c1 < N; c1++) {
			for(int r2 = r1; r2 < N; r2++) {
				for(int c2 = c1; c2 < N; c2++) {
					int area = (r2 - r1 + 1) * (c2 - c1 + 1);
					if(area > A) continue;
					int currA = 0;
					int currF = 0;
					for(int r = r1; r <= r2; r++) {
						for(int c = c1; c <= c2; c++) {
							if(board[r][c] == 'A') currA++;
							else if(board[r][c] == '.') currF++;
						}
					}
					int currP = area - currA - currF;
					int needA = area - currA;
					int moves = needA + currP;
					if(needA != 0 and needA == currP and F == 0) continue;
					if(moves <= K)
						result = max(result, area);
				}	
			}
		}
	}
	return result;
}
