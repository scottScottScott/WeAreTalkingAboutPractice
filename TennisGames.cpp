#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int n;
	cin >> n;
	vector<pii> memo(n);
	for(int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if(temp == 1) {
			memo[i].first = (i == 0 ? 0 : memo[i - 1].first) + 1;
			memo[i].second = (i == 0 ? 0 : memo[i - 1].second);
		}
		else {
			memo[i].second = (i == 0 ? 0 : memo[i - 1].second) + 1;
			memo[i].first = (i == 0 ? 0 : memo[i - 1].first);
		}
	}
	vector<pii> result;
	for(int t = 1; t <= n; t++) {
		int start = 0;
		pii win;
		int winner = 0;
		while(start < n) {
			int lo = start;
			int hi = n - 1;
			int found = -1;
			while(lo <= hi) {
				int mid = lo + (hi - lo) / 2;
				pii curr;								
				curr.first = memo[mid].first - (start == 0 ? 0 : memo[start - 1].first);
				curr.second = memo[mid].second - (start == 0 ? 0 : memo[start - 1].second);
				if(curr.first >= t or curr.second >= t) {
					winner = curr.first >= curr.second ? 1 : 2;
					found = mid;
					hi = mid - 1;
				}
				else 
					lo = mid + 1;
			}
			if(found == -1) break;
			start = found + 1;
			if(winner == 1) win.first++;
			else win.second++;
		}
		if(start == n and win.first != win.second) {
			if(win.first > win.second and winner == 2) continue;
			if(win.first < win.second and winner == 1) continue;
			result.emplace_back(max(win.first, win.second), t);
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for(pii curr : result)
		printf("%d %d \n", curr.first, curr.second);
}
