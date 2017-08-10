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

ll solve(ll E, ll M, ll MH, ll H) {
	if(M < H) {
		ll change = min(MH, H - M);
		MH -= change;
		M += change;
	}
	else if(H < M) {
		ll change = min(MH, M - H);
		MH -= change;
		H += change;
	}
	M += MH / 2;
	H += MH / 2;
	ll result = E;
	result = min(result, min(M, H));
	return result;
}

class ProblemSets {
public:
	long long maxSets(long long, long long, long long, long long, long long);
};

long long ProblemSets::maxSets(long long E, long long EM, long long M, long long MH, long long H) {
	ll low = 0;	
	ll high = EM;
	ll result = 0;
	while(low <= high) {
		ll a = low + (high - low) / 3;
		ll b = high - (high - low) / 3;
		ll ans1 = solve(E + a, M + EM - a, MH, H);
		ll ans2 = solve(E + b, M + EM - b, MH, H);

		if(ans1 < ans2)
			low = a + 1;
		else 
			high = b - 1;

		result = max(result, max(ans1, ans2));
	}
	return result;
}
