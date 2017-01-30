#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long, long> pll;

int N;

class ShufflingMachine {
public:
	double stackDeck(vector <int>, int, vector <int>, int);
};

void make_shuffle(vector<int> &curr, vector<int> &shuffle) {
	vector<int> next_curr(N);
	for(int i = 0; i < N; i++)
		next_curr[shuffle[i]] = curr[i];
	curr = move(next_curr);
}

double ShufflingMachine::stackDeck(vector <int> shuffle, int maxShuffles, vector <int> cardsReceived, int K) {
	N = shuffle.size();
	vector<int> count(N);
	vector<int> curr(N);
	for(int i = 0; i < N; i++)
		curr[i] = i;
	for(int s = 1; s <= maxShuffles; s++) {
		make_shuffle(curr, shuffle);
		for(int i : cardsReceived)
			count[curr[i]]++;
	}
	sort(count.rbegin(), count.rend());
	return accumulate(count.begin(), count.begin() + K, 0.0) / maxShuffles;
}
