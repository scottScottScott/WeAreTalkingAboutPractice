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

class CorporationSalary {
public:
	long long totalSalary(vector <string>);
};

long long CorporationSalary::totalSalary(vector<string> relations) {
	int N = relations.size();
	vector<long long> val(N);
	vector<int> children(N);
	deque<int> Q;
	for(int r = 0; r < N; r++) {
		int &numC = children[r];
		for(int c = 0; c < N; c++)
			if(relations[r][c] == 'Y') numC++;
		if(numC == 0)
			Q.push_back(r);
	}		

	long long result = 0;
	while(!Q.empty()) {
		int curr = Q.front();
		Q.pop_front();
		long long &temp = val[curr];
		for(int c = 0; c < N; c++) {
			if(relations[curr][c] == 'Y')
				temp += val[c];		
		}
		if(temp == 0) temp = 1;
		result += temp;
		for(int r = 0; r < N; r++) {
			if(relations[r][curr] == 'Y') {
				if(--children[r] == 0)
					Q.push_back(r);	
			}
		}
	}
	return result;
}
