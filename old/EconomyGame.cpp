#include <iostream>

using namespace std;

const int A = 1234567;
const int B = 123456;
const int C = 1234;

int main() {
	int N;
	cin >> N;
	bool possible = false;
	while(N >= 0) {
		int temp = N;
		N -= A;
		if(temp % 2 == 1) continue;
		if(temp % B == 0 or temp % C == 0)
			possible = true;
		while(temp >= 0) {
			temp -= B;
			if(temp >= 0 and temp % C == 0)
				possible = true;
		}
	}	
	cout << (possible ? "YES" : "NO") << endl;
}
