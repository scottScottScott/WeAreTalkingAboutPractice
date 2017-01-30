#include <iostream>

using namespace std;

int main() {
	int N;
	int M;
	cin >> N >> M;

	int A = N * 2;
	int B = M * 3;
	int overlap = min(A / 6, B / 6);

	int i = 0;
	while(i < overlap) {
		if(A + 2 <= B + 3) {
			A += 2;
			if(A <= B and A % 3 == 0)
				continue;
			i++;
		}
		else {
			B += 3;
			if(B <= A and B % 2 == 0)
				continue;
			i++;
		}
	}

	cout << max(A, B) << endl;
}
