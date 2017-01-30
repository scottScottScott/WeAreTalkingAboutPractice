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

class PairGame {
public:
	int maxSum(int, int, int, int);
};

int PairGame::maxSum(int a, int b, int c, int d) {
	set<pii> S;	
	S.emplace(a, b);
	while(a != b) {
		if(a > b) a -= b;	
		else b -= a;
		S.emplace(a, b);
	}

	if(S.count(make_pair(c, d))) return c + d;
	while(c != d) {
		if(c > d) c -= d;
		else d -= c;
		if(S.count(make_pair(c, d)))
			return c + d;
	}

	return -1;
}
