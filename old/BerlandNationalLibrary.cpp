#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	vector<bool> B(N);
	for(int i = 0; i < N; i++) {
		char X;
		cin >> X >> A[i];
		if(X == '+') B[i] = 1;
	}

	set<int> S;
	int currVal = 0;
	for(int i = 0; i < N; i++) {
		if(B[i] == 1)
			S.insert(A[i]);
		else {
			if(S.count(A[i])) S.erase(A[i]);
			else currVal++;
		}
	}
	
	int result = currVal;
	for(int i = 0; i < N; i++) {
		if(B[i] == 1) currVal++;
		else if(B[i] == 0) currVal--;
		result = max(result, currVal);
	}
	cout << result << endl;
}
