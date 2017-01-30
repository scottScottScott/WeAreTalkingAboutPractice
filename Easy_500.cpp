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

class MafiaGame {
public:
	double probabilityToLose(int, vector <int>);
};

double MafiaGame::probabilityToLose(int N, vector <int> decisions) {
	deque<int> votes(N);
	for(int d : decisions) votes[d]++;
	int moreVotes = N - decisions.size();
	int maxSame = 0;	

	while(true) {
		while(moreVotes > 0) {
			sort(votes.begin(), votes.end());
			votes[0]++;
			moreVotes--;
		}
		sort(votes.begin(), votes.end());
		int tempSame = 1;
		for(int i = votes.size() - 1; i > 0; i--) {
			if(votes[i] == votes[i - 1]) tempSame++;
			else break;
		}
		maxSame = max(tempSame, maxSame);

		if(tempSame == 1) return 1.0 / maxSame;	
		if(tempSame == votes.size()) return 0;
	
		while(votes.size() > tempSame) {
			moreVotes += votes[0];
			votes.pop_front();		
		}
	}
}
