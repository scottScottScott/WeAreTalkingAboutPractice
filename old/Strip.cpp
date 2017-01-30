#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
vector<pii> minV, maxV;
int n, s, l;

int find(int i, vector<pii>& temp) {
	int low = 0;	
	int high = temp.size() - 1;
	int result = temp.front().first;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(temp[mid].second >= i) {
			result = temp[mid].first;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return result;
}

int find_index(int i) {
	int low = 0;	
	int high = i;
	int result = i;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		int low_val = find(mid, minV);
		int high_val = find(mid, maxV);
		if(high_val - low_val <= s) {
			result = mid;
			high = mid - 1;	
		}
		else
			low = mid + 1;
	}
	return result;
}

int main() {
	cin >> n >> s >> l;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	vector<int> memo(n, INT_MAX);
	deque<pii> Q;
	for(int i = 0; i < n; i++) {
		while(!minV.empty() and a[i] <= minV.back().first)
			minV.pop_back();
		minV.emplace_back(a[i], i);
		while(!maxV.empty() and a[i] >= maxV.back().first)
			maxV.pop_back();
		maxV.emplace_back(a[i], i);
		if(i < l - 1) 
			continue;
		int best_i = find_index(i);
		// cout << i << " " << best_i << endl;
		if(best_i > i - l + 1) 
			continue;
		while(!Q.empty() and Q.front().second < best_i - 1)
			Q.pop_front();
		if(best_i == 0)
			memo[i] = 1;
		else {
			int val = Q.empty() ? INT_MAX : Q.front().first;
			if(val != INT_MAX and Q.front().second <= i - l) memo[i] = val + 1;
		}
		while(!Q.empty() and memo[i] < Q.back().first)
			Q.pop_back();
		Q.emplace_back(memo[i], i);
		// cout << i << " MEMO: " << memo[i] << endl;
	}
	cout << (memo[n - 1] == INT_MAX ? -1 : memo[n - 1]) << endl;
}
