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

class Decipherability {
public:
	string check(string, int);
};

string Decipherability::check(string s, int K) {
	set<string> S;
	int n = s.size();
	if(K == n) return "Certain";
	for(int i = 1; i <= K; i++) {
		for(int j = 0; j + i <= n; j++) {
			string temp;
			temp += s.substr(0, j);
			temp += s.substr(j + i);
			if(S.count(temp)) 
				return "Uncertain";
			S.insert(temp);
		}
	}
	return "Certain";
}
