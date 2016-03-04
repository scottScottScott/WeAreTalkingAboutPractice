#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string S;
	cin >> S;
	int N = S.size();

	vector<int> Z(N);
	Z[0] = N;
	int l = 0;
	int r = 0;
	for(int i = 1; i < N; i++) {
		if(i > r) {
			r = l = i;
			int start = 0;
			while(S[start] == S[r]) {
				start++;
				r++;
			}
			Z[i] = r - l;
		}	
		else {
			if(Z[i - l] < r - i) {
				Z[i] = Z[i - l];
			}
			else {
				l = i;
				while(S[r] == S[r - l]) {
					r++;
				}
				Z[i] = r - l;
			}
		}
	}

	int maxPossible = 0;
	for(int i = 1; i < N - 1; i++) {
		int temp = min(Z[i], N - i - 1);
		maxPossible = max(maxPossible, temp);
	}

	int maxSize = 0;
	for(int i = N - 1; i > 0; i--) {
		if(Z[i] == N - i) {
			if(Z[i] <= maxPossible) {
				maxSize = max(maxSize, Z[i]);
			}
		}
	}

	cout << (maxSize == 0 ? "Just a legend" : S.substr(0, maxSize)) << endl;
}
