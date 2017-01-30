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

class OkonomiyakiParty {
public:
	int count(vector <int>, int, int);
};

int OkonomiyakiParty::count(vector <int> osize, int M, int K) {
	int n = osize.size();
	vector<vector<int>> choose(n + 1, vector<int> (n + 1));	
	choose[0][0] = 1;
	for(int r = 1; r <= n; r++) {
		for(int c = 0; c <= n; c++) {
			choose[r][c] = (c != 0 ? choose[r - 1][c - 1] : 0) + choose[r - 1][c];
			choose[r][c] %= MOD;
		}
	}
	
	long result = 0;
	sort(osize.begin(), osize.end());
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(osize[j] - osize[i] <= K and j - i + 1 >= M)
				result = (result + choose[j - i - 1][M - 2]) % MOD; 	
		}
	}
	return result;
}
