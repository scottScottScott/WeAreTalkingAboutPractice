#include <iostream>

using namespace std;

int main() {
	long long S, X;
	cin >> S >> X;

	long long A = S - X;
	if(A < 0 or A % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}
	long long B = A / 2;

	long long solution = 1;
	long long temp = 1;
	for(int i = 0; i <= 40; i++) {
		if(X & (temp << i)) {
			if(B & (temp << i)) {
				cout << 0 << endl;
				return 0;
			}
			solution *= 2;
		}
	}
	if(A == 0) solution -= 2;
	cout << solution << endl;
	return 0;
}
