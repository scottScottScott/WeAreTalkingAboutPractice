#include <iostream>

using namespace std;

int main() {
	int N, S;
	cin >> N >> S;
	int minTime = S;
	for(int i = 0; i < N; i++) {
		int F, T;
		cin >> F >> T;
		minTime = max(T + F, minTime);
	}

	cout << minTime << endl;
}
