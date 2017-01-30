#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int M, N, K;	
	cin >> M >> N >> K;
	
	set<vector<int>> distinct;
	while(M--) {

		vector<int> temp(N);
		bool hasZero = false;
		
		for(int i = 0; i < N; i++) {
			cin >> temp[i];
			if(temp[i] == 0)
				hasZero = true;
		}

		if(hasZero)
			distinct.insert(temp);
	}

	int countZero = 0;

	for(const vector<int> &X : distinct) {
		for(int y : X) {
			if(y == 0)
				countZero++;
		}
	}

	cout << ( (countZero == N) and (distinct.size() <= K) ? "yes" : "no" ) << endl;
}
