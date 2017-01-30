#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N, K;
		cin >> N >> K;
		int result = 0;
		for(int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			result ^= temp;
		}	
		cout << (result != 0 ? "First" : "Second") << endl;
	}
}
