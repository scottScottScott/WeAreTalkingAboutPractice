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

class PouringWater {
public:
	int getMinBottles(int, int);
};

int PouringWater::getMinBottles(int N, int K) {
	vector<bool> count(30);
	int bottles = 0;
	for(int i = 30; i >= 0; i--) {
		int temp = 1 << i;
		if(N >= temp) {
			count[i] = 1;
			N -= temp;	
			bottles++;
		}
	}
	int result = 0;
	while(bottles > K) {
		for(int i = 0; i <= 30; i++) {
			if(count[i] == 1) {
				int temp = 1 << i;
				result += temp;
				for(int j = i; j <= 30; j++) {
					if(count[j] == 1) {
						count[j] = 0;
						bottles--;
					}
					else {
						count[j] = 1;
						bottles++;
						break;
					}
				}
				break;
			}
		}
	}
	return result;
}
