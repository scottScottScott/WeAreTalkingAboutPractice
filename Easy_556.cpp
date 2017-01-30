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

class XorTravelingSalesman {
	public:
		int maxProfit(vector<int>, vector<string>);
};

int XorTravelingSalesman::maxProfit(vector<int> cityValues, vector<string> roads) {
	int N = cityValues.size();
	vector<vector<bool>> memo(N, vector<bool> (1024));

	vector<vector<int>> adjList(N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(roads[i][j] == 'Y')
				adjList[i].push_back(j);
		}
	}

	int startVal = cityValues[0];
	deque<pii> toVisit { {0, startVal} };
	memo[0][startVal] = 1;
	int maxVal = startVal;
	while(!toVisit.empty()) {
		pii curr = toVisit.front();
		toVisit.pop_front();
		for(int x : adjList[curr.first]) {
			int next = curr.second ^ cityValues[x];
			if(memo[x][next] == 0) {
				memo[x][next] = true;
				toVisit.emplace_back(x, next);
				maxVal = max(maxVal, next);
			}
		}
	}

	return maxVal;
}
