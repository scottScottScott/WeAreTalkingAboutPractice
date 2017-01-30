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

int N, M;

bool isValid(vector<string> &grid) {
	bool result = true;
	for(int c = 0; c < M; c++) {
		int count = 1;
		for(int r = 1; r < N; r++) {
			if(grid[r][c] == grid[r - 1][c]) count++;	
			else count = 1;

			if(count > N / 2) result = false;
		}
	}
	return result;
}

class TaroJiroGrid {
public:
	int getNumber(vector <string>);
};

int TaroJiroGrid::getNumber(vector <string> grid) {
	N = grid.size();
	M = grid[0].size();

	if(isValid(grid)) return 0;

	for(int	R = 0; R < N; R++) {
		vector<string> currGrid = grid;
		for(int c = 0; c < M; c++)
			currGrid[R][c] = 'W';
		if(isValid(currGrid))
			return 1;

		for(int c = 0; c < M; c++)
			currGrid[R][c] = 'B';
		if(isValid(currGrid))
			return 1;
	}
	return 2;
}
