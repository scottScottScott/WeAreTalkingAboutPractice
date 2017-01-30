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

class MaxMinTreeGame {
public:
	int findend(vector <int>, vector <int>);
};

int MaxMinTreeGame::findend(vector <int> edges, vector <int> costs) {
	int N = costs.size();
	vector<vector<int>> adjList(N);
	for(int i = 0; i < N - 1; i++) {
		adjList[i + 1].push_back(edges[i]);
		adjList[edges[i]].push_back(i + 1);
	}
	int result = -1;
	for(int i = 0; i < N; i++) {
		if(adjList[i].size() == 1)
			result = max(result, costs[i]);
	}
	return result;
}



