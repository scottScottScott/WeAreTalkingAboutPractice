#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int MAX = 100;
double memo[MAX + 1][MAX + 1][MAX + 1];

int main() {
	int R, S, P;
	cin >> R >> S >> P;
	memo[R][S][P] = 1;
	int total = R + S + P;
	vector<double> prob(3);
	for(int t = total; t >= 1; t--) {
		for(int r = 0; r <= t; r++) {
			for(int s = 0; s + r <= t; s++) {
				int p = t - r - s;
				if(r > 100 or s > 100 or p > 100) continue;
				double denom = r * s + s * p + r * p;
				vector<int> curr {r, s, p};
				double currVal = memo[r][s][p];
				bool isEnd = false;
				for(int i = 0; i < 3; i++) {
					if(curr[i] == t) {
						prob[i] += currVal;
						isEnd = true;
					}
				}
				if(isEnd) continue;
					
				for(int i = 0; i < 3; i++) {
					if(curr[i] == 0) {
						if(i == 0) prob[1] += currVal;
						if(i == 1) prob[2] += currVal;
						if(i == 2) prob[0] += currVal;
						isEnd = true;
					}
				}
				if(isEnd) continue;

				memo[r - 1][s][p] += r * p * currVal / denom;
				memo[r][s - 1][p] += r * s * currVal / denom;
				memo[r][s][p - 1] += s * p * currVal / denom;
			}
		}
	} 
	cout << setprecision(10) << prob[0] << " " << prob[1] << " " << prob[2] << endl;
}
