#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	int fixed = 0;
	vector<int> A(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		if(A[i] == i) fixed++;
	}
	
	bool two_swap = false;
	for(int i = 0; i < N; i++) {
		if(A[i] == i) continue;
		if(A[A[i]] == i) two_swap = true;
	}

	if(two_swap)
		fixed += 2;
	else if(fixed < N)
		fixed++;

	cout << fixed << endl;
}
