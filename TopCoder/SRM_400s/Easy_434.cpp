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

class FindingSquareInTable {
public:
	int findMaximalSquare(vector <string>);
};

int FindingSquareInTable::findMaximalSquare(vector <string> table) {
	int M = table.size();	
	int N = table[0].size();
	
	int result = -1;
	for(int c_y = -M + 1; c_y < M; c_y++) {
		for(int c_x = -N + 1; c_x < N; c_x++) {
			for(int r = 0; r < M; r++) {
				for(int c = 0; c < N; c++) {
					int y = r;			
					int x = c;
					string temp;
					while(y >= 0 and y < M and x >= 0 and x < N) {
						temp += table[y][x];
						y += c_y;
						x += c_x;
						int curr = stoi(temp);
						if( abs(pow((int) (sqrt(curr) + 1e-6), 2) - curr) < 1e-6)
							result = max(result, curr);
						if(c_x == 0 and c_y == 0) break;
					}
				}
			}
		}
	}
	return result;
}
