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

class BuildingRoutes {
public:
	int build(vector <string>, int);
};

int BuildingRoutes::build(vector<string> dist, int T) {
	int result = 0;	
	int N = dist.size();
	vector<vector<int>> adjMat(N, vector<int> (N));	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++)
			adjMat[i][j] = dist[i][j] - '0';
	}
	vector<vector<int>> adjMat_s = adjMat;
	for(int k = 0; k < N; k++) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++)
				adjMat_s[i][j] = min(adjMat_s[i][j], adjMat_s[i][k] + adjMat_s[k][j]);
		}
	}	

	for(int u = 0; u < N; u++) {
		for(int v = 0; v < N; v++) {
			if(u == v) continue;
			int count = 0;
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					if(adjMat_s[i][u] + adjMat_s[v][j] + adjMat[u][v] == adjMat_s[i][j])
						count++;
				}
			}
			if(count >= T) 
				result += adjMat[u][v];
		}
	}
	return result;
}
