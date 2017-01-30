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

class RotatedClock {
public:
	string getEarliest(int, int);
};

string RotatedClock::getEarliest(int hourHand, int minuteHand) {
	int diff_1 = (hourHand - minuteHand + 360) % 360;
	for(int h = 0; h < 12; h++) {
		for(int m = 0; m < 60; m++) {
			int h_D = h * 30;
			int m_D = m * 6;
			if(m_D % 12 != 0) continue; 
			h_D += m_D / 12;

			int diff_2 = (h_D - m_D + 360) % 360;	
			if(diff_1 == diff_2 and m_D % 30 == minuteHand % 30) {
				string ret;
				if(h < 10) ret += "0";
				ret += to_string(h);
				ret += ":";
				if(m < 10) ret += "0";
				ret += to_string(m);
				return ret;
			}
		}
	}	
	return "";
}
