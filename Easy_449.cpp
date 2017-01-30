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
unordered_set<long> S;

void getPoints(int A, vector<pii> &P) {
	for(long x : S) {
		if(x <= A and S.count(A - x)) {
			long y = A - x;	
			int xx = sqrt(x);
			int yy = sqrt(y);
			P.emplace_back(xx, yy); 
			P.emplace_back(xx, -yy);
			P.emplace_back(-xx, yy);
			P.emplace_back(-xx, -yy);
		}
	}
}

double dist(pii A, pii B) {
	return sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2));
}

class MaxTriangle {
public:
	double calculateArea(int, int);
};

double MaxTriangle::calculateArea(int A, int B) {
	for(long i = 0; i * i <= 2e9; i++)
		S.insert(i * i);

	vector<pii> P_A, P_B;
	getPoints(A, P_A);
	getPoints(B, P_B);
	
	double a = sqrt(A);
	double b = sqrt(B);
	
	double result = -1;
	for(pii curr_A : P_A) {
		for(pii curr_B : P_B) {
			double c = dist(curr_A, curr_B);	
			if(c > a + b + 1e-6 or max(a, b) > min(a, b) + c + 1e-6) continue;
			double P = (a + b + c) / 2;
			double area = sqrt(P * (P - a) * (P - b) * (P - c));
			result = max(result, area);
		}
	}
	return result;
}
