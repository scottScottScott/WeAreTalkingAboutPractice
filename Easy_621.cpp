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

double getDist(long x, long y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}

class RadioRange {
public:
	double RadiusProbability(vector <int>, vector <int>, vector <int>, int);
};

double RadioRange::RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z) {
	vector<pair<double, double>> segments;	
	for(int i = 0; i < X.size(); i++) {
		double dist = getDist(X[i], Y[i]);
		segments.emplace_back(max(0.0, dist - R[i]), dist + R[i]);
	}

	double result = 0;
	double start = 0;
	sort(segments.begin(), segments.end());
	for(int i = 0; i < segments.size(); i++) {
		if(segments[i].first > start and start < Z) {
			result += min(segments[i].first - start, Z - start);
		}
		start = max(start, segments[i].second);
	}
	result += max(Z - start, 0.0);
	return result / Z;
}

