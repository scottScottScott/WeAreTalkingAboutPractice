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

class UnluckyIntervals {
public:
	vector <int> getLuckiest(vector <int>, int);
};

vector <int> UnluckyIntervals::getLuckiest(vector <int> luckySet, int n) {
	sort(luckySet.begin(), luckySet.end());
	vector<pll> result;
	for(int x : luckySet)
		result.emplace_back(0, x);

	for(int i = 0; i < luckySet.size(); i++) {
		int start = (i == 0 ? 0 : luckySet[i - 1]);
		int end = luckySet[i];

		for(int j = start + 1; j <= min(start + 50, end - 1); j++)
			result.emplace_back((long) (j - start) *  (end - j) - 1, j);
		for(int j = end - 1; j >= max(end - 50, start + 50 + 1); j--)
			result.emplace_back((long) (j - start) *  (end - j) - 1, j);
	}

	int next = luckySet[luckySet.size() - 1] + 1;
	while(result.size() < n) {
		result.emplace_back(INT_MAX, next);
		next++;
	}
	sort(result.begin(), result.end());
	vector<int> ret_vec;
	for(int i = 0; i < n; i++)
		ret_vec.push_back(result[i].second);
	return ret_vec;
}
