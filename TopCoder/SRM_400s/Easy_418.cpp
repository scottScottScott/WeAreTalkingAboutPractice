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

class TwoLotteryGames {
public:
	double getHigherChanceGame(int, int, int);
};

double choose(int a, int b) {
	double result = 1;
	for(int i = a; i > a - b; i--)
		result *= i;
	for(int i = 1; i <= b; i++)
		result /= i;
	return result;
}

double TwoLotteryGames::getHigherChanceGame(int n, int m, int k) {
	double denom = choose(n, m) * choose(n, m);	
	double num = 0;
	for(int i = k; i <= m; i++) {
		double curr = choose(n, i);
		curr *= choose(n - i, m - i);
		curr *= choose(n - m, m - i);
		num += curr;
	}
	return num / denom;
}



