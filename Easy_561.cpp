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

class ICPCBalloons {
public:
	int minRepaintings(vector <int>, string, vector <int>);
};

int ICPCBalloons::minRepaintings(vector <int> balloonCount, string balloonSize, vector <int> maxAccepted) {
	int N = maxAccepted.size();
	int retVal = -1;
	sort(maxAccepted.rbegin(), maxAccepted.rend());
	for(int i = 0; i < pow(2, N); i++) {
		deque<int> M, L;
		for(int i = 0; i < balloonCount.size(); i++) {
			if(balloonSize[i] == 'M') M.push_back(balloonCount[i]);
			else L.push_back(balloonCount[i]);
		}
		sort(M.rbegin(), M.rend());
		sort(L.rbegin(), L.rend());

		int change = 0;
		int total = 0;
		for(int z = 0; z < 2; z++) {
			for(int j = 0; j < N; j++) {
				if( ((i >> j) & 1) ^ z) {
					if(M.empty()) {
						if(total >= maxAccepted[j]) {
							total -= maxAccepted[j];
							change += maxAccepted[j];
						}	
						else total = -1000;
					}
					else if(maxAccepted[j] > M.front()) {
						change += maxAccepted[j] - M.front();
						total -= maxAccepted[j] - M.front();
						M.pop_front();	
					}
					else {
						total += M.front() - maxAccepted[j];
						M.pop_front();
					}
				}
			}
			while(!M.empty()) {
				total += M.front();
				M.pop_front();
			}
			if(total < 0) break;
			M = L;
			total = 0;
		}	
		if(total < 0) continue;
		if(retVal == -1 or change < retVal) retVal = change;
	}
	return retVal;
}
