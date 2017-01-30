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

class ShipLoading {
public:
	int minimumTime(vector <int>, vector <string>);
};

int ShipLoading::minimumTime(vector <int> cranes, vector <string> boxes) {
	string str;
	for(string &temp : boxes)
		str += temp;
	vector<int> B;
	istringstream iss(str);
	int curr;
	while(iss >> curr)
		B.push_back(curr);
	
	sort(cranes.begin(), cranes.end());
	int N = cranes.size();
	vector<int> count(N);
	for(int x : B) {
		if(x > cranes[N - 1]) return -1;
		for(int i = 0; i < cranes.size(); i++) {
			if(cranes[i] >= x) {
				count[i]++;
				break;
			}
		}
	}

	stack<pii> S;
	int result = 0;
	int total = 0;
	int size = 0;
	for(int i = N - 1; i >= -1; i--) {
		if(i == N - 1) {
			total = count[N - 1];
			size = 1;
		}
		else if(i != -1 and count[i] >= total / size) {
			total += count[i];
			size++;
			while(!S.empty() and (total / size >= S.top().first / S.top().second)) {
				total += S.top().first;
				size += S.top().second;
				S.pop();
			}
		}
		else {
			S.emplace(total, size);
			if(i != -1)	
				total = count[i];
			size = 1;
		}
	}
	while(!S.empty()) {
		pii curr = S.top();
		S.pop();
		result = max(result, (curr.first + curr.second - 1) / curr.second);
	}
	return result;
}
