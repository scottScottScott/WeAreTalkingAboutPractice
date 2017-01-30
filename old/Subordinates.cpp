#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	s--;
	vector<int> A(n);	
	for(int i = 0; i < n; i++)
		cin >> A[i];
	int result = 0;
	if(A[s] != 0) {
		result++;
		A[s] = 0;
	}
	sort(A.begin(), A.end());
	int other = 0;
	for(int i = 1; i < n; i++) {
		if(A[i] > A[i - 1] + 1) {
			if(A[i] - A[i - 1] - 1 - other < n - i) {
				if(other >= A[i] - A[i - 1] - 1)
					other -= A[i] - A[i - 1] - 1;
				else {
					int diff = A[i] - A[i - 1] - 1 - other;
					other = 0;
					n -= diff;
				}
				result += A[i] - A[i - 1] - 1;
			}
			else {
				result += n - i;
				n = i;
			}
		}
		else if(A[i] == 0)
			other++;
	}
	cout << result + other << endl;
}
