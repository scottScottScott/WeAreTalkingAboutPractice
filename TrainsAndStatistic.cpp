#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

class Fenwick {
	public:
		Fenwick(int N) {
			this->N = N;
			storage.resize(N + 1);
		}
		pii getMax(int i) {
			pii result = storage[i];
			for( ; i > 0; i -= i & -i) {
				if(storage[i].first > result.first or 
					(storage[i].first == result.first and storage[i].second < result.second))
					result = storage[i];
			}
			return result;
		}
		void insert(int i, int val) {
			int start = i;
			for( ; i <= N; i += i & -i) {
				if(val >= storage[i].first) 
					storage[i] = make_pair(val, start);
			}
		}
	private:
		int N;
		vector<pii> storage;
};

int main() {
	int N;
	cin >> N;
	vector<int> A(N + 1);
	for(int i = 1; i < N; i++)
		scanf("%d", &A[i]);
	vector<long long> memo(N + 1);	
	Fenwick F(N);
	F.insert(N, N);
	for(int i = N - 1; i >= 1; i--) {
		pii best = F.getMax(A[i]);
		memo[i] += (best.second - i) + memo[best.second] + (N - A[i]);
		F.insert(i, A[i]);
	}

	cout << accumulate(memo.begin(), memo.end(), (long long) 0) << endl;
}
