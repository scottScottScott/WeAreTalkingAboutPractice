#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++)
		cin >> A[i];
	sort(A.begin(), A.end());
	
	int minWant = A[0];
	int maxWant = A[N - 1];
		
	int start = maxWant;
	int end = 2 * maxWant;

	int minRounds = end;
	while(start <= end) {
		int middle = start + (end - start) / 2;
		
		long long relax = 0;
		for(int i = 1; i < N; i++) {
			relax += middle - A[i];
		}
		if(relax >= minWant) {
			minRounds = middle;			
			end = middle - 1;
		}
		else 
			start = middle + 1;
	}

	cout << minRounds << endl;
}
