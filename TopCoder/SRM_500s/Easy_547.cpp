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

class Pillars {
public:
	double getExpectedLength(int, int, int);
};

double Pillars::getExpectedLength(int w, int x, int y) {
	long long ll_x = x;
	long long ll_y = y;
	double num = w * min(x, y);
	int maxDiff = max(x, y);	
	long long denom = ll_x * ll_y;
	for(long long d = 1; d < maxDiff; d++) {
		double temp = sqrt(w * w + d * d);
		if(y > d) num += temp * min(y - d, ll_x);
		if(x > d) num += temp * min(x - d, ll_y);
	}
	return num / denom;
}
