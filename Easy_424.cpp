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

bool getFactors(int N, vector<int> &factors) {
	for(int i = 2; i < 10; i++) {
		while(N % i == 0) {
			N /= i;
			factors.push_back(i);
		}
	}
	return N == 1;
}

class ProductOfDigits {
public:
	int smallestNumber(int);
};

int ProductOfDigits::smallestNumber(int N) {
	if(N == 1) return 1;
	vector<int> factors;
	bool valid = getFactors(N, factors);
	if(!valid) return -1;
	int result = 0;
	int currVal = 0;
	for(int x : factors) {
		if(currVal == 0) {
			currVal = x;
			result++;
		}
		else if(currVal * x < 10)
			currVal *= x;
		else {
			result++;
			currVal = x;
		}
	}
	
	return result;
}
