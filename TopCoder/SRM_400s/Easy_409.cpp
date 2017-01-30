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

class OrderedSuperString {
public:
	int getLength(vector <string>);
};

void append(string &W, string &S, int &lastSet) {
	int M = S.size();
	int N = W.size();
	
	for(int i = lastSet; i < M; i++) {
		int j = i;
		for( ; j < min(M, i + N); j++)
			if(S[j] != W[j - i]) break;
			
		if(j == i + N) {
			lastSet = i;
			return;
		}
		if(j == M) {
			lastSet = i;
			S += W.substr(M - i);	
			return; 
		}
	}
	
	lastSet = S.size();
	S += W;
}

int OrderedSuperString::getLength(vector<string> words) {
	string S;
	int lastSet = 0;
	for(string W : words)
		append(W, S, lastSet);
	return S.size();
}
