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

class NewArenaPassword {
public:
	int minChange(string, int);
};

int NewArenaPassword::minChange(string oldPassword, int K) {
	int changes = 0;
	int N = oldPassword.size();
	vector<bool> visited(N);
	
	for(int i = 0; i < K; i++) {
		if(visited[i]) continue;
		int minDiff = N;
		for(char x = 'a'; x <= 'z'; x++) {
			int diff = 0;
			int fst_i = i;
			int snd_i = N - K + fst_i;
			string copy = oldPassword;
			while(fst_i < K) {
				visited[fst_i] = true;
				if(copy[fst_i] != x) {
					diff++;
					copy[fst_i] = x;
				}
				if(copy[snd_i] != x) {
					diff++;
					copy[snd_i] = x;
				}
				
				if(snd_i < K and snd_i != fst_i) {
					fst_i = snd_i;
					snd_i = N - K + fst_i;
				}
				else break;
			}
			minDiff = min(minDiff, diff);
		}			
		changes += minDiff;	
	}
	
	return changes;
}
