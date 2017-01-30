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

class AlienAndHamburgers {
public:
	int getNumber(vector <int>, vector <int>);
};

int AlienAndHamburgers::getNumber(vector <int> type, vector <int> taste) {
	vector<pii> negative;
	int typeCount = 0;
	vector<bool> T(100 + 1);
	int total = 0;
	for(int i = 0; i < type.size(); i++) {
		if(taste[i] >= 0) {
			if(T[type[i]] == 0) {
				T[type[i]] = 1;
				typeCount++;
			}
			total += taste[i];
		}
		else negative.emplace_back(taste[i], type[i]);
	}
	
	int result = total * typeCount;
	sort(negative.rbegin(), negative.rend());
	for(int i = 0; i < negative.size(); i++) {
		if(T[negative[i].second] == 0) {
			T[negative[i].second] = 1;
			typeCount++;
			total += negative[i].first;
			if(total * typeCount > result)
				result = total * typeCount;
			else break;
		}
	}
	return result;
}
