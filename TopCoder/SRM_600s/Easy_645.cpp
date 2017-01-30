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

class JanuszTheBusinessman {
public:
	int makeGuestsReturn(vector <int>, vector <int>);
};

int JanuszTheBusinessman::makeGuestsReturn(vector <int> arrivals, vector <int> departures) {
	vector<pii> info;		
	for(int i = 0; i < arrivals.size(); i++) {
		info.emplace_back(arrivals[i], departures[i]);
	}
	sort(info.begin(), info.end());
	int result = 0;
	int min_val = -1;	
	int max_val = -1;
	int i = 0;
	while(i < info.size()) {
		pii curr = info[i];
		if(min_val == -1) {
			min_val = curr.second;
			max_val = max(curr.second, max_val);
			i++;
		}
		else if(curr.first > min_val) {
			int next_max = -1;
			while(i < info.size() and info[i].first <= max_val) {
				next_max = max(info[i].second, next_max);	
				i++;
			}
			min_val = -1;
			max_val = next_max;
			result++;
		}
		else {
			max_val = max(max_val, curr.second);
			min_val = min(min_val, curr.second);
			i++;
		}
	}
	if(min_val != -1) result++;
	return result;
}
