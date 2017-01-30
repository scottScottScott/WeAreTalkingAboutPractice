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

class AliceGame {
public:
	long long findMinimumValue(long long, long long);
};

long long AliceGame::findMinimumValue(long long x, long long y) {
	long long total = x + y;	
	long long N = 0;	
	while(true) {
		if( N * N == total)	
			break;
		else if(N * N > total)
			return -1;
		N++;
	}
	cout << N << endl;
	for(long long turns = 0; turns <= N; turns++) {
		if( (x + turns) % 2 == 1) continue;
		long long sum = (x + turns) / 2;
		long long low = turns * (turns + 1) / 2;
		long long high = turns * (N + (N - turns + 1)) / 2;
		if(sum >= low and sum <= high)
			return turns;
	}
	return -1;
}
