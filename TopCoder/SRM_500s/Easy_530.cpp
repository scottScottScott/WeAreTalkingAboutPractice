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

class GogoXCake {
public:
	string solve(vector <string>, vector <string>);
};

string GogoXCake::solve(vector <string> cake, vector <string> cutter) {
	int M = cake.size();
	int N = cake[0].size();
	int A = cutter.size();
	int B = cutter[0].size();
	
	vector<string> start(M, string(N, 'X'));
	for(int r = 0; r <= M - A; r++) {
		for(int c = 0; c <= N - B; c++) {
			bool valid = true;
			for(int i = 0; i < A; i++) {
				for(int j = 0; j < B; j++) {
					if(cutter[i][j] == 'X') {}
					else if(start[r + i][c + j] == 'X' and cutter[i][j] == '.' and cake[r + i][c + j] == '.') {}
					else valid = false;
				}
			}
			if(valid) {
				for(int i = 0; i < A; i++) {
					for(int j = 0; j < B; j++) {
						if(cutter[i][j] == '.') start[r + i][c + j] = '.';
					}
				}
			}
		}
	}

	bool valid = true;
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			if(start[i][j] != cake[i][j]) valid = false;
		}
	}
	return valid ? "YES" : "NO";
}
