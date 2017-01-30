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

class P8XGraphBuilder {
public:
	int solve(vector <int>);
};

int P8XGraphBuilder::solve(vector <int> scores) {
	int N = scores.size() + 1;
	vector<int> nodes(N);
	nodes[0] = 0; 
	nodes[1] = scores[0] * 2;
	for(int n = 3; n <= N; n++) {
		for(int j = 1; j <= n - 2; j++) {
			int possible = nodes[n - 1 - j] + scores[j] + (j - 1) * scores[0];
			nodes[n - 1] = max(nodes[n - 1], possible);
		}
	}
	return nodes[N - 1];
}
