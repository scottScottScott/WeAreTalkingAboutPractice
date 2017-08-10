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

class FoxesOfTheRoundTable {
public:
	vector <int> minimalDifference(vector <int>);
};

vector <int> FoxesOfTheRoundTable::minimalDifference(vector <int> h) {
	int n = h.size();
	vector<pii> info;
	vector<pii> result;	
	for(int i = 0; i < n; i++)
		info.emplace_back(h[i], i);	
	sort(info.begin(), info.end());
	for(int i = 0; i < n; i += 2)
		result.push_back(info[i]);
	for(int i = (n % 2 == 0 ? n - 1 : n - 2); i >= 0; i -= 2)
		result.push_back(info[i]);
	vector<int> answer(n);
	for(int i = 0; i < n; i++) 
		answer[i] = result[i].second;	
	return answer;
}
