#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N;
	cin >> N;
	vector<int> balls(N);
	for(int i = 0; i < N; i++) 
		cin >> balls[i];
	sort(balls.begin(), balls.end());

	priority_queue<pii, vector<pii>, less<pii>> Q;
	int count = 1;
	for(int i = 1; i <= N; i++) {
		if(i == N or balls[i] != balls[i - 1]) {
			Q.emplace(count, balls[i - 1]);
			count = 1;
		}
		else 
			count++;
	}

	vector<vector<int>> result;
	while(!Q.empty()) {
		vector<pii> curr_pairs;
		vector<int> curr_balls;
		for(int i = 0; i < 3; i++) {
			if(Q.empty()) break;
			curr_pairs.push_back(Q.top());
			curr_balls.push_back(curr_pairs[i].second);
			Q.pop();
		}
		if(curr_pairs.size() != 3) break;

		result.push_back(curr_balls);
		for(pii X : curr_pairs) {
			X.first--;	
			if(X.first)
				Q.push(X);
		}
	}

	cout << result.size() << endl;
	for(vector<int> &X : result) {
		sort(X.begin(), X.end());
		reverse(X.begin(), X.end());
		cout << X[0] << " " << X[1] << " " << X[2] << endl;
	}
}
