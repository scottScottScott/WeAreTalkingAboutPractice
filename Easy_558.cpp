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

typedef pair<int, bool> pib;

int N;
string color;

class Stamp {
public:
	int getMinimumCost(string, int, int);
};

int r_dp(int start, int end, int size, vector<vector<int>>& memo) {
	if(end < start) return 0;
	if(memo[start][end] != -2) return memo[start][end]; 

	int& minVal = memo[start][end];
	minVal = INT_MAX;
	int curr = start;
	for(int i = start; i <= end; i++) {
		if(color[curr] == '*') curr++;
		else if(color[i] == color[curr] or color[i] == '*') { }
		else break;

		int numStamps = (i - start + 1) / size;
		if(numStamps < 1) continue;
		numStamps += (i - start + 1) % size != 0;
		int temp = r_dp(i + 1, end, size, memo);
		if(temp == -1) continue;
		minVal = min(minVal, numStamps + temp);
	}	
	if(minVal == INT_MAX) minVal = -1;
	return minVal;
}

int dp_cost(int size) {
	vector<vector<int>> memo(N, vector<int> (N, -2));
	return r_dp(0, N - 1, size, memo);
}

int Stamp::getMinimumCost(string desiredColor, int stampCost, int pushCost) {
	N = desiredColor.size();	
	color = desiredColor;
	int minCost = stampCost + N * pushCost;	
	
	for(int size = 2; size <= N; size++) {
		int temp = dp_cost(size);
		if(temp == -1) continue;
		temp *= pushCost;
		temp += stampCost * size;
		minCost = min(minCost, temp);
	}

	return minCost;
}
