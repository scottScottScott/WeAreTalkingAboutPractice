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

vector<pii> step_vec { {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1} };

pii getKnight(vector<string> &board) {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) 
			if(board[i][j] == 'K') return make_pair(i, j);
	}
	return make_pair(-1, -1);
}

int getNumber(pii curr, vector<string> &board) {
	int result = 0;
	for(pii step : step_vec) {
		pii next {curr.first + step.first, curr.second + step.second};
		if(next.first >= 8 or next.first < 0 or next.second >= 8 or next.second < 0 or board[next.first][next.second] != '.') continue;
		result++;
	}
	return result;
}

class KnightsTour {
public:
	int visitedPositions(vector <string>);
};

int KnightsTour::visitedPositions(vector <string> board) {
	int result = 1;	
	do {
		vector<vector<int>> memo(8, vector<int> (8));
		pii curr = getKnight(board);		
		pii best {-1, -1};
		for(pii step : step_vec) {
			pii next {curr.first + step.first, curr.second + step.second};
			if(next.first >= 8 or next.first < 0 or next.second >= 8 or next.second < 0 or board[next.first][next.second] != '.') continue;
			memo[next.first][next.second] = getNumber(next, board);
			
			if(best.first == -1) best = next;
			else if(memo[next.first][next.second] < memo[best.first][best.second])
				best = next;
		}
		if(best.first == -1) break;	
		result++;
		board[curr.first][curr.second] = '*';
		board[best.first][best.second] = 'K';
	} while(true);
	return result;
}
