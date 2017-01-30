#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int T, K, X, Y;

int main() {
	vector<vector<int>> memo(15, vector<int> (15));
	for(int total = 0; total <= 28; total++) {
		for(int x = 0; x <= total; x++) {
			int y = total - x;
			if(x >= 15 or y >= 15) continue;
			vector<int> grundy;
			vector<pii> next_vec { {-2, 1}, {-2, -1}, {1, -2}, {-1, -2} };
			for(pii next : next_vec) {
				int x_next = x + next.first;
				int y_next = y + next.second;
				if(x_next < 0 or x_next >= 15) continue;
				if(y_next < 0 or y_next >= 15) continue;
				
				grundy.push_back(memo[x_next][y_next]);
			}
			sort(grundy.begin(), grundy.end());
			if(grundy.size() == 0 or grundy[0] != 0) continue;
			for(int val = 1; val <= grundy.size(); val++) {
				if(val == grundy.size() or grundy[val] > grundy[val - 1] + 1) {
					memo[x][y] = grundy[val - 1] + 1;
					break;
				}
			}
		}
	}	

	cin >> T;
	while(T--) {
		cin >> K;
		int result = 0;
		for(int i = 0; i < K; i++) {
			cin >> X >> Y;
			result ^= memo[X - 1][Y - 1];
		}
		cout << (result != 0 ? "First" : "Second") << endl;
	}
}
