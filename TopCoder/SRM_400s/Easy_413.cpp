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

class ArithmeticProgression {
public:
	double minCommonDifference(int, vector <int>);
};

double ArithmeticProgression::minCommonDifference(int a0, vector <int> seq) {	
	if(seq.size() == 0) return 0;
	int jump = seq[0] - a0;
	if(jump < 0) return -1;
	int lo = 0;	
	int hi = 1e9;
	bool found = false;
	while(lo < hi) {
		double mid = lo + (hi - lo) / 2;
		double curr = jump + mid * 1e-9;
		int valid = 0;
		double start = a0;
		for(int i = 0; i < seq.size(); i++) {
			if(start + curr >= seq[i] and start + curr < seq[i] + 1)
				start += curr;
			else if(start + curr < seq[i]) {
				valid = 1;
				break;
			}
			else if(start + curr >= seq[i] + 1) {
				valid = 2;
				break;
			}
		}

		if(valid == 0 or valid == 2) hi = mid;
		else lo = mid + 1;
		if(valid == 0) found = true;
	}

	return !found ? -1 : jump + lo * 1e-9;
}
