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

const long long MAX = 1e18;

class StrongPrimePower {
public:
	vector <int> baseAndExponent(string);
};

bool isPrime(long long A) {
	for(int i = 2; i * i <= A; i++)
		if(A % i == 0) return false;
	return true;
}

vector<int> StrongPrimePower::baseAndExponent(string n) {
	vector<int> result;
	long long X = stol(n);	
	long long low = 2; 
	long long high = X;
	
	for(int currPower = 2; currPower <= 60; currPower++) {
		low = 2;
		while(low <= high) {
			long long mid = low + (high - low) / 2;
			long long currVal = mid;
			long long maxVal = MAX / mid;
			bool valid = true;
			for(int i = 2; i <= currPower; i++) {
				if(currVal > maxVal) valid = false;
				currVal *= mid;
			}
			
			if(!valid or currVal > X)
				high = mid - 1;
			else if(currVal == X) {
				if(isPrime(mid)) {
					result.push_back(mid);
					result.push_back(currPower);
					return result;
				}
				else break;
			}
			else low = mid + 1;
		}
	}

	return result;
}
