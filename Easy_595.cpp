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

class LittleElephantAndIntervalsDiv1 {
public:
	long long getNumber(int, vector <int>, vector <int>);
};

long long LittleElephantAndIntervalsDiv1::getNumber(int M, vector <int> L, vector <int> R) {
	vector<int> last(M + 1, -1);
	for(int i = 0; i < L.size(); i++) {
		for(int j = L[i]; j <= R[i]; j++)
			last[j] = i;
	}
	
	long long count = 1;
	for(int i = 0; i < L.size(); i++) {
		bool possible = false;
		for(int j = L[i]; j <= R[i]; j++)
			if(last[j] == i) possible = true;
		if(possible) count *= 2;
	}
	
	return count == 1 ? 0 : count;
}
