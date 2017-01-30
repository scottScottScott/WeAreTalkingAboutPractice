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

class EllysNumberGuessing {
public:
	int getNumber(vector <int>, vector <int>);
};

const int MIN = 1;	
const int MAX = 1e9;

bool valid(long long X) {
	 return (X >= MIN and X <= MAX) ? true : false;
}

int EllysNumberGuessing::getNumber(vector <int> guesses, vector <int> answers) {
	deque<long long> G;
	for(int i = 0; i < guesses.size(); i++) {
		long long currG = guesses[i];	
		long long currA = answers[i];
		if(i == 0) {
			if(valid(currG + currA)) G.push_back(currG + currA); 
			if(valid(currG - currA)) G.push_back(currG - currA);	
		}
		else {
			vector<long long> vec = {currG + currA, currG - currA};
			vector<bool> match(G.size());		
			for(int i = 0; i < G.size(); i++) {
				for(long long x : vec)
					if(x == G[i]) match[i] = true;	
			}
			for(int i = match.size() - 1; i >= 0; i--) {
				if(!match[i]) {
					if(i == 1) G.pop_back();
					else G.pop_front();
				}
			}
		}
		if(G.size() == 0) return -2;
	}
	if(G.size() == 2) return -1;	
	return G[0];
}
