#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

double getVal(double x, vector<int> &a) {
	vector<double> temp(a.size());
	for(int i = 0; i < a.size(); i++)
		temp[i] = a[i] - x;

	double result = 0;
	for(int loop = 0; loop < 2; loop++) {
		double currVal = 0;
		for(int i = 0; i < temp.size(); i++) {
			if(currVal + temp[i] < 0)
				currVal = 0;
			else currVal += temp[i];
			result = max(result, currVal);
			temp[i] = -temp[i];
		}
	}

	return result;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	double result = INT_MAX;	
	double lo = -10000;
	double hi = 10000;
	for(int loop = 0; loop < 100; loop++) {
		double left = lo + (hi - lo) / 3;
		double right = hi - (hi - lo) / 3;
		double lval = getVal(left, a);
		double rval = getVal(right, a);
		if(lval <= rval) hi = right;
		else lo = left;
		result = min(result, min(lval, rval));
	}
	printf("%.10f\n", result);
}
