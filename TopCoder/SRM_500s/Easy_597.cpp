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

class LittleElephantAndString {
public:
	int getNumber(string, string);
};

int LittleElephantAndString::getNumber(string A, string B) {
	string X = A;
	string Y = B;
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	if(X != Y) return -1;
	
	int moves = 0;	
	int j = B.size() - 1;
	for(int i = A.size() - 1; i >= 0; i--) {
		while(j >= 0 and B[i] != A[j]) {
			j--;
			moves++;
		}
		if(j < 0) return moves;
		j--;
	}
	return moves;
}
