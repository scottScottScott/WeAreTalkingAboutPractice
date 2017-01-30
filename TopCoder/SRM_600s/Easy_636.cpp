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

class ChocolateDividingEasy {
public:
	int findBest(vector <string>);
};

int ChocolateDividingEasy::findBest(vector <string> chocolate) {
	int result = 0;
	int N = chocolate.size();
	int M = chocolate[0].size();

	vector<vector<int>> memo(N, vector<int> (M));
	for(int r = 0; r < N; r++) {
		for(int c = 0; c < M; c++) {
			memo[r][c] = chocolate[r][c] - '0';
			if(c > 0) memo[r][c] += memo[r][c - 1];
			if(r > 0) memo[r][c] += memo[r - 1][c];
			if(c > 0 and r > 0) memo[r][c] -= memo[r - 1][c - 1];
		}
	}

	for(int r1 = 0; r1 + 1 < N; r1++) {
		for(int r2 = r1 + 1; r2 + 1 < N; r2++) {
			for(int c1 = 0; c1 + 1 < M; c1++) {
				for(int c2 = c1 + 1; c2 + 1 < M; c2++) {
					
					int temp = -1;
					vector<int> first {r1, r2, N - 1};
					vector<int> second {c1, c2, M - 1};
					for(int i = 0; i < 3; i++) {
						for(int j = 0; j < 3; j++) {
							int val = memo[first[i]][second[j]];
							if(i != 0 and j != 0) val += memo[first[i - 1]][second[j - 1]];
							if(i != 0) val -= memo[first[i - 1]][second[j]];
							if(j != 0) val -= memo[first[i]][second[j - 1]];
							
							if(temp == -1) temp = val;
							else temp = min(temp, val);
						}
					}
					result = max(temp, result);
					
				}
			}
		}
	}	
	return result;
}
