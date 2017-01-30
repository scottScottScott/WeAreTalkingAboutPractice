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

class EquilibriumPoints {
public:
	vector <double> getPoints(vector <int>, vector <int>);
};

vector <double> EquilibriumPoints::getPoints(vector <int> x, vector <int> m) {
	int N = x.size();	
	vector<double> result;
	for(int i = 0; i + 1 < N; i++) {
		double lo = x[i] + 1e-9;
		double hi = x[i + 1] - 1e-9;
		for(int loop = 0; loop < 200; loop++) {
			double mid = lo + (hi - lo) / 2;
			
			double val = 0;
			for(int j = 0; j < N; j++) {
				if(j <= i)
					val += m[j] / pow(mid - x[j], 2);
				else 
					val -= m[j] / pow(mid - x[j], 2);
			}

			if(val > 0)
				lo = mid;
			else
				hi = mid;
		}
		result.push_back(lo);
	}
	return result;
}
