#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> balls;
	balls.resize(N);
	for(int i = 0; i < N; i++) {
		cin >> balls[i];
	}
	sort(balls.begin(), balls.end());

	vector<long long> memo(5000);
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			int diff = balls[j] - balls[i];
		//	cout << diff << endl;
			memo[diff]++;
		}
	}

	vector<long long> diff_memo(5000);
	for(int i = 0; i < 5000; i++) {
		for(int j = 0; j < 5000; j++) {
			if(i + j < 5000)
				diff_memo[i + j] += memo[i] * memo[j];
		}
	}

	for(int i = 1; i < 5000; i++) {
		diff_memo[i] += diff_memo[i - 1];
	}

	long long count = 0;
	for(int andrew = 0; andrew < N; andrew++) {
		for(int jerry = andrew + 1; jerry < N; jerry++) {
			int diff = balls[jerry] - balls[andrew];
			count += ( diff == 0 ? 0 : diff_memo[diff - 1] );			
			// cout << balls[jerry] << " " << balls[andrew] << " " << diff_memo[diff - 1] << endl;
		}
	}
	
//	cout << count << endl;
	long long totalProb = N * (N - 1) / 2.0;
	totalProb *= totalProb * totalProb;
//	cout << totalProb << endl;
	cout << setprecision(17) << (double) count / totalProb << endl;
}
