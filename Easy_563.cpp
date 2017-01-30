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

class FoxAndHandle {
public:
	string lexSmallestName(string);
};

string FoxAndHandle::lexSmallestName(string S) {
	vector<int> total(26);
	vector<int> more;
	for(char x : S)
		total[x - 'a']++;
	more = total;

	string retStr;
	vector<int> count(26);		
	for(int i = 0; i < S.size(); i++) {
		int X = S[i] - 'a';

		char temp;
		if(count[X] < total[X] / 2) {
			while( !retStr.empty() and (temp = retStr.back()) > S[i] and count[temp - 'a'] - 1 + more[temp - 'a'] >= total[temp - 'a'] / 2) {
				count[temp - 'a']--;
				retStr.pop_back();	
			}
			count[X]++;
			retStr.push_back(X + 'a');
		}	
		more[X]--;
	}
	return retStr;
}
