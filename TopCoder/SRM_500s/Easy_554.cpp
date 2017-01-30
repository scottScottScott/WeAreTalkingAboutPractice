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

class TheBrickTowerEasyDivOne {
public:
	int find(int, int, int, int);
};

int TheBrickTowerEasyDivOne::find(int redCount, int redHeight, int blueCount, int blueHeight) {
	int result = 0;
	int x = min(redCount, blueCount);
	result += (redHeight != blueHeight) ? x * 3 : x * 2;
	if(blueCount != redCount) result++;	
	return result;
}
