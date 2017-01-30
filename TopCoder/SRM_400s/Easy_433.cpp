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

vector<vector<int>> P;
vector<int> temp;
vector<bool> used(10);

void r_generate(int N) {
	if(temp.size() == N) {
		P.push_back(temp);
		return;
	}
	
	for(int i = 0; i < N; i++) {
		if(used[i] == 1) continue;
		
		used[i] = 1;
		temp.push_back(i);
		r_generate(N);
		used[i] = 0;
		temp.pop_back();
	}
}

class MagicWords {
public:
	int count(vector <string>, int);
};

int MagicWords::count(vector<string> S, int K) {
	int result = 0;	
	int N = S.size();	
	r_generate(N);
	for(vector<int> &curr_P : P) {
		string temp;
		for(int i : curr_P)
			temp += S[i];
		if(K > temp.size() or temp.size() % K != 0) continue;
		int period = temp.size() / K;

		bool valid = true;
		for(int i = 0; i <= period; i++) {
			char curr = temp[i];
			int j = i + period;
			for( ; j < temp.size(); j += period)
				if(temp[j] != curr) break;
			if(j < temp.size())
				valid = false;
		}
		if(!valid) continue;

		bool possible = true;
		for(int p = 1; p <= temp.size(); p++) {
			if(temp.size() % p != 0 or p >= period) continue;
			bool valid = true;
			for(int i = 0; i < p; i++) {
				char curr = temp[i];
				int j = i + p;
				for( ; j < temp.size(); j += p)
					if(temp[j] != curr) break;
				if(j < temp.size())
					valid = false;
			}
			if(valid == true) possible = false; 
		}
		if(!possible) continue;

		result++;
	}
	return result;
}
