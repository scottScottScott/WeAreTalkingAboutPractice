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

double dist(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double bsearch(double V, double A, double D) {
	double lo = 0;
	double hi = 1000000;
	for(int i = 0; i < 200; i++) {
		double mid = lo + (hi - lo) / 2;
		double result = V * mid + 0.5 * A * mid * mid - D;
		
		if(result == 0) return mid;
		else if(result > 0) hi = mid;
		else lo = mid;
	}
	return hi;
}

class IncredibleMachine {
public:
	double gravitationalAcceleration(vector <int>, vector <int>, int);
};

double IncredibleMachine::gravitationalAcceleration(vector <int> x, vector <int> y, int T) {
	double lo = 0;	
	double hi = 1000000;
	for(int i = 0; i < 200; i++) {
		double mid = lo + (hi - lo) / 2;
			
		double t = 0;
		double V = 0;
		for(int i = 1; i < x.size(); i++) {
			double D = dist(x[i - 1], y[i - 1], x[i], y[i]);
			double A = mid * (y[i - 1] - y[i]) / D;
			double temp_t = bsearch(V, A, D);
			t += temp_t;
			V += A * temp_t;
		}
		
		if(t < T) hi = mid;
		else if(t > T) lo = mid;
		else return mid;
	}
	return hi;
}
