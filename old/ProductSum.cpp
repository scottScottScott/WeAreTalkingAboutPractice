#include <iostream> 
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Fenwick {
	public:
		Fenwick(vector<long long> &A) {
			N = A.size() - 1;
			storage.resize(N + 1);
			for(int i = 1; i <= N; i++) {
				update(i, A[i]);
			}
		}
		void update(int i, long long X) {
			for( ; i <= N; i += i & (-i))
				storage[i] += X;
		}
		long long sum(int i, int j) {
			return sum_helper(j) - sum_helper(i - 1);
		}		
		long long sum_helper(int i) {
			long long retVal = 0;
			for( ; i >= 1; i -= i & (-i))
				retVal += storage[i];
			return retVal;
		}
	private:
		int N;
		vector<long long> storage;
};

int main() {
	int N;
	cin >> N;
	vector<long long> A(N + 1);
	for(int i = 1; i <= N; i++)
		cin >> A[i];

	Fenwick F(A);

	vector<long long> B(N + 1);
	for(int i = 1; i <= N; i++)
		B[i] = B[i - 1] + A[i] * i;
	
	long long maxVal = B[N];
	int k = 1;	
	deque<int> higherVal;
	for(int j = 1; j <= N; j++) {
		if(A[j] > A[k]) {
			if(higherVal.empty() or A[j] > A[higherVal.back()]) 
				higherVal.push_back(j);
		}

		long long currVal = B[N] - F.sum(k, j) + A[k] * (j - k + 1);
			
		while(!higherVal.empty()) {
			int next_k = higherVal.front();	
			long long nextVal = B[N] - F.sum(next_k, j) + A[next_k] * (j - next_k + 1);
			if(nextVal >= currVal or j == N) {
				currVal = max(currVal, nextVal);	
				higherVal.pop_front();
				k = next_k;
			}
			else if(j != N)
				break;
		}

		maxVal = max(currVal, maxVal);
	}	

	k = N;	
	deque<int> lowerVal;
	for(int j = N; j >= 1; j--) {
		if(A[j] < A[k]) {
			if(lowerVal.empty() or A[j] < A[lowerVal.back()]) 
				lowerVal.push_back(j);
		}

		long long currVal = B[N] + F.sum(j, k) - A[k] * (k - j + 1);
			
		while(!lowerVal.empty()) {
			int next_k = lowerVal.front();	
			long long nextVal = B[N] + F.sum(j, next_k) - A[next_k] * (next_k - j + 1);
			if(nextVal >= currVal or j == 1) {
				currVal = max(currVal, nextVal);	
				lowerVal.pop_front();
				k = next_k;
			}
			else if(j != 1)
				break;
		}
		maxVal = max(currVal, maxVal);
	}

	cout << maxVal << endl;
}
