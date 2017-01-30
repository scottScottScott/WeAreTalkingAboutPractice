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

class Egalitarianism3 {
public:
	int maxCities(int, vector <int>, vector <int>, vector <int>);
};

int Egalitarianism3::maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
	vector<vector<int>> adjMat(n, vector<int> (n, 1e6));
	for(int i = 0; i < a.size(); i++) {
		adjMat[a[i] - 1][b[i] -1] = len[i];
		adjMat[b[i] - 1][a[i] -1] = len[i];
	}
	
	for(int i = 0; i < n; i++)
		adjMat[i][i] = 0;
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
		}
	}

	int result = 1;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int currDist = adjMat[i][j];
			vector<int> temp {i, j};
			for(int k = 0; k < n; k++) {
				int z = 0;
				for( ; z < temp.size(); z++) {
					if(adjMat[k][temp[z]] != currDist) 
						break;
				}
				if(z == temp.size()) temp.push_back(k);
			}	
			result = max(result, (int) temp.size());
		}
	}
	return result;
}
