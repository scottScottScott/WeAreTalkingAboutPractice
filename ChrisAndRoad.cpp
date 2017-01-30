#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<double, double> pdd;

int main() {
	int n;
	double w, v, u;
	cin >> n >> w >> v >> u;
	vector<pdd> P;
	for(int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		P.emplace_back(x, y);
	}
	bool valid = true;	
	for(pdd curr : P) {
		double time = curr.first / v;
		double y_val = u * time;
		if(y_val < curr.second) {
			valid = false;
			break;
		}
	}
	if(valid) {
		printf("%.10lf\n", w / u);
		return 0;
	}
	double result = 0;
	for(pdd curr : P) {
		double t_1 = curr.first / v;
		double t_2 = curr.second / u;
		result = max(result, max(t_1, t_2) + (w - curr.second) / u);	
	}
	printf("%.10lf\n", result);
}
