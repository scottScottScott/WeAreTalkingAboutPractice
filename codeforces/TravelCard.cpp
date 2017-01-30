#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int n;	
	cin >> n;
	vector<int> T(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &T[i]);
	vector<int> memo(n, -1);
	for(int i = 0; i < T.size(); i++) {
		memo[i] = (i == 0 ? 0 : memo[i - 1]) + 20;
		for(pii curr : { pii{90, 50}, pii{1440, 120} }) {
			int last = T[i] + 1 - curr.first;
			int idx = lower_bound(T.begin(), T.end(), last) - T.begin() - 1;
			memo[i] = min(memo[i], (idx >= 0 ? memo[idx] : 0) + curr.second);
		}
		printf("%d\n", i == 0 ? memo[i] : memo[i] - memo[i - 1]);
	}
}
