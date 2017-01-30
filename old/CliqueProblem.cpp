#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

class Fenwick {
	public:
		Fenwick(int n) {
			this->n = n;
			storage.resize(n + 1);
		}
		void update(int i, int x) {
			i++;
			for( ; i <= n; i += i & -i)
				storage[i] = max(storage[i], x);
		}
		int query(int i) {
			i++;
			int result = 0;
			for( ; i > 0; i -= i & -i)
				result = max(result, storage[i]);	
			return result;
		}
	private:
		int n;
		vector<int> storage;
};

int main() {
	int n;
	cin >> n;
	vector<pii> A;
	vector<int> B;
	for(int i = 0; i < n; i++) {
		int x, w;
		cin >> x >> w;
		B.push_back(x + w);
		A.emplace_back(x, w);
	}

	int index = 0;
	map<int, int> M;
	sort(B.begin(), B.end());
	for(int x : B) {
		if(M.count(x))
			continue;
		M[x] = index++;
	}

	Fenwick F(n);
	sort(A.begin(), A.end());	
	for(pii curr : A) {
		int index;
		auto itr = lower_bound(B.begin(), B.end(), curr.first - curr.second);
		if(*itr != curr.first - curr.second) {
			if(itr == B.begin())
				index = -1;
			else {
				itr--;	
				index = M[*itr];
			}
		}
		else
			index = M[*itr];
		int result = 1 + (index == -1 ? 0 : F.query(index));
		int idx_2 = M[curr.first + curr.second];
		F.update(idx_2, result);
	}
	cout << F.query(n - 1) << endl;
}
