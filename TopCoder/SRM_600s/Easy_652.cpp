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

typedef long long ll;

const int MOD = 1e9 + 7;

class ThePermutationGame {
public:
	int findMin(int);
};

int ThePermutationGame::findMin(int N) {
	ll result = 1;		
	vector<bool> prime(N + 1, 1);
	for(ll i = 2; i <= sqrt(N); i++) {
		if(!prime[i]) continue;
		for(ll j = i * i; j <= N; j += i)
			prime[j] = 0;
	}
	for(int i = 2; i <= N; i++) {
		if(!prime[i]) continue;
		ll j = i;
		while(j <= N) {
			result *= i;
			result %= MOD;
			j *= i;
		}
	}
	return result;
}
