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

void swap(string &curr, int a, int b) {
	int temp = curr[a];
	curr[a] = curr[b];
	curr[b] = temp;
}

class TheSwap {
public:
	int findMax(int, int);
};

int TheSwap::findMax(int n, int k) {
	string S = to_string(n);	
	int N = S.size();
	if(N == 1 or (N == 2 and S[1] == '0')) return -1;

	vector<unordered_set<string>> M(2);

	deque<string> Q {S};
	int curr_k = 0;
	while(!Q.empty()) {
		int Q_size = Q.size();
		curr_k++;
		for(int i = 0; i < Q_size; i++) {
			string curr = Q.front();
			Q.pop_front();
			for(int j = 0; j < N; j++) {
				for(int k = j + 1; k < N; k++) {
					swap(curr, j, k);
					if(M[curr_k % 2].count(curr) == 0) {
						M[curr_k %2].insert(curr);
						Q.push_back(curr);
					}
					swap(curr, j, k);
				}
			}
		}
		if(curr_k == K) break;
	}

	string result = S;
	for(string x : M[k % 2]) {
		if(x > result) result = x;
	}
	return result;
}



