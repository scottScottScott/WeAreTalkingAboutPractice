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

class CompositeSmash {
public:
	string thePossible(int, int);
};

bool r_smash(int N, int target, unordered_map<int, bool> &possible) {
	if(possible.count(N)) return possible[N];

	bool valid = true;
	bool isPrime = true;
	for(int x = 2; x <= sqrt(N); x++) {
		if(N % x == 0) {
			isPrime = false;
			int A = x;
			int B = N / x;
			
			if(!r_smash(A, target, possible) and !r_smash(B, target, possible)) {
				valid = false;
				break;
			}
		}			
	}	

	possible[N] = (isPrime or !valid) ? false : true;
	return possible[N];
}

string CompositeSmash::thePossible(int N, int target) {
	unordered_map<int, bool> possible;
	possible[target] = true;
	
	return r_smash(N, target, possible) ? "Yes" : "No";
}
