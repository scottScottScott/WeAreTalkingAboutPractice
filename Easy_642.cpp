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

class WaitingForBus {
public:
	double whenWillBusArrive(vector <int>, vector <int>, int);
};

double WaitingForBus::whenWillBusArrive(vector <int> time, vector <int> prob, int s) {
	vector<double> memo(s + 1e5);
	memo[0] = 1;
	for(int i = 0; i < s; i++) {
		for(int j = 0; j < time.size(); j++) {
			double newP = (prob[j] * memo[i]) / 100;
			memo[i + time[j]] += newP;
		}
	}
	double result = 0;
	for(int i = s; i < memo.size(); i++)
		result += memo[i] * (i - s);	
	return result;
}
