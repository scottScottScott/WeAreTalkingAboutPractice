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

class TemplateMatching {
public:
	string bestMatch(string, string, string);
};

string TemplateMatching::bestMatch(string text, string prefix, string suffix) {
	int bestSum, bestPre;
	bestSum = bestPre = -1;
	string best;

	int P = prefix.size();
	int S = suffix.size();
	
	int N = text.size();	
	for(int s = 0; s < N; s++) {
		string curr;
		for(int e = s; e < N; e++) {
			curr += text[e];
			
			for(int a = 0; a <= min(e - s + 1, P); a++) {
				for(int b = 0; b <= min(e - s + 1, S); b++) {
					bool valid = true;
					for(int i = 0; i < a; i++) {
						if(curr[i] != prefix[P - a + i])
							valid = false;
					}
					for(int i = 0; i < b; i++) {
						if(curr[e - s - b + 1 + i] != suffix[i])
							valid = false;
					}
					if(!valid) continue;
					if(a + b > bestSum or (a + b == bestSum and a > bestPre) or (a + b == bestSum and a == bestPre and curr < best)) {
						bestSum = a + b;
						bestPre = a;
						best = curr;
					}
				}
			}
		}
	}
	
	return best;
}
