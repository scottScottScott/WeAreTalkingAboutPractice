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

class ImportantSequence {
public:
	int getCount(vector <int>, string);
};

int ImportantSequence::getCount(vector <int> B, string operators) {
	long low = 1;
	long high = 100 * 1e9;
	bool isInfinite = true;

	for(int i = 0; i < operators.size(); i++) {
		if(operators[i] == '-') {
			high -= B[i];
			low -= B[i];
			if(low < 1) low = 1;
		}
		else if(operators[i] == '+') {
			if(B[i] >= 0) {
				isInfinite = false;
				long newHigh = B[i] - low;
				long newLow = B[i] - high >= 1 ? B[i] - high : 1;
				high = newHigh;
				low = newLow;
			}
			else if(B[i] < 0) return 0;
		}
		if(high < low or high <= 0) return 0;
	}	

	return isInfinite ? -1 : high - low + 1;
}
