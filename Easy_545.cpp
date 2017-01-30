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

class StrIIRec {
public:
	string recovstr(int, int, string);
};

string StrIIRec::recovstr(int n, int minInv, string minStr) {
	vector<bool> used(n);	
	for(char x : minStr)
		used[x - 'a'] = 1;
	for(int i = 0; i < n; i++) {
		if(!used[i]) {
			minStr += i + 'a';
			used[i] = 1;
		}
	}
	
	vector<int> val(n);	
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(minStr[i] > minStr[j])
				val[i]++;
		}
	}

	int count = accumulate(val.begin(), val.end(), 0);
	used[minStr.back() - 'a'] = 0;
	minStr.pop_back();
	int index = n - 1;
	while(count < minInv) {
		index--;
		count -= val[index];
		count += (n - 1) - index;
		used[minStr.back() - 'a'] = 0;
		minStr.pop_back();
	}
	count = accumulate(val.begin(), val.begin() + index, 0);
	for(int i = index; i < n; i++) {
		int x = (n - 1) - (i + 1);
		int end = x * (x + 1) / 2;
		int need = max(1, (minInv - count - end) + 1);
		int a = 0;	
		for(int j = 0; j < n; j++) {
			if(used[j] == 0)
				a++;
			if(a == need) {
				used[j] = 1;
				minStr += 'a' + j;	
				count += need - 1;
				break;
			}
		}
	}	
	return minStr;
}
