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

void make_substrings(string target, unordered_set<string> &T) {
	int n = target.size();
	for(int i = 0; i < n; i++) {
		string temp;
		for(int j = i; j < n; j++) {
			temp += target[j];
			T.insert(temp);
		}
	}
}

class ABBADiv1 {
public:
	string canObtain(string, string);
};

string ABBADiv1::canObtain(string initial, string target) {
	unordered_set<string> S, T;		
	
	make_substrings(target, T);	
	reverse(target.begin(), target.end());
	make_substrings(target, T);	
	reverse(target.begin(), target.end());

	deque<string> Q{initial};	
	S.insert(initial);
	while(!Q.empty()) {
		string curr = Q.front();
		Q.pop_front();
		if(curr == target)
			return "Possible";
		curr += 'A';
		if(!S.count(curr) and T.count(curr)) {
			S.insert(curr);	
			Q.push_back(curr);	
		}
		curr.pop_back();
		curr += 'B';
		reverse(curr.begin(), curr.end());	
		if(!S.count(curr) and T.count(curr)) {
			S.insert(curr);
			Q.push_back(curr);
		}
	}
	return "Impossible";
}
