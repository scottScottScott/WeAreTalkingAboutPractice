#include <iostream>

using namespace std;

int getGCD(int A, int B) {
	if(B != 0)
		return getGCD(B, A % B);
	return A;
}

int main() {
	int N, K;
	cin >> N >> K;
	int gcd;
	for(int i = 0; i < N; i++) {
		if(i == 0)	
			cin >> gcd;
		else {
			int X;
			cin >> X;
			gcd = getGCD(gcd, X);
		}
	}

	int result = 0;
	for(int d = 1; d * d <= gcd; d++) {
		if(gcd % d == 0) {
			int other = gcd / d;
			for(int X : {d, other}) {
                if(X == 1) continue;
				int curr = (K / X) * X;
				result = max(result, curr);	
			}
		}
	}
	cout << result << endl;
}
