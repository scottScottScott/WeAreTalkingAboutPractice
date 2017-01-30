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

class TheSquareRootDilemma {
public:
	int countPairs(int, int);
};

int TheSquareRootDilemma::countPairs(int N, int M) {
	int X = min(N, M);
	vector<int> memo(X + 1, 1);
	memo[1] = 0;
	for(int i = 2; i <= sqrt(X); i++) {
		int y = i * i;
		for(int j = y; j <= X; j += y)
			memo[j] = 0;
	}
	int s_N = sqrt(N);
	int s_M = sqrt(M);
	int result = s_N * s_M;
	for(int i = 2; i <= min(N, M); i++) {
		if(memo[i] == 1)
			result += (int) sqrt(N / i) * (int) sqrt(M / i);
	}
	return result;
}
