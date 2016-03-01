#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<bool> valid(N * K + 1, true);
	vector<int> promised(K);
	for(int i = 0; i < K; i++) {
		cin >> promised[i];
		valid[promised[i]] = false;
	}
	
	int index = 1;
	for(int i = 0; i < K; i++) {
		cout << promised[i];
		int count = N - 1;
		while(count) {
			cout << " ";
			if(valid[index] == true) {
				cout << index;
				count--;
			}
			index++;
		}
		cout << endl;
	}
}
