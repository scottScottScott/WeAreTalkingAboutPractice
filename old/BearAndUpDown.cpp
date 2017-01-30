#include <vector>
#include <iostream>
#include <utility>
#include <set>

using namespace std;

typedef pair<int, int> pii;

void swap(int i, int j, vector<int> &T) {
	int temp = T[i];
	T[i] = T[j];
	T[j] = temp;
}

bool valid(int j, vector<int> &badIndex, vector<int> &T) {
	for(int x : badIndex) {
		if(x % 2 == 0) {
			if(x != 0 and T[x] >= T[x - 1]) return false;
			if(x != T.size() - 1 and T[x] >= T[x + 1]) return false;
		}
		else {
			if(T[x] <= T[x - 1]) return false;
			if(x != T.size() - 1 and T[x] <= T[x + 1]) return false;
		}
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	vector<int> T(N);
	for(int i = 0; i < N; i++)
		cin >> T[i];

	set<int> badIndex_set;
	for(int i = 1; i < N; i += 2) {
		if(T[i] <= T[i - 1]) {
			badIndex_set.insert(i);
			badIndex_set.insert(i - 1);
		}
		if(i != N - 1 and T[i] <= T[i + 1]) {
			badIndex_set.insert(i);	
			badIndex_set.insert(i + 1);
		}
	}

	if(badIndex_set.size() > 6) {
		cout << "0" << endl;
		return 0;
	}

	vector<int> badIndex(badIndex_set.begin(), badIndex_set.end());
	vector<int> copy = badIndex;
	set<pii> S;
	for(int i : copy) {
		for(int j = 0; j < N; j++) {
			swap(i, j, T);
			badIndex.push_back(j);
			if(valid(j, badIndex, T))
				S.emplace(min(i, j), max(i, j));
			swap(i, j, T);
			badIndex.pop_back();
		}
	}
	cout << S.size() << endl;
}
