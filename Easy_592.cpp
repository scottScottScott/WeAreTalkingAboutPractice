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

class LittleElephantAndBalls {
public:
	int getNumber(string);
};

int LittleElephantAndBalls::getNumber(string S) {
	vector<int> color_count(3);
	unordered_map<char, int> M{ {'R', 0}, {'G', 1}, {'B', 2} };

	int count = 0;	
	for(char x : S) {
		for(char y : color_count) {
			if(y == 1) count += 1;
			else if(y >= 2) count += 2;
		}
		color_count[M[x]]++;
	}
	return count;
}
