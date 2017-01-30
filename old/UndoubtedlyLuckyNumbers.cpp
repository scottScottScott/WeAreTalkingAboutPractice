#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

int N;	
set<string> S;

void build(string &currNum, int i, int j) {
	currNum += (i + '0');
	int n = currNum.size();
	if(n <= 9) {
		if(currNum[0] != '0' and stoi(currNum) <= N)
			S.insert(currNum);
		build(currNum, i, j);

		currNum[n - 1] = (j + '0');
		if(currNum[0] != '0' and stoi(currNum) <= N)
			S.insert(currNum);
		build(currNum, i, j);
	}
	currNum.pop_back();
}

int main() {
	cin >> N;

	string currNum;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			build(currNum, i, j);
		}
	}
	if(N == 1e9) S.insert("billion");
	cout << S.size() << endl;
}
