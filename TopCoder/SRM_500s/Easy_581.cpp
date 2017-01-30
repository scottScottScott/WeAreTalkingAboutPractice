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

class SurveillanceSystem {
public:
	string getContainerInfo(string, vector <int>, int);
};

string SurveillanceSystem::getContainerInfo(string containers, vector <int> reports, int L) {
	int N = containers.size();
	string result(N, '-');	
	map<int, int> M;
	for(int X : reports) 
		M[X]++;

	map<int, int> total;
	for(int i = 0; i <= N - L; i++) {
		int val = 0;
		for(int j = 0; j < L; j++) {
			if(containers[i + j] == 'X')
				val++;
		}
		total[val]++;
	}

	vector<vector<int>> memo(N, vector<int> (L + 1));
	for(int i = 0; i < N; i++) {
		for(int start = i - L + 1; start <= i; start++) {
			if(start < 0) continue;
			if(start + L > N) continue;
			int count = 0;
			for(int j = start; j < start + L; j++) {
				if(containers[j] == 'X') count++;
			}
			memo[i][count]++;
		}
	}	

	for(pii curr : M) {
		int T = total[curr.first];
		int temp = curr.second;
		for(int i = 0; i < N; i++) {
			int count = memo[i][curr.first];
			if(T - count < temp) result[i] = '+';
			else if(count >= 1) {
				if(result[i] == '-') 
					result[i] = '?';
			}
		}
	}

	return result;
}
