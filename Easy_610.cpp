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

class TheMatrix {
public:
	int MaxArea(vector <string>);
};

int TheMatrix::MaxArea(vector <string> board) {
	int M = board.size();
	int N = board[0].size();	

	vector<vector<int>> memo(M, vector<int>(N, 1));
	for(int row = 0; row < M; row++) {
		for(int col = N - 2; col >= 0; col--) {
			if(board[row][col] != board[row][col + 1])
				memo[row][col] = memo[row][col + 1] + 1;
		}
	}

	int result = 0;
	for(int row = 0; row < M; row++) {
		for(int col = 0; col < N; col++) {
			int width = memo[row][col];
			result = max(result, width);
			for(int next = row + 1; next < M; next++) {
				if(board[next - 1][col] == board[next][col]) break;
				width = min(width, memo[next][col]);
				result = max(result, width * (next - row + 1));
			}
		}
	}

	return result;
}
