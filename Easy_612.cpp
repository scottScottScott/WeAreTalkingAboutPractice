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
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long, long> pll;

class EmoticonsDiv1 {
public:
	int printSmiles(int);
};

const int MAX = 2000;

int memo[MAX + 1][MAX + 1];

int EmoticonsDiv1::printSmiles(int smiles) {
	memset(memo, -1, sizeof(memo));
	memo[1][0] = 0;	
	deque<pii> Q;
	Q.emplace_back(1, 0);
	while(!Q.empty()) {
		pii curr = Q.front();
		Q.pop_front();
		int chat = curr.first;
		int clip = curr.second;
		int val = memo[chat][clip];

		if(chat == smiles) return val;

		vector<pii> next_vec;
		next_vec.emplace_back(chat, chat);
		next_vec.emplace_back(chat + clip, clip);
		next_vec.emplace_back(chat - 1, clip);
		for(pii next : next_vec) {
			if(next.first > MAX or next.first < 0) continue; 
			if(memo[next.first][next.second] == -1) {
				Q.push_back(next);
				memo[next.first][next.second] = val + 1;
			}
		}
	}

	return -1;
}
