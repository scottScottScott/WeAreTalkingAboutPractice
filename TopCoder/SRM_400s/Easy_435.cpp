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

class CellRemoval {
public:
	int cellsLeft(vector <int>, int);
};

int CellRemoval::cellsLeft(vector <int> parent, int deletedCell) {
	int N = parent.size();	
	vector<vector<int>> children(N);
	int root = -1;
	for(int i = 0; i < parent.size(); i++) {
		if(parent[i] == -1)
			root = i;
		else
			children[parent[i]].push_back(i);
	}	
	deque<int> Q{root};	
	int result = 0;
	while(!Q.empty()) {
		int curr = Q.front();
		Q.pop_front();
		if(curr == deletedCell) continue;

		if(children[curr].size() == 0)	
			result++;
		else{
			for(int next : children[curr])
				Q.push_back(next);
		}
	}
	return result;
}
