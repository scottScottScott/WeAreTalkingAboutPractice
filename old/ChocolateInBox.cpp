#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	int product = 0;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		product ^= A[i];
	}
	int count = 0;
	for(int i = 0; i < N; i++) {
		if(A[i] > (product ^ A[i]) ) {
			count++;
		}
	}		
	cout << count << endl;
}
