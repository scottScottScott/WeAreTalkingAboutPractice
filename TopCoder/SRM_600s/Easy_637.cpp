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

class GreaterGame {
public:
	double calc(vector <int>, vector <int>);
};

double GreaterGame::calc(vector <int> hand, vector <int> sothe) {
	int N = hand.size();		
	vector<bool> seen(2 * N + 1);
	for(int x : hand) seen[x] = 1;
	for(int x : sothe)
		if(x != -1) seen[x] = 1;
	vector<int> A, B;
	for(int i = 1; i < seen.size(); i++)
		if(seen[i] == 0) B.push_back(i);
	int start = 0;	
	sort(hand.begin(), hand.end());
	sort(sothe.rbegin(), sothe.rend());
	vector<bool> used(hand.size());
	for(int x : sothe) {
		if(x == -1) break;
		int i = 0;
		for( ; i < hand.size(); i++) {
			if(used[i]) continue;
			if(hand[i] > x) {
				used[i] = true;
				start++;
				break;
			}
		}
		if(i == hand.size()) {
			for(int j = 0; j < hand.size(); j++) {
				if(used[j]) continue;
				used[j] = true;
				break;
			}
		}
	}
	for(int i = 0; i < used.size(); i++)
		if(used[i] == 0) A.push_back(hand[i]);
	double num = 0;
	double denom = A.size();
	for(int i = 0; i < A.size(); i++) {
		for(int j = 0; j < B.size(); j++) {
			if(A[i] > B[j]) num++;
		}
	}
	return start + (denom == 0 ? 0 : num / denom);
}
