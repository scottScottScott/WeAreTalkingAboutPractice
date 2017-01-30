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

const double eps = 1e-6;

class PointyWizardHats {
public:
	int getNumHats(vector <int>, vector <int>, vector <int>, vector <int>);
};

double valid(int topH, int topR, int bottomH, int bottomR) {
	if(topR >= bottomR) return -1;
	
	double new_height = ( (double) topR / bottomR) * bottomH;
	if(new_height >= topH - eps) return -1;

	return topH - new_height;
}

int PointyWizardHats::getNumHats(vector <int> topHeight, vector <int> topRadius, vector <int> bottomHeight, vector <int> bottomRadius) {
	int N = topHeight.size();
	int M = bottomHeight.size();
	vector<pii> info;		
	for(int i = 0; i < N; i++)
		info.emplace_back(topRadius[i], topHeight[i]);
	sort(info.rbegin(), info.rend());

	vector<bool> used(M);
	for(int top = 0; top < N; top++) {
		int bestIndex = INT_MAX;
		double minHeight = 0;
		for(int bottom = 0; bottom < M; bottom++) {
			if(used[bottom] == true) continue;
			
			double currHeight = 0;
			if( (currHeight = valid(info[top].second, info[top].first, bottomHeight[bottom], bottomRadius[bottom])) != -1) {
				if(bestIndex == INT_MAX or currHeight < minHeight) {
					minHeight = currHeight;
					bestIndex = bottom;
				}
			}
		}
		if(bestIndex != INT_MAX) {
			used[bestIndex] = true;	
		}		
	}
	
	return accumulate(used.begin(), used.end(), 0);
}
