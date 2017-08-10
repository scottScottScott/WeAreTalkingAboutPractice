#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

vector<pii> B;

class Fenwick {
	public:
		Fenwick(int n) {
			size = n;
			storage.resize(n + 1);
		}
		ll getMax(int i) {
			i++;
			ll result = storage[i];
			for( ; i > 0; i -= i & -i)
				result = max(result, storage[i]);
			return result;
		}
		void insert(int i, ll val) {
			i++;	
			storage[i] = val;
			for( ; i <= size; i += i & -i)
				storage[i] = max(storage[i], val);
		}
	private:
		int size;
		vector<ll> storage;
};

bool cmp(pii pA, pii pB) {
	if(pA.first > pB.first)
		return 1;
	else if(pA.first < pB.first)
		return 0;
	else
		return B[pA.second] > B[pB.second];
}

int main() {
	int n;
	cin >> n;
	vector<pii> A(n);
	B.resize(n);
	vector<int> H(n);
	for(int i = 0; i < n; i++) {
		int a, b, h;
		scanf("%d %d %d", &(B[i].first), &(A[i].first), &H[i]);
		A[i].second = i;
		B[i].second = i;
	}
	sort(A.begin(), A.end(), cmp);
	sort(B.begin(), B.end());
	vector<ll> memo(n);		
	map<int, int> M;
	Fenwick F(n);
	for(int i = 0; i < n; i++)
		M[B[i].second] = i;	
	ll result = 0;
	for(int i = 0; i < n; i++) {
		pii curr = A[i];
		int index = lower_bound(B.begin(), B.end(), make_pair(curr.first, 0)) - B.begin() - 1;
		ll maxVal = F.getMax(index);
		maxVal += H[curr.second];
		result = max(result, maxVal);
		F.insert(M[curr.second], maxVal);
	}
	cout << result << endl;
}
