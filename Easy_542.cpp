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

class PatrolRoute {
public:
	int countRoutes(int, int, int, int);
};

int PatrolRoute::countRoutes(int X, int Y, int minT, int maxT) {
	const int MOD = 1e9 + 7;
	long result = 0;
	for(int x = 3; x <= X; x++) {
		for(int y = 3; y <= Y; y++) {
			if(x + y < minT or x + y > maxT) continue;
			long count = 6 * (x - 2) * (y - 2);
			count *= (X - x + 1);	
			count %= MOD;
			count *= (Y - y + 1);
			result += count % MOD;
		}
	}
	return result;
}
