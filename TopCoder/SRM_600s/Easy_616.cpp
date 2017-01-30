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

class WakingUp {
public:
	int maxSleepiness(vector <int>, vector <int>, vector <int>, int);
};

int getGCD(int a, int b) {
	if(a % b == 0) return b;
	return getGCD(b, a % b);
}

int getLCM(int a, int b) {
	return a * (b / getGCD(a, b));
}

int WakingUp::maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D) {
	int P = 1;
	int N = period.size();
	for(int i = 0; i < N; i++)
		P = getLCM(P, period[i]);	
	vector<int> simulate(P + 1);
	for(int i = 0; i <= P; i++) {
		simulate[i] = (i != 0 ? simulate[i - 1] : 0) + D;
		for(int j = 0; j < N; j++) {
			if(start[j] - 1 == i % period[j])
				simulate[i] -= volume[j];
		}
	}
	int result = *min_element(simulate.begin(), simulate.end());
	if(result > 0) return 0;
	return (simulate[P] < simulate[0] ? -1 : -result);

}
