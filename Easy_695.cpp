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

class BearPasswordLexic {
public:
	string findPassword(vector <int>);
};

string BearPasswordLexic::findPassword(vector <int> x) {
	string result;
	deque<int> temp;
	for(int i = x.size() - 1; i >= 0; i--) {
		while(x[i] != 0) {
			int curr = 1;
			for(int j = i; j >= 0; j--) {
				x[j] -= curr;
				curr++;
				if(x[j] < 0) return "";
			}
			temp.push_back(i + 1);
		}
	}
	sort(temp.rbegin(), temp.rend());
	while(!temp.empty()) {
		int curr = temp.front();
		temp.pop_front();
		result += string(curr, 'a');
		if(temp.empty()) continue;
		curr = temp.back();
		temp.pop_back();
		result += string(curr, 'b');
	}
	if(result.size() != x.size()) return "";
	return result;	
}
