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

class TheLuckyNumbers {
public:
	int count(int, int);
};

int countLucky(int max, string &curr) {
	if(curr.size() >= 9) return 0;
	int count = 0;
	
	vector<char> next_vec {'4', '7'};
	for(char next : next_vec) {
		curr += next;
		int X = stoi(curr);
		if(X <= max) {
			count++;
			count+=countLucky(max, curr);	
		}
		curr.pop_back();
	}
	
	return count;
}

int TheLuckyNumbers::count(int a, int b) {
	string nullStr;
	return countLucky(b, nullStr) - countLucky(a - 1, nullStr);
}
