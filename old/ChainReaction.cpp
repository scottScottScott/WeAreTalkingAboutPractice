#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii; 

int main() {
	int N;
	cin >> N;
	vector<pii> beacons(N);
	for(int i = 0; i < N; i++) {
		scanf("%d %d", &beacons[i].first, &beacons[i].second);
	}
	sort(beacons.begin(), beacons.end());
	map<int, int> M;
	for(int i = 0; i < beacons.size(); i++)
		M[beacons[i].first] = i;

	vector<int> memo(N);
	for(int i = 0; i < N; i++) {
		int previous = beacons[i].first - beacons[i].second;
		auto X = M.lower_bound(previous);
		if(X == M.end() or X == M.begin()) memo[i] = 1;
		else {
			X--;
			memo[i] = memo[X->second] + 1;	
		}
	}	

	cout << N - *max_element(memo.begin(), memo.end()) << endl;
}
