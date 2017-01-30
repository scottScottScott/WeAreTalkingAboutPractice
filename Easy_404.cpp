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

class RevealTriangle {
public:
	vector <string> calcTriangle(vector <string>);
};

vector<string> RevealTriangle::calcTriangle(vector<string> questionMarkTriangle) {
	vector<string> Q = questionMarkTriangle;
	int N = questionMarkTriangle.size();	
	int last = N - 1;
	for(int r = last - 1; r >= 0; r--) {
		bool valid = false;
		while(!valid) {
			valid = true;
			for(int c = 0; r + c + 1 < N; c++) {
				int A, B;
				B = Q[r + 1][c] - '0';
				if(Q[r][c] != '?' and Q[r][c + 1] == '?') {
					A = Q[r][c] - '0';		
					Q[r][c + 1] = (B + 10 - A) % 10 + '0';
				}
				else if(Q[r][c] == '?' and Q[r][c + 1] != '?') {
					A = Q[r][c + 1] - '0';	
					Q[r][c] = (B + 10 - A) % 10 + '0';
				}
				else if(Q[r][c] == '?' and Q[r][c + 1] == '?') 
					valid = false;
			}	
		}
	}

	return Q;
}
