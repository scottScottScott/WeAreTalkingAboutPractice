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

class WinterAndPresents {
public:
	long long getNumber(vector <int>, vector <int>);
};

long long WinterAndPresents::getNumber(vector<int> apple, vector<int> orange) {
	long long result = 0;
	for(int X = 1; X <= apple[0] + orange[0]; X++) {
		int minApple = 0;
		int maxApple = 0;
		bool valid = true;
		for(int i = 0; i < apple.size(); i++) {
			if(apple[i] + orange[i] < X)
				valid = false;
			minApple += max(0, X - orange[i]);
			maxApple += min(apple[i], X);
		}
		if(!valid) break;
		result += maxApple - minApple + 1;
	}
	return result;
}
