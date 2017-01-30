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

class PotentialArithmeticSequence {
public:
	int numberOfSubsequences(vector <int>);
};

int PotentialArithmeticSequence::numberOfSubsequences(vector <int> d) {
	int result = 0;
	for(int i = 0; i < d.size(); i++) {
		for(int j = i; j < d.size(); j++) {
			bool valid = true;
			vector<int> temp(d.begin() + i, d.begin() + j + 1);
			int val = 0;
			while(valid == true and temp.size() > 1) {
				vector<int> next;
				for(int i = 0; i < temp.size(); i++) {
					if(temp[i] == val) {
						if(i >= 2 and temp[i - 2] != val) valid = false;
						if(i >= 1 and temp[i - 1] == val) valid = false;
					}
					if(temp[i] != val) {
						if(i >= 1 and temp[i - 1] != val) valid = false;
						next.push_back(temp[i]);
					}
				}
				temp = move(next);
				val++;
			}
			if(valid) result++;
		}
	}
	return result;	
}
