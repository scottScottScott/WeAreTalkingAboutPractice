#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	unordered_set<int> S;
	for(int i = 0; i < N; i++) {
		int temp;	
		cin >> temp;
		S.insert(temp);
	}

	int currToy = 1;
	vector<int> toys;
	while(M > 0) {
		if(!S.count(currToy)) {
			M -= currToy;
			if(M >= 0) toys.push_back(currToy);
		}
		currToy++;
	}
	
	cout << toys.size() << endl;
	for(int i = 0; i < toys.size(); i++) {
		if(i != 0) cout << " ";
		cout << toys[i];
	}
	cout << endl;
}
