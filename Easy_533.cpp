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

class CasketOfStar {
public:
	int maxEnergy(vector <int>);
};

int r_max(int start, int end, vector<vector<int>> &memo, vector<int> &weight) {
	int &retVal = memo[start][end];
	if(retVal != -1) return retVal;
	
	if(end == start + 1) return 0;
	for(int i = start + 1; i < end; i++) {
		int temp = weight[start] * weight[end] + r_max(start, i, memo, weight) + r_max(i, end, memo, weight);
		retVal = max(retVal, temp);
	}
	return retVal;
}

int CasketOfStar::maxEnergy(vector <int> weight) {
	int N = weight.size();
	vector<vector<int>> memo(N, vector<int> (N, -1));

	return r_max(0, N - 1, memo, weight);
}
