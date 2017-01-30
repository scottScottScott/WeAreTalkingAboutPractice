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

class ORSolitaire {
public:
	int getMinimum(vector <int>, int);
};

bool isValid(int curr, int goal) {
	for(int i = 0; i < 31; i++) {
		if( (curr >> i) & 1) {
			if( ((goal >> i) & 1) == 0)
				return false;
		}
	}
	return true;
}

int ORSolitaire::getMinimum(vector <int> numbers, int goal) {
	int x = 0;
	for(int curr : numbers)
		if(isValid(curr, goal)) x |= curr;
	if(x != goal) return 0;	
	int result = numbers.size();
	for(int i = 0; i < 31; i++) {	
		if( ((goal >> i) & 1) != 1) continue;
		int count = 0;
		for(int curr : numbers) {
			if(isValid(curr, goal))
				count += (curr >> i) & 1;
		}
		result = min(result, count);
	}
	return result;
}



