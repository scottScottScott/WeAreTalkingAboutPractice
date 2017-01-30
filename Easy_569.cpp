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

class TheDevice {
public:
	int minimumAdditional(vector <string>);
};

int TheDevice::minimumAdditional(vector <string> plates) {
	int retVal = 0;
	
	for(int i = 0; i < plates[0].size(); i++) {
		int zero_cnt = 0;
		int one_cnt = 0;
		for(int j = 0; j < plates.size(); j++) {	
			if(plates[j][i] == '1') one_cnt++;
			else zero_cnt++;
		}
		int temp = 0;
		if(one_cnt == 0) temp += 2;
		else if(one_cnt == 1) temp += 1;
		if(zero_cnt == 0) temp+=1;
			
		retVal = max(retVal, temp); 
	}	
	
	return retVal;
}
