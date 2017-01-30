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

const double PI = 3.1415926535;

double getAngle(int x, int y) {
	double R = sqrt(pow(x, 2) + pow(y, 2));
	return acos(y / R);	
}

class LaserShooting {
public:
	double numberOfHits(vector <int>, vector <int>, vector <int>);
};

double LaserShooting::numberOfHits(vector <int> x, vector <int> y1, vector <int> y2) {
	deque<pair<double, double>> intervals;
	for(int i = 0; i < x.size(); i++) {
		double angle_1 = getAngle(x[i], y1[i]);
		double angle_2 = getAngle(x[i], y2[i]);
		if(angle_1 < angle_2) {
			double temp = angle_1;
			angle_1 = angle_2;
			angle_2 = temp;
		}
		intervals.emplace_back(angle_1, 1);
		intervals.emplace_back(angle_2, 0);
	}
	sort(intervals.rbegin(), intervals.rend());
	
	double result = 0;
	int count = 1;
	double last = intervals.front().first;
	intervals.pop_front();
	for(auto x : intervals) {
		result += (last - x.first) * count;
		if(x.second == 1) count++;
		else count--;
		last = x.first;
	}
	return result / PI;
}
