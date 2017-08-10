#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	string temp;
	getline(cin, temp);
	vector<string> W(n);
	for(int i = 0; i < n; i++)
		getline(cin, W[i]);
	for(int i = n - 2; i >= 0; i--) {
		for(int j = 0; j < W[i].size(); j++) {
			if(j == W[i + 1].size() or W[i][j] > W[i + 1][j]) {
				while(W[i].size() > j)
					W[i].pop_back();
			}
			else if(W[i][j] < W[i + 1][j])
				break;
		}
	}
	for(int i = 0; i < n; i++)
		cout << W[i] << endl;
}
