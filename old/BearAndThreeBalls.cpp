#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A;
	vector<bool> seen(1000 + 1);
	for(int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if(!seen[temp]) {
			seen[temp] = true;
			A.push_back(temp);
		}
	}
	sort(A.begin(), A.end());
	for(int i = 0; i < (int) A.size() - 2; i++) {
		if(A[i] + 1 == A[i + 1] and A[i + 1] + 1 == A[i + 2]) {
			cout << "YES" << endl;
			return 0;
		}	
	}
	cout << "NO" << endl;
}
