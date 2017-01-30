#include <iostream>
#include <vector>

using namespace std;

int n, l, v1, v2, k;

double getTime(double dist) {
	double ftime = dist / v2;
	double btime = (dist - ftime * v1) / (v1 + v2);
	int trips = (n + k - 1) / k;
	double busTime = (ftime + btime) * trips - btime;	
	double result = max(busTime, ftime + (l - dist) / v1); 
	return result;
}

int main() {
	cin >> n >> l >> v1 >> v2 >> k;
	double lo = 0;
	double hi = l;
	if(v1 >= v2) {
		cout << getTime(0) << endl;
		return 0;
	}
	for(int i = 0; i < 100; i++) {
		double left = lo + (hi - lo) / 3;
		double right = hi - (hi - lo) / 3;
		double ltime = getTime(left);	
		double rtime = getTime(right);
		if(ltime <= rtime) hi = right;
		else lo = left;
	}
	printf("%0.10f\n", getTime(lo));
}
