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

int numDivisors(int N) {
	int result = 0;
	for(int i = 1; i * i <= N; i++) {
		if(N % i == 0) {
			result += 2;
			if(i * i == N)
				result--;
		}
	}
	return result;
}

class DivisorsPower {
public:
	long long findArgument(long long);
};

long long DivisorsPower::findArgument(long long n) {
	long long result = -1;			
	for(int P = 2; P < 60; P++) {
		int low = 2;
		int high = 1e9;
		while(low <= high) {
			int mid = low + (high - low) / 2;
			long long curr = 1;
			long long bound = 1e18 / mid;
			for(int i = 1; i <= P; i++) {
				if(curr > bound) {
					curr = -1;
					break;
				}
				curr *= mid;
			}
			if(curr == n) {
				if(numDivisors(mid) == P)
					result = mid;
				break;
			}
			else if(curr == -1 or curr > n)	
				high = mid - 1;
			else
				low = mid + 1;
		}
	}

	return result;
}
