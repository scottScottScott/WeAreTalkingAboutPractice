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

class BuildingHeights {
public:
	int minimum(vector <int>);
};

int BuildingHeights::minimum(vector <int> heights) {
	int result = 0;	
	sort(heights.begin(), heights.end());
	int N = heights.size();
	for(int same = 2; same <= N; same++) {
		int curr = 0;
		for(int i = 0; i < same; i++)
			curr += heights[same - 1] - heights[i];
		int minNeed = curr;
		for(int i = same; i < N; i++) {
			curr += same * (heights[i] - heights[i - 1]);
			curr -= heights[i] - heights[i - same];
			minNeed = min(minNeed, curr);
		}
		minNeed = min(minNeed, curr);
		result ^= minNeed;
	}
	return result;
}



