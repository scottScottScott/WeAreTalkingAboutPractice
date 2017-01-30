#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;
typedef pair<int, int> pii;

vector<pii> storeVec;

// range of [start, end)
void subsetSum(int start, int end, vector<pii>& storage, pii sum) {
	if(start == end) {
		storage.push_back(sum);
	}
	else {
		subsetSum(start+1, end, storage, sum);	

		sum.first += storeVec[start].first;
		sum.second += storeVec[start].second;
		subsetSum(start+1, end, storage, sum);
	}
}

int main() {
	int N;
	cin >> N;

	for(int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		storeVec.emplace_back(x, y);
	}

	pii zeroPair {0, 0};

	if(N == 1) {
		if(storeVec[0] == zeroPair) 
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}

	vector<pii> one;
	vector<pii> two;

	subsetSum(0, N / 2, one, make_pair(0, 0));	
	subsetSum(N / 2, N, two, make_pair(0, 0));

	map<pii, int> completion;
	long total = 0;
	for(auto x : one) {
		completion[x]++;
	}		

	for(auto x : two) {
		pii complement {x.first * -1, x.second * -1};
		if(completion.count(complement))
			total += completion[complement];
	}
	total--;

	cout << total << endl;
}
