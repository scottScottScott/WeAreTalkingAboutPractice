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

class BestView {
public:
	int numberOfBuildings(vector <int>);
};

int BestView::numberOfBuildings(vector <int> heights) {
	int result = 0;		
	int N = heights.size();
	for(int a = 0; a < N; a++) {
		int temp = 0;
		for(int b = 0; b < N; b++) {
			if(b == a) continue;
			int i, j;
			if(a < b) {
				i = a;
				j = b;
			}
			else {
				i = b;
				j = a;
			}
			bool valid = true;	
			for(int c = 0; c < N; c++) {
				if(c >= j or c <= i) continue;
				
				long first = (j - i) * (long) heights[i] + (long) (heights[j] - heights[i]) * (c - i);
				long second = (j - i) * (long) heights[c];
				if( first <= second)
					valid = false;
			}
			if(valid)
				temp++;
		}
		result = max(temp, result);
	}
	return result;
}
