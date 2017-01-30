#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int n, k;
	cin >> n >> k;
	vector<pii> cL;
	vector<int> cR;
	for(int i = 0; i < n; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		cL.emplace_back(l, i);
		cR.push_back(r);
	}
	priority_queue<int, vector<int>, greater<int>> Q;
	int bIdx = k - 1;
	int bInvl = 0;
	sort(cL.begin(), cL.end());
	for(int i = 0; i < n; i++) {
		pii curr = cL[i];		
		int left = curr.first;
		int index = curr.second;
		if(i < k - 1) Q.push(cR[index]);	
		else {
			while(Q.size() >= k or (!Q.empty() and Q.top() < left))
				Q.pop();
			Q.push(cR[index]);
			if(Q.size() != k) continue;
			int invl = Q.top() - left + 1;
			if(invl > bInvl) {
				bInvl = invl;
				bIdx = i;
			}
		}
	}
	cout << bInvl << endl;
	if(bInvl == 0) {
		for(int i = 0; i < k; i++)	
			cout << i + 1 << (i + 1 == k ? "\n" : " ");
	}	
	else {
		int right = cL[bIdx].first + bInvl - 1;
		for(int i = bIdx; i >= 0 and k > 0; i--) {
			int rI = cL[i].second;		
			if(cR[rI] < right) continue;
			cout << rI + 1 << (--k != 0 ? " " : "\n");
		}
	}
}
