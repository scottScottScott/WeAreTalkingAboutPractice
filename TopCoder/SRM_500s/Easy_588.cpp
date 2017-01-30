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

class GUMIAndSongsDiv1 {
public:
	int maxSongs(vector <int>, vector <int>, int);
};

int GUMIAndSongsDiv1::maxSongs(vector <int> duration, vector <int> tone, int T) {
	vector<pii> info;
	for(int i = 0; i < duration.size(); i++)
		info.emplace_back(tone[i], duration[i]);
	sort(info.begin(), info.end());

	vector<pii> memo;
	for(int i = 0; i < info.size(); i++) {		
		for(int j = memo.size(); j >= 1; j--) {
			int temp = memo[j - 1].second + (info[i].first - memo[j - 1].first) + info[i].second;
			if(j == memo.size()) {
				if(temp <= T) memo.emplace_back(info[i].first, temp);
			}
			else if(temp <= memo[j].second + (info[i].first - memo[j].first) ) {
				memo[j].second = temp;
				memo[j].first = info[i].first;
			}
		}
		
		if(memo.size() == 0) {
			if(info[i].second <= T) memo.push_back(info[i]);
		}
		else if(info[i].second <= memo[0].second + info[i].first - memo[0].first)
			memo[0] = info[i];
	}	
	return memo.size();
}
