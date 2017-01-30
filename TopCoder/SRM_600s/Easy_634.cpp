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

bool isPossible(int N, int K, int numK, vector<int> &s) {
	deque<int> temp(s.begin(), s.end());
	sort(temp.begin(), temp.end());
	while(!temp.empty() and temp.front() == 0) 
		temp.pop_front();
	for(int i = 0; i < numK; i++) {
		for(int j = 0; j < temp.size(); j++)
			temp[j]--;
		while(!temp.empty() and temp.front() == 0)
			temp.pop_front();
	}
	int maxRemove = K - 1;	
	int L = N - numK;
	while(L-- > 0 and !temp.empty()) {
		sort(temp.rbegin(), temp.rend());	
		for(int i = 0; i < min(maxRemove, (int) temp.size()); i++)
			temp[i]--;
		sort(temp.begin(), temp.end());
		while(!temp.empty() and temp.front() == 0)
			temp.pop_front();
	}
	return temp.empty();
}

class ShoppingSurveyDiv1 {
public:
	int minValue(int, int, vector <int>);
};

int ShoppingSurveyDiv1::minValue(int N, int K, vector <int> s) {
	int result = N;

	int lo = 0;
	int hi = N;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		bool valid = isPossible(N, K, mid, s);
		if(valid) {
			result = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	
	return result;
}
