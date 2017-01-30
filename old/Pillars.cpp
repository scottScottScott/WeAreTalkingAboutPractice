#include <iostream>
#include <utility>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Fenwick {
	public:

	Fenwick(int n) {
		storage.resize(n + 1);
		this->n = n;
	}	
	void insert(int i, pii x) {
		for( ; i <= n; i += i & -i) {
			if(x.first > storage[i].first)
				storage[i] = x;
		}
	}	
	pii max(int i) {
		pii result = storage[i];
		for( ; i > 0; i -= i & -i) {
			if(storage[i].first > result.first)
				result = storage[i];
		}
		return result;
	}

	int n;
	vector<pii> storage;
};

int main() {
	int n, d;
	cin >> n >> d;
	vector<ll> A(n);
	vector<pii> memo(n);
	for(int i = 0; i < n; i++)
		scanf("%I64d", &A[i]);

	vector<ll> sH = A;
	sort(sH.begin(), sH.end());
	unordered_map<ll, int> M;
	for(int i = 0; i < n; i++) {
		if(!M.count(sH[i]))
			M[sH[i]] = i + 1;
	}

	Fenwick F(n), G(n);
	for(int i = 0; i < n; i++) {
		ll low = A[i] - d;
		ll high = A[i] + d;
		int low_idx = upper_bound(sH.begin(), sH.end(), low) - sH.begin();
		int hi_idx = n - (lower_bound(sH.begin(), sH.end(), high) - sH.begin());
		pii L = F.max(low_idx);
		pii H = G.max(hi_idx);
		L.first++, H.first++;
		memo[i] = H.first > L.first ? H : L;
		pii curr{max(L.first, H.first), i};
		F.insert(M[A[i]], curr);
		G.insert(n - M[A[i]] + 1, curr);
		
	}

	int iBest = 0;
	for(int i = 0; i < n; i++) {
		if(memo[i].first > memo[iBest].first)
			iBest = i;
	}

	int result = memo[iBest].first;
	cout << result << endl;
	vector<int> path{iBest};
	while(path.size() < result) {
		iBest = memo[iBest].second;
		path.push_back(iBest);
	}
	reverse(path.begin(), path.end());
	for(int i = 0; i < path.size(); i++)
		cout << path[i] + 1 << (i + 1 == path.size() ? "\n" : " ");
}
