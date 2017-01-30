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

int N;
vector<string> P;

void generate(string &curr, vector<bool> &used) {
	if(curr.size() == N) {
		P.push_back(curr);
		return;
	}

	for(int i = 1; i <= N; i++) {
		if(used[i]) continue;
		
		used[i] = 1;
		curr += '0' + i;
		generate(curr, used);
		used[i] = 0;
		curr.pop_back();
	}
}

void swap(string &S, int i, int j) {
	char temp = S[i];
	S[i] = S[j];
	S[j] = temp;
}

class RandomSort {
public:
	double getExpected(vector <int>);
};

double RandomSort::getExpected(vector<int> permutation) {
	N = permutation.size();	
	string curr;
	vector<bool> used(N + 1);
	generate(curr, used);

	string p_str;
	for(int x : permutation)
		p_str += '0' + x;

	vector<vector<int>> levels(1 + N * (N - 1) / 2);
	unordered_map<string, int> toIndex;
	for(int p = 0; p < P.size(); p++) {
		string &curr = P[p];
		int count = 0;
		for(int i = 0; i < N; i++) {
			for(int j = i + 1; j < N; j++)
				if(curr[i] > curr[j]) count++;
		}	
		levels[count].push_back(p);
		
		toIndex[curr] = p;
	}	

	vector<double> memo(P.size());
	for(int L = 1; L < levels.size(); L++) {
		for(int I : levels[L]) {
			string &curr = P[I];
			double &temp = memo[I];
			for(int i = 0; i < N; i++) {
				for(int j = i + 1; j < N; j++) {
					if(curr[i] > curr[j]) {
						swap(curr, i, j);
						temp += memo[toIndex[curr]] + 1;
						swap(curr, i, j);
					}
				}
			}
			temp /= L;	
		}
	}

	return memo[toIndex[p_str]];
}
