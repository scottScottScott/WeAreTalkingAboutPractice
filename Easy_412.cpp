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

class ForbiddenStrings {
public:
	long long countNotForbidden(int);
};

long memo[30][3][3];

long long ForbiddenStrings::countNotForbidden(int n) {
	if(n == 1) return 3;
	if(n == 2) return 9;

	long result = 0;
	for(int i = 1; i < n; i++) {
		for(int first = 0; first < 3; first++) {
			for(int second = 0; second < 3; second++) {
				if(i == 1) {
					memo[1][first][second] = 1;
					continue;
				}
				for(int third = 0; third < 3; third++) {
					if(first == second or first == third or second == third)
						memo[i][second][third] += memo[i - 1][first][second];
				}	
			}
		}
	}
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			result += memo[n - 1][i][j];
	}
	return result;
}
