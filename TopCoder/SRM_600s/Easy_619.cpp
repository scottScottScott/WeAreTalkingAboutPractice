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

class SplitStoneGame {
public:
	string winOrLose(vector <int>);
};

string SplitStoneGame::winOrLose(vector <int> number) {
	sort(number.rbegin(), number.rend());
	int N = number.size();	
	if(N <= 2 or number[0] == 1 or N % 2 == 0) return "LOSE";
	else return "WIN";
}



