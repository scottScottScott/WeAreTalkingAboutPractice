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

class CubeWalking {
public:
	string finalPosition(string);
};

string CubeWalking::finalPosition(string movement) {
	int D = 0;
	pii curr {1, 1};
	vector<pii> step{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	for(char X : movement) {
		if(X == 'L') 
			D = (D + 3) % 4;
		else if(X == 'R') 
			D = (D + 1) % 4;
		else {
			curr.first += step[D].first;	
			curr.second += step[D].second;

			curr.first = (curr.first + 3) % 3;
			curr.second = (curr.second + 3) % 3;
		}
	}

	if(curr.first == 1 and curr.second == 1) return "GREEN";
	if(curr.first == 1 or curr.second == 1) return "BLUE";
	return "RED";
}



