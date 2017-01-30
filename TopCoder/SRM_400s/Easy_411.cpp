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

class SentenceDecomposition {
public:
	int decompose(string, vector <string>);
};

int SentenceDecomposition::decompose(string sentence, vector <string> validWords) {
	int N = sentence.size();
	vector<int> memo(N, INT_MAX);
	for(int i = 0; i < N; i++) {
		for(string &temp : validWords) {
			int M = temp.size();
			int start = i - M + 1;
			if(start < 0 or (start != 0 and memo[start - 1] == INT_MAX)) continue;
			int change = 0;
			vector<int> count(26);
			for(int j = start; j <= i; j++) {
				if(sentence[j] != temp[j - start]) {
					change++;
					count[sentence[j] - 'a']++;
					count[temp[j - start] - 'a']--;
				}
			}
			bool valid = true;
			for(int x : count) {
				if(x != 0)
					valid = false;
			}
			if(valid)
				memo[i] = min(memo[i], (start == 0 ? 0 : memo[start - 1]) + change);
		}
	}
	return memo[N - 1] == INT_MAX ? -1 : memo[N - 1];
}
