#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int n;
	cin >> n;
	deque<pii> L(n + 1, pii{-1, -1});
	vector<int> B(n);
	vector<vector<int>> bL(n + 1);
	for(int i = 0; i < n; i++) {
		int p;
		scanf("%d %d", &p, &B[i]);
		L[p].first = i;
		L[p].second = p;
		bL[p].push_back(i);
	}
	sort(L.begin(), L.end());
	while(L.front().first == -1) L.pop_front();

	int q;
	cin >> q;
	while(q--) {
		int k;
		scanf("%d", &k);
		set<int> S;
		while(k--) {
			int l;
			scanf("%d", &l);
			S.insert(l);
		}
		bool found = false;
		for(int i = L.size() - 1; i >= 0; i--) {
			int p = L[i].second;	
			if(!S.count(p)) {
				int j = bL[p].size() - 1;
				int I = i - 1;
				while(I >= 0 and S.count(L[I].second)) I--;
				if(I >= 0) 
					j = upper_bound(bL[p].begin(), bL[p].end(), L[I].first) - bL[p].begin();
				else
					j = 0;
				j = bL[p][j];
				cout << p << " " << B[j] << endl;
				found = true;
				break;
			}
		}
		if(!found)
			cout << 0 << " " << 0 << endl;
	}
}
