#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<double> info;
	double best = 0;
	for(int i = 0; i < n; i++) {
		double temp;
		cin >> temp;
		best = max(best, temp);
		if(temp < .5)
			info.push_back(temp);
	}
	sort(info.rbegin(), info.rend());
	double temp, total;
	temp = total = -1;
	for(int i = 0; i < info.size(); i++) {
		if(i == 0) {
			temp = info[0];
			total = 1 - info[0];
			continue;
		}
		temp = (1 - info[i]) * temp + total * info[i];
		total *= (1 - info[i]);
		best = max(best, temp);
	}
	printf("%.10f\n", best);
}
