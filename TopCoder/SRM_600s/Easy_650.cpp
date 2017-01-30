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

const int MOD = 1e9 + 7;

class TaroFillingAStringDiv1 {
public:
	int getNumber(int, vector <int>, string);
};

int TaroFillingAStringDiv1::getNumber(int N, vector <int> position, string value) {
	long result = 1;	
	vector<pii> info;
	for(int i = 0; i < position.size(); i++)
		info.emplace_back(position[i], value[i] - 'A');
	sort(info.begin(), info.end());
	for(int i = 1; i < info.size(); i++) {
		int free = info[i].first - info[i - 1].first - 1;	
		if(info[i].second == info[i - 1].second and free % 2 == 0)
			result *= free + 1;
		else if(info[i].second != info[i - 1].second and free % 2 == 1)
			result *= free + 1;
		result = result % MOD;
	}
	return result;
}
