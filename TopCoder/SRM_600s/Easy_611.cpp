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

int gcd(int A, int B) {
	if(B != 0) return gcd(B, A % B);	
	return A;	
}

int lcm_single(int A, int B) {
	long long result = (long long) A * B;
	result /= gcd(A, B);
	return result;
}

int getLCM(vector<int> &V) {
	int result = V[0];
	for(int i = 1; i < V.size(); i++)
		result = lcm_single(result, V[i]);
	return result;
}

class LCMSet {
public:
	string equal(vector <int>, vector <int>);
};

string LCMSet::equal(vector <int> A, vector <int> B) {
	vector<vector<int>> lcm(2);
	vector<vector<int>> P{A, B};
	for(int i = 0; i < 2; i++) {
		sort(P[i].begin(), P[i].end());	
		for(int x : P[i]) {
			if(lcm[i].size() < 2) lcm[i].push_back(x);
			else {
				vector<int> temp;
				for(int y : lcm[i]) {
					if(x % y == 0) 
						temp.push_back(y);
				}
				if(temp.empty() or getLCM(temp) < x) 
					lcm[i].push_back(x);
			}
		}
	}
	return lcm[0] == lcm[1] ? "Equal" : "Not equal";
}



