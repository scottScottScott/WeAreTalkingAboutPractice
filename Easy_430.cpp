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

class BitwiseEquations {
public:
	long long kthPlusOrSolution(int, int);
};

long long BitwiseEquations::kthPlusOrSolution(int x, int k) {
	long long result = 0;
	int j = 0;
	for(int i = 0; i < 63; i++) {
		if(j >= 31) break;
		
		if( i < 31 and (x >> i) & 1) continue;
		else {
			if( (k >> j) & 1)
				result |= 1LL << i;
			j++;
		}
	}
	
	return result;
}
