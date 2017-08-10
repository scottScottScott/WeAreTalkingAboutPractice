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

class ApplesAndOrangesEasy {
public:
	int maximumApples(int, int, vector <int>);
};

int ApplesAndOrangesEasy::maximumApples(int N, int K, vector <int> info) {
	vector<int> memo(N);	
	vector<bool> seen(N);
	for(int i = 0; i < info.size(); i++) {
		int curr = info[i] - 1;
		seen[curr] = 1;
	}
	for(int i = 0; i < N; i++) {
		if(seen[i] != 1) continue;
		for(int j = i; j < min(N, i + K); j++)
			memo[j]++;
	}
	int result = info.size();
	for(int i = 0; i < N; i++) {
		if(seen[i]) continue;
		bool valid = true;
		for(int j = i; j < min(N, i + K); j++) {
			if(memo[j] + 1 > K / 2)
				valid = false;
		}
		if(!valid) continue;	
		result++;
		for(int j = i; j < min(N, i + K); j++)
			memo[j]++;	
	}
	return result;
}
