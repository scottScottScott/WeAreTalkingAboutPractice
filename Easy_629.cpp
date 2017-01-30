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

class RectangleCovering {
public:
	int minimumNumber(int, int, vector <int>, vector <int>);
};

int RectangleCovering::minimumNumber(int holeH, int holeW, vector <int> boardH, vector <int> boardW) {
	int result = -1;			
	vector<pii> I { {holeH, holeW}, {holeW, holeH}};
	for(pii curr : I) {
		vector<int> temp;
		for(int i = 0; i < boardH.size(); i++) {
			int first = max(boardH[i], boardW[i]);
			int second = min(boardH[i], boardW[i]);
			if(second > curr.first) temp.push_back(first);
			else if(first > curr.first) temp.push_back(second);
		}
		sort(temp.begin(), temp.end());
		int val = 0;
		int used = 0;
		while(val < curr.second and !temp.empty()) {
			used++;
			val += temp.back();
			temp.pop_back();
		}
		if(val < curr.second) continue;
		if(result == -1) result = used;
		else result = min(result, used);
	}

	return result;
}

