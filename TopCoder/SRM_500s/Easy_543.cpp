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

class EllysXors {
public:
	long long getXor(long long, long long);
};

long long singleXor(long long A) {
	long long result = (A % 4 == 1 or A % 4 == 2);	
	for(int i = 63; i >= 1; i--) {
		long long temp = 1LL << i;
		if(A & temp) {
			A ^= temp;
			if(A % 2 == 0) result ^= temp;
		}
	}
	return result;
}

long long EllysXors::getXor(long long L, long long R) {
	return singleXor(L - 1) ^ singleXor(R);		
}
