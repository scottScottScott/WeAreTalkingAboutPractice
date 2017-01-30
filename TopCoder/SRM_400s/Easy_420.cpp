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

class SolitaireSimulation {
public:
	int periodLength(vector <int>);
};

string convert(deque<int> &Q) {
	string result;
	for(int i = 0; i < Q.size(); i++) {
		string X = to_string(Q[i]);
		if(X.size() == 1) result += '0';
		result += X;
	}
	return result;
}

int SolitaireSimulation::periodLength(vector <int> heaps) {
	sort(heaps.begin(), heaps.end());
	unordered_map<string, int> M;
	deque<int> Q(heaps.begin(), heaps.end());
	string curr = convert(Q);
	int currStep = 0;
	while(!M.count(curr)) {
		M[curr] = currStep;
		int N = Q.size();
		for(int i = 0; i < N; i++)
			Q[i]--;
		while(!Q.empty() and Q.front() == 0)
			Q.pop_front();
		Q.push_back(N);
		sort(Q.begin(), Q.end());
		curr = convert(Q);
		currStep++;
	}
	return currStep - M[curr];	
}
