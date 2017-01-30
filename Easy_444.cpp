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

class UnfoldingTriangles {
public:
	int solve(vector <string>, int);
};

int UnfoldingTriangles::solve(vector <string> grid, int unfoldLimit) {
	int result = -1;
	int N = grid.size();
	int M = grid[0].size();
	for(int r = 0; r < N; r++) {
		for(int c = 0; c < M; c++) {

			int used = 0;	
			int area = 0;
			for(int C = c; C < M; C++) {
				
				int size = C - c + 1;
				if(r + 1 < size) break;
				if(r + 1 < N and grid[r + 1][C] == '#') break;

				bool valid = true;
				bool valid_2 = true; 
				for(int R = r; R > r - size; R--) {
					if(C + 1 < M and grid[R][C + 1] == '#') valid_2 = false;

					if(grid[R][C] == '.') valid = false;
					else if(R == r - size + 1 and grid[R][C] != '/') valid = false;
					else if(R != r - size + 1 and grid[R][C] == '/'){
						if(used == unfoldLimit) valid = false;	
						used++;
					}
					area++;
				}

				if(valid and valid_2) result = max(result, area);
				else if(!valid) break;	
			}
		}
	}
	return result;
}



