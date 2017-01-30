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

class OlympicCandles {
public:
	int numberOfNights(vector <int>);
};

int OlympicCandles::numberOfNights(vector<int> candles) {
	int result = 0;
	while(true) {
		sort(candles.rbegin(), candles.rend());	
		if(result + 1 > candles.size()) break;
		int i = 0;
		for( ; i < result + 1; i++) {
			if(candles[i] > 0) candles[i]--;
			else break;
		}	
		if(i != result + 1) break;
		result++;
	}
	
	return result;
}
