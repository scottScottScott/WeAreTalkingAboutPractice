#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int V;
	cin >> V;
	vector<int> A(10);
	int minIndex = 0;
	for(int i = 1; i < A.size(); i++) {
		cin >> A[i];	
		if(minIndex == 0 or A[i] < A[minIndex])
			minIndex = i;
	}
		
	int numDigits = V / A[minIndex];
	if(numDigits == 0) {
		cout << -1 << endl;
		return 0;
	}

	string result;
	for(int i = 0; i < numDigits; i++) {
		result += ('0' + minIndex);
	}
	
	V -= A[minIndex] * numDigits;
	for(int i = 0; i < numDigits; i++) {
		for(int j = 9; j > minIndex; j--) {
			if( V - (A[j] - A[minIndex]) >= 0) {
				V -= A[j] - A[minIndex];
				result[i] = ('0' + j);
				break;
			}
		}
	}
	cout << result << endl;
}
