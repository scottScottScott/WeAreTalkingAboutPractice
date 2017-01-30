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

const int MAX = 50 * 50;

void getProb(int c, int d, vector<double> &count) {
	count[0] = 1;
	for(int loop = 1; loop <= c; loop++) {
		for(int i = MAX - d; i >= 0; i--) {
			if(count[i] > 0) {
				for(int j = 1; j <= d; j++)
					count[i + j] += count[i] / d;
				count[i] = 0;
			}
		}
	}
}

class FixedDiceGameDiv1 {
public:
	double getExpectation(int, int, int, int);
};

double FixedDiceGameDiv1::getExpectation(int a, int b, int c, int d) {
	if(a * b <= c) return -1;

	vector<double> count_1(MAX + 1);			
	vector<double> count_2(MAX + 1);			
	getProb(c, d, count_1);
	getProb(a, b, count_2);
	vector<double> sum(MAX + 1);
	for(int i = 2; i <= MAX; i++)
		sum[i] = count_1[i - 1] + sum[i - 1];
	double num = 0;
	double denom = 0;
	for(int i = a * 1; i <= a * b; i++) {
		denom += sum[i] * count_2[i];
		num += i * sum[i] * count_2[i];
	}
	return num / denom;
}
