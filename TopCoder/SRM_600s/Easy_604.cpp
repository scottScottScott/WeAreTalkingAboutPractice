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

class PowerOfThree {
public:
	string ableToGet(int, int);
};

void solve(int x, vector<int> &powers) {
	if(x == 0) return;

	int currPower = 0;
	long currVal = 1;
	long total = 1;
	while(total < x) {
		currPower++;
		currVal *= 3;
		total += currVal;
	}
	x -= currVal;
	powers.push_back(currPower);
		
	solve(abs(x), powers);
}


string PowerOfThree::ableToGet(int x, int y) {
	vector<int> powers;	
	for(int curr : {x, y})
		solve(abs(curr), powers);
	sort(powers.begin(), powers.end());
	for(int i = 0; i < powers.size(); i++)
		if(powers[i] != i) return "Impossible";
	return "Possible";
}
