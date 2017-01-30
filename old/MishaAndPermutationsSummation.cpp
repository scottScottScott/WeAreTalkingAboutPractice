#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Fenwick {
	public:
		Fenwick(int n) {
			storage.resize(n + 1);
			this->n = n;
			for(int i = 1; i <= n; i++) {
				insert(1, i);
			}
		}
		int sum(int i) {
			int result = 0;
			for( ; i > 0; i -= i & -i)
				result += storage[i];
			return result;
		}
		void insert(int val, int i) {
			for( ; i <= n; i += i & -i)
				storage[i] += val;
		}
		void reset() {
			storage.clear();
			storage.resize(n + 1);
			for(int i = 1; i <= n; i++)
				this->insert(1, i);
		}
	private:
		vector<int> storage;
		int n;
};

int main() {
	int n;
	cin >> n;
	vector<int> p(n), q(n);
	for(int i = 0; i < n; i++) 
		scanf("%d", &p[i]);	
	for(int i = 0; i < n; i++) 
		scanf("%d", &q[i]);	
	Fenwick F(n);	
	vector<int> P, Q;
	for(int temp : p) {
		int val = F.sum(temp + 1);
		F.insert(-1, temp + 1);
		P.push_back(val - 1);
	}
	F.reset();
	for(int temp : q) {
		int val = F.sum(temp + 1);
		F.insert(-1, temp + 1);
		Q.push_back(val - 1);
	}

	for(int i = n - 1; i >= 0; i--) {
		int mod = n - i;
		if(P[i] + Q[i] >= mod)
			if(i != 0) P[i - 1]++;
		P[i] = (P[i] + Q[i]) % mod;
	}

	F.reset();	
	for(int i = 0; i < n; i++) {
		int lo = P[i] + 1;
		int hi = n;
		int idx = hi;
		while(lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			int sum = F.sum(mid);	
			if(sum == P[i] + 1)
				idx = mid;
			if(sum < P[i] + 1)
				lo = mid + 1;	
			else
				hi = mid - 1;
		}
		F.insert(-1, idx);
		P[i] = idx - 1;
	}

	for(int i = 0; i < n; i++)
		cout << P[i] << (i + 1 != n ? " " : "\n");
}
