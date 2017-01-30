#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>

using namespace std;

class Fenwick {
	public:
		Fenwick(int size) {
			this->size = size;
			storage.resize(size + 1);
		}
		void insert(int i, int x) {
			for( ; i <= size; i += i & -i)
				storage[i] ^= x;
		}	
		int sum(int i) {
			int result = 0;
			for( ; i > 0; i -= i & -i)
				result ^= storage[i];
			return result;
		}
	private:
		vector<int> storage;
		int size;
};

int main() {
	int n;
	cin >> n;
	Fenwick F(n);
	map<int, int> M;
	vector<int> A(n + 1), next(n + 1), total(n + 1);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		total[i] = A[i] ^ total[i - 1];
		if(!M.count(A[i]))
			F.insert(i, A[i]);
		else
			next[M[A[i]]] = i;
		M[A[i]] = i;
	}
	int m;
	cin >> m;
	vector<int> result(m);
	deque<vector<int>> Q;
	for(int i = 0; i < m; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		Q.emplace_back(vector<int> {l, r, i});
	}
	sort(Q.begin(), Q.end());
	int last = 1;
	while(!Q.empty()) {
		vector<int> curr = Q.front();
		Q.pop_front();
		while(last < curr[0]) {
			F.insert(last, A[last]);
			if(next[last] != 0) 
				F.insert(next[last], A[last]);
			last++;
		}
		result[curr[2]] = F.sum(curr[1]) ^ total[curr[1]] ^ total[curr[0] - 1];
	}
	for(int x : result)	
		printf("%d\n", x);
}
