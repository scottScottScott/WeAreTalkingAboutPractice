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

class Embassy {
public:
	int visaApplication(vector <int>, int, int);
};

int Embassy::visaApplication(vector <int> forms, int dayLength, int openTime) {
	int result = INT_MAX;
	for(int start = 0; start < dayLength; start++) {
		int totalTime = 0;
		int currTime = start;
		for(int F : forms) {
			totalTime += F;	
			currTime += F;
			currTime %= dayLength;
			if(currTime > openTime) {
				totalTime += dayLength - currTime;
				currTime = 0;
			}
		}
		result = min(totalTime, result);
	}	
	return result;
}
