#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> shortcuts(N);
	for(int i = 0; i < N; i++) {
		cin >> shortcuts[i];
		shortcuts[i]--;
	}
	
	vector<int> memo(N, INT_MAX);
	memo[0] = 0;
	deque<int> Q{0};
	while(!Q.empty()) {
		int curr = Q.front();
		Q.pop_front();
		if(curr + 1 < N and memo[curr] + 1 < memo[curr + 1]) {
			Q.push_back(curr + 1);
			memo[curr + 1] = memo[curr] + 1;
		}
		if(memo[curr] + 1 < memo[shortcuts[curr]]) {
			Q.push_back(shortcuts[curr]);
			memo[shortcuts[curr]] = memo[curr] + 1;
		}
		if(curr - 1 >= 0 and memo[curr] + 1 < memo[curr - 1]) {
			Q.push_back(curr - 1);
			memo[curr - 1] = memo[curr] + 1;
		}
	}
	
	for(int i = 0; i < N; i++) {
		if(i != 0) cout << " ";
		cout << memo[i];
	}
	cout << endl;
}
