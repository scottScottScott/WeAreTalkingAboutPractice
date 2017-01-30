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

class PalindromePermutations {
public:
	double palindromeProbability(string);
};

double PalindromePermutations::palindromeProbability(string word) {
	vector<int> count(26);	
	int N = word.size();
	for(char x : word)
		count[x - 'a']++;

	int numOdd = 0; 
	for(int i = 0; i < 26; i++) {
		if(count[i] % 2 == 1)
			numOdd++;
	}
	if(numOdd > 1) return 0;

	double result = 1;
	vector<deque<int>> info(2);
	for(int i = N; i > N / 2; i--)
		info[0].push_back(i);
	for(int x : count) {
		for(int i = x; i > x / 2; i--)
			info[1].push_back(i);
	}
	sort(info[0].rbegin(), info[0].rend());
	while(!info[0].empty() or !info[1].empty()) {
		int change = 0;
		if(info[1].empty()) {}
		else if(info[0].empty()) 
			change = 1;
		else if(info[0].front() > info[1].front()) {}
		else if(info[1].front() > info[0].front()) 
			change = 1;
		else {
			info[0].pop_front();
			info[1].pop_front();
			continue;
		}

		if(change == 1)
			result *= info[1].front();
		else
			result /= info[0].front();
		info[change].pop_front();
	}

	return result;
}
