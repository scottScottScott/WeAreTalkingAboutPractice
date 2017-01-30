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

class MagicalStringDiv1 {
public:
	int getLongest(string);
};

int MagicalStringDiv1::getLongest(string S) {
	int result = 0;
	int leftCnt = 0;
	int rightCnt = 0;
	for(char C : S)
		if(C == '<') leftCnt++;
	for(int i = 0; i < S.size(); i++) {
		if(S[i] == '<')
			leftCnt--;
		else {
			rightCnt++;
			result = max(result, 2 * min(leftCnt, rightCnt));
		}
	}
	return result;
}
