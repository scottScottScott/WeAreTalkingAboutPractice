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

class PerfectPermutation {
public:
	int reorder(vector <int>);
};

int PerfectPermutation::reorder(vector <int> P) {
	int N = P.size();
	int result = 0;	
	vector<bool> visited(N);
	for(int i = 0; i < P.size(); i++) {
		if(visited[i] == 1) continue; 
		result++;
		int curr = i;
		while(!visited[curr]) {
			visited[curr] = true;
			curr = P[curr];
		}
	}
	return (result == 1) ? 0 : result;
}
