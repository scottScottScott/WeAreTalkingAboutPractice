#include <vector>
#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> B(N);
	vector<int> countStart(N);
	for(int i = 0; i < N; i++) {
		cin >> B[i];
		B[i]--;
		if(B[i] != -1) countStart[B[i]]++;
	}
	for(int i = 0; i < N; i++) {
		if(B[i] != -1 and countStart[B[i]] > 1)
			B[i] = -1;
	}

	vector<int> maxPath;
	for(int i = 0; i < N; i++) {
		if(A[i] == 1) {
			int curr = i;
			vector<int> currPath {i + 1};
			while(B[curr] != -1) {
				curr = B[curr];
				currPath.push_back(curr + 1);
			}
			if(currPath.size() > maxPath.size())
				maxPath = currPath;
		}
	}

	cout << maxPath.size() << endl;
	for(int i = maxPath.size() - 1; i >= 0; i--) {
		cout << maxPath[i];
		if(i == 0) cout << endl;
		else cout << " ";
	}
}
