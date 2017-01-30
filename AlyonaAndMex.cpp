#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	sort(A.begin(), A.end());

	int nxt_val = 1;
	for(int i = 0; i < N; i++) 
		if(A[i] >= nxt_val) nxt_val++;

	cout << nxt_val << endl;
}
