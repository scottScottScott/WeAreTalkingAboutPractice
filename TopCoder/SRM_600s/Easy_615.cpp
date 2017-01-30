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
typedef long long ll;

class AmebaDiv1 {
public:
	int count(vector <int>);
};

int AmebaDiv1::count(vector <int> X) {
	set<long> result;		
	for(int x : X) result.insert(x);

	for(long curr : X) {
		for(int next : X)
			if(curr == next) curr *= 2; 
		if(result.count(curr)) result.erase(curr);
	}

	return result.size();
}
