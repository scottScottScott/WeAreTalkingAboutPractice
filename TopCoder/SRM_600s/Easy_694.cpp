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

int memo[256][256][256];

class TrySail {
public:
	int get(vector <int>);
};

int TrySail::get(vector <int> strength) {
	memo[0][0][0] = 1;
	int result = 0;
	for(int n = 1; n <= strength.size() + 1; n++) {
		int x = (n <= strength.size() ? strength[n - 1] : 0);
		for(int i = 255; i >= 0; i--) {
			for(int j = 255; j >= 0; j--) {
				for(int k = 255; k >= 0; k--) {
					if(memo[i][j][k] == n or memo[i][j][k] == -1) {
						if(n == strength.size() + 1) {
							result = max(result, i + j + k);
							continue;
						}
						int n_i = i ^ x;
						int n_j = j ^ x;
						int n_k = k ^ x;

						memo[n_i][j][k] = (memo[n_i][j][k] == n ? -1 : n + 1);	
						memo[i][n_j][k] = (memo[i][n_j][k] == n ? -1 : n + 1);	
						memo[i][j][n_k] = (memo[i][j][n_k] == n ? -1 : n + 1);	
					}
					if(memo[i][j][k] == n) memo[i][j][k] = 0;
					else if(memo[i][j][k] == -1) memo[i][j][k] = n + 1;
				}
			}
		}
	}
	
	return result;
}
