#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Fenwick {
	public:
		Fenwick(int N) {
			size = N;
			storage.resize(N + 1);
		}

		void update(int idx, int val) {
			for(int i = idx; i <= size; i += -i & i)
				storage[i] += val;
		}

		int sum(int idx) {
			int result = 0;
			for(int i = idx; i > 0; i -= -i & i)
				result += storage[i];
			return result;
		}

	private:
		int size;
		vector<int> storage;
};

int main() {
	int N;	
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	
	unordered_map<int, int> forward, backward;
	vector<int> count_forward(N);
	vector<int> count_backward(N);
	for(int i = 0; i < N; i++) {
		forward[A[i]]++;
		count_forward[i] = forward[A[i]];
	}
	for(int i = N - 1; i >= 0; i--) {
		backward[A[i]]++;
		count_backward[i] = backward[A[i]];
	}

	Fenwick F(1e6);
	for(int i = 0; i < N; i++) {
		F.update(count_backward[i], 1);
	}

	long long result = 0;
	for(int i = 0; i < N; i++) {
		F.update(count_backward[i], -1);
		int val = count_forward[i];
		result += F.sum(val - 1);
	}
	cout << result << endl;

}
