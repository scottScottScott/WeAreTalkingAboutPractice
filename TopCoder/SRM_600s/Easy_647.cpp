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

class BuildingTowersEasy {
public:
	int maxHeight(int, vector <int>, vector <int>);
};

int BuildingTowersEasy::maxHeight(int N, vector <int> x, vector <int> t) {
	int result = 0;
	int curr = 0;
	for(int i = 2; i <= N; i++) {
		bool changed = false;
		for(int j = 0; j < x.size(); j++) {
			if(x[j] < i) continue; 

			int dist = x[j] - i;
			if( (curr + 1) - t[j] > dist ) {
				if(curr - t[j] > dist )
					curr--;
				changed = true;
				break;
			}
		}
		if(!changed)
			curr++;
		result = max(result, curr);
	}
	return result;
}



