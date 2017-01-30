#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, W;

int r_dp(int w, int n, vector<vector<int>> &memo, vector<vector<pii>> &options, int &bestIndex) {
	if(w < 0 or n < 0)
		return 0;

	if(memo[w][n] != -1)
		return memo[w][n];

	int &curr = memo[w][n];
	curr = 0;

	int k = options[w].size();
	for(int i = 0; i < k; i++) {
		int ticketsUsed = (options[w][i].second > n) ? n : options[w][i].second;
		int temp = options[w][i].first * ticketsUsed + r_dp(w - 1, n - ticketsUsed, memo, options, bestIndex);
		curr = max(curr, options[w][i].first * ticketsUsed + r_dp(w - 1, n - ticketsUsed, memo, options, bestIndex) );

		if(w == W and temp == curr)
			bestIndex = i;
	}

	return curr;
}

int main() {
	cin >> N >> W;

	vector<vector<int>> memo(W + 1, vector<int> (N + 1, -1));
	vector<vector<pii>> options(W + 1);
	int bestIndex = -1;

	for(int w = W; w >= 0; w--) {
		int K;
		cin >> K;
		
		vector<pii> temp(K);	
		for(int k = 0; k < K; k++) {
			cin >> temp[k].first;
		}
		for(int k = 0; k < K; k++) {
			cin >> temp[k].second;
		}
		sort(temp.begin(), temp.end());
		reverse(temp.begin(), temp.end());

		options[w] = move(temp);	
	} 

	cout << r_dp(W, N, memo, options, bestIndex) << endl;	
	cout << options[W][bestIndex].first << endl;
}
