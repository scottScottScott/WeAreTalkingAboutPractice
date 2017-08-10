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

class SquareScores {
public:
	double calcexpectation(vector <int>, string);
};

double SquareScores::calcexpectation(vector<int> p, string s) {
	while(p.size() < 26) p.push_back(0);
	double val = 0;
	int n = s.size();	
	for(int i = 0; i < n; i++) {
		vector<double> memo(26, 1);
		char curr = s[i];
		double prob = 1;
		for(int j = i; j < n; j++) {
			if(curr == '?' and s[j] != '?') {
				curr = s[j];
				prob = memo[s[j] - 'a'];
			}
			else if(s[j] == '?') {
				if(curr != '?')
					prob *= (double) p[curr - 'a'] / 100;	
			}
			else if(s[j] != curr)
				break;

			if(curr != '?')
				val += prob;
			else {
				for(int i = 0; i < 26; i++) {
					memo[i] *= (double) p[i] / 100;
					val += memo[i];
				}
			}
		}
	}
	return val;
}
