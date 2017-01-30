#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, T;
	cin >> n >> T;
	vector<double> Prob(n);
	vector<int> Time(n);
	for(int i = 0; i < n; i++) {
		int p, t;
		cin >> p >> t;
		Prob[i] = p * .01;
		Time[i] = t;
	}

	double result = 0;
	vector<vector<double>> memo(n + 1, vector<double>(T + 1));
	memo[0][0] = 1;
	for(int song = 1; song <= n; song++) {
		double tailProb = 0;
		double temp = Prob[song - 1];
		for(int second = 1; second < Time[song - 1]; second++) {
			tailProb += temp;
			temp *= (1 - Prob[song - 1]);
		}
		double sum = 0;
		for(int second = 1; second <= T; second++) {		
			sum *= (1 - Prob[song - 1]);
			sum += Prob[song - 1] * memo[song - 1][second - 1];
			double curr = 0;
			if(second - Time[song - 1] >= 0) {
				int last = second - Time[song - 1];
				sum -= memo[song - 1][last] * temp;
				curr += memo[song - 1][last] * (1 - tailProb);
			}
			memo[song][second] = curr + sum;
		}
		double val = accumulate(memo[song - 1].begin(), memo[song - 1].end(), 0.0) - accumulate(memo[song].begin(), memo[song].end(), 0.0);
		result += val * (song - 1);
	}
	double val = accumulate(memo[n].begin(), memo[n].end(), 0.0);
	result += val * n;
	printf("%.10f\n", result);
}
