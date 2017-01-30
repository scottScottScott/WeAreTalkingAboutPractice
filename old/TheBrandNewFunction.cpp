#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
	int N;	
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++)
		cin >> A[i];
	
	vector<int> lastSet(20, -1);
	unordered_set<int> S;
	vector<int> temp;
	for(int i = 0; i < N; i++) {
		int val = 1;
		int minIndex = i;
		for(int b = 0; b <= 20; b++) {
			if(A[i] & val) {
				int last = lastSet[b];
				lastSet[b] = i;
				minIndex = min(minIndex, last + 1);
			}
			val <<= 1;
		}		
		// cout << "MIN: " << minIndex << endl;
		for(int z = minIndex; z < i; z++) {
			temp[z] |= A[i];
			S.insert(temp[z]);
		}

		S.insert(A[i]);
		temp.push_back(A[i]);
	}	

	cout << S.size() << endl;
}
