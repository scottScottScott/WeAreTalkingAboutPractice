#include <vector>
#include <iostream>

using namespace std;

class Fenwick {
	public:
		Fenwick(int N) {
			storage.resize(N + 1);	
			this->N = N;	
		}
		long long sum(int i, int j) {
			if(j < i) return 0;
			return sum_helper(j) - sum_helper(i - 1);
		}
		long long sum_helper(int i) {
			long long result = 0;
			for(; i > 0 ; i -= (i & -i))
				result += storage[i];
			return result;
		}
		long update(int x, int i) {
			for( ; i <= N; i += (i & -i)) 
				storage[i] += x;
		}	
	private:
		vector<int> storage;	
		int N;
};

int main() {
	int N, K, A, B, Q;
	cin >> N >> K >> A >> B >> Q;

	Fenwick before(N);	
	Fenwick after(N);
	vector<int> order_before(N + 1);
	vector<int> order_after(N + 1);

	while(Q--) {
		int T;
		cin >> T;
		if(T == 1) {
			int D_i, A_i;
			cin >> D_i >> A_i;
			if(order_before[D_i] < B) {
				int temp = min(A_i, B - order_before[D_i]);
				order_before[D_i] += temp;
				before.update(temp, D_i);
			}
			if(order_after[D_i] < A) {
				int temp = min(A_i, A - order_after[D_i]);
				order_after[D_i] += temp;
				after.update(temp, D_i);
			}
		}
		else if(T == 2) {
			int P_i;
			cin >> P_i;
			long long sumBefore = before.sum(1, P_i - 1);	
			long long sumAfter = after.sum(P_i + K, N);
			cout << sumBefore + sumAfter << endl;
		}
	}
}
