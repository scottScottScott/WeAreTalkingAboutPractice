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

class Family {
public:
	string isFamily(vector <int>, vector <int>);
};

string Family::isFamily(vector <int> parent1, vector <int> parent2) {
	int N = parent1.size();	
	vector<vector<int>> adjList(N);
	for(int i = 0; i < N; i++) {
		if(parent1[i] != -1) {
			adjList[parent1[i]].push_back(i);
			adjList[parent2[i]].push_back(i);
		}
	}

	vector<int> classify(N);	
	vector<bool> visited(N);
	bool result = true;
	for(int i = 0; i < N; i++) {
		if(parent1[i] == -1 or visited[i]) continue;
		deque<int> Q{i};
		visited[i] = 1;
		while(!Q.empty()) {
			int curr = Q.front();	
			Q.pop_front();
			int P1 = parent1[curr];
			int P2 = parent2[curr];
			visited[curr] = 1;
			vector<int> nextP;
			if(classify[P1] != 0 and classify[P1] == classify[P2]) {
					result = false;
					break;
			}
			if(classify[P1] == 0 and classify[P2] == 0) {
				classify[P1] = 1;
				classify[P2] = 2;
				nextP.push_back(P1);
				nextP.push_back(P2);
			}
			else if(classify[P1] != 0 and classify[P2] == 0) {
				if(classify[P1] == 1) classify[P2] = 2;
				else classify[P2] = 1;
				nextP.push_back(P2);
			}
			else if(classify[P1] == 0 and classify[P2] != 0) {
				if(classify[P2] == 1) classify[P1] = 2;
				else classify[P1] = 1;
				nextP.push_back(P1);
			}
			for(int P : nextP) {
				for(int x : adjList[P]) {
					if(!visited[x]) {
						visited[x] = 1;
						Q.push_back(x);
					}	
				}
			}
		}
	}
	return result ? "Possible" : "Impossible";
}
