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

class LampsGrid {
public:
	int mostLit(vector <string>, int);
};

int LampsGrid::mostLit(vector <string> initial, int K) {
	int M = initial.size();
	int N = initial[0].size();
	int result = 0;
	for(int curr = 0; curr < M; curr++) {
		vector<vector<bool>> temp(M, vector<bool> (N));	
		int flips = 0;
		for(int c = 0; c < N; c++) {
			bool reverse = (initial[curr][c] == '0');
			flips += reverse;
			for(int r = 0; r < M; r++) {
				if(initial[r][c] == '0') {
					if(reverse) temp[r][c] = 1;
					else temp[r][c] = 0;
				}
				else {
					if(reverse) temp[r][c] = 0;
					else temp[r][c] = 1;
				}
			}
		}
		if(K % 2 != flips % 2 or flips > K) continue;
		int count = 0;
		for(int r = 0; r < M; r++) {
			bool valid = true;
			for(int c = 0; c < N; c++) {
				if(temp[r][c] == 0) 
					valid = false;
			}
			count += valid;
		}
		result = max(result, count);	
	}
	return result;	
}
