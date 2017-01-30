#include <iostream>
#include <climits>

using namespace std;

long choose(int N, int K) {
	if(K == 0) return 1;
	return N * choose(N - 1, K - 1) / K;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		long N, M;
		cin >> N >> M;

		cout << choose(N, M - 1) << endl;
	}
}
