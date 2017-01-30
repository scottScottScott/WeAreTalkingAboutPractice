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
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long, long> pll;

class TypoCoderDiv1 {
public:
	int getmax(vector <int>, int);
};

int memo[51][2200];

int TypoCoderDiv1::getmax(vector <int> D, int X) {
	int result = 0;
	memset(memo, -1, sizeof(memo));	
	memo[0][X] = 0;
	for(int i = 0; i < D.size(); i++) {
		int j = i + 1;
		for(int score = 0; score < 2200; score++) {
			if(memo[i][score] == -1) continue;
			if(score - D[i] <= 0) memo[j][0] = max(memo[j][0], memo[i][score]);
			if(score - D[i] > 0 and score - D[i] < 2200)
				memo[j][score - D[i]] = max(memo[j][score - D[i]], memo[i][score]);
			if(score + D[i] < 2200)
				memo[j][score + D[i]] = max(memo[j][score + D[i]], memo[i][score]);
			if(score + D[i] >= 2200) {
				if(i + 1 < D.size() and score + D[i] - D[i + 1] < 2200) {
					int next = max(0, score + D[i] - D[i + 1]);
					memo[j + 1][next] = max(memo[j + 1][next], 2 + memo[i][score]);
					result = max(result, memo[j + 1][next]);
				}
				else if(i + 1 == D.size())
					result = max(result, 1 + memo[i][score]);
			}
		}
	}	

	return result;
}
