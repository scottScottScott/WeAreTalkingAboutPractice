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

class NextNumber {
public:
	int getNextNumber(int);
};

int NextNumber::getNextNumber(int N) {
	int count = 0;		
	for(int i = 0; i < 31; i++) {
		if((N >> i) & 1) {
			count++;
			N ^= 1 << i;
		}	
		else if(count != 0) {
			int result = N;	
			result |= 1 << i;
			count--;
			for(int j = 0; j < count; j++)
				result |= 1 << j;	
			return result;
		}
	}	
	return -1;
}
