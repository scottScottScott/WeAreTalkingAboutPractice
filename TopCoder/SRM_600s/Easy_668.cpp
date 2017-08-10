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

class PaintTheRoom {
public:
	string canPaintEvenly(int, int, int);
};

string PaintTheRoom::canPaintEvenly(int R, int C, int K) {
	string good = "Paint";
	string bad = "Cannot paint";

	if( K == 1 or (R % 2 == 0 or C % 2 == 0))
		return good;
	else
		return bad;	
}
