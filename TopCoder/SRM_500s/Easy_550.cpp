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

class RotatingBot {
public:
	int minArea(vector <int>);
};

int RotatingBot::minArea(vector<int> moves) {
	int width = 0;	
	int height = 0;

	int tempWidth = 0;
	int tempHeight = 0;

	int N = moves.size();
	for(int i = 0; i < N; i++) {
		if(i == 0) {
			width = 1 + moves[0];		
			height = 1;
		}
		else if(i == 1) {
			height += moves[1];
		}	
		else if(i == 2) {
			if(moves[2] + 1 < width) {
				if(i != N - 1)
					return -1;
			}	
			else {
				width = moves[2] + 1;
			}
		}
		else if(i == 3) {
			if(moves[3] + 1 < height) {
				if(i != N - 1)
					return -1;
			}
			else {
				tempHeight = height;
				height = moves[3] + 1;
				tempHeight = height - tempHeight - 1;
				tempWidth = width - 1;
			}
		}
		else {
			if(i % 2 == 0) {
				if(moves[i] > tempWidth) return -1;
				if(moves[i] < tempWidth and i != N - 1) return -1;
				tempWidth--;

			}
			if(i % 2 == 1) {
				if(moves[i] > tempHeight) return -1;
				if(moves[i] < tempHeight and i != N - 1) return -1;
				tempHeight--;
			}
		}
	}
	
	return width * height;
}
