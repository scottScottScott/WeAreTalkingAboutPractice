#include <iostream>
#include <vector>

using namespace std;

bool memo[500 + 1][500 + 1];

int main() {
	int N, K;
	cin >> N >> K;
	memo[0][0] = 1;

	for(int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		for(int j = 500; j >= 0; j--) {
			for(int k = 500; k >= 0; k--) {
				if(k - temp >= 0 and memo[j][k - temp] != 0)
					memo[j][k] = 1;
				if(j - temp >= 0 and memo[j - temp][k] != 0)
					memo[j][k] = 1;
			}
		}
	}

	vector<int> result;
	for(int i = 0; i <= K; i++) {
		if(memo[i][K - i])
			result.push_back(i);
	}

	cout << result.size() << endl;
	for(int i = 0; i < result.size(); i++) {
		if(i != 0) cout << " ";
		cout << result[i];
	}
	cout << endl;
}
