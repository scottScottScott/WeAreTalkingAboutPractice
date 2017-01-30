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

class TheTower {
public:
	vector <int> count(vector <int>, vector <int>);
};

vector<int> TheTower::count(vector <int> x, vector <int> y) {
	int N = x.size();
	vector<int> result(N, INT_MAX);	
	result[0] = 0;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			vector<int> A;
			for(int k = 0; k < N; k++)
				A.push_back( abs(x[i] - x[k]) + abs(y[j] - y[k]) );	
			sort(A.begin(), A.end());
			int moves = 0;
			for(int i = 0; i < N; i++) {
				moves += A[i];
				result[i] = min(result[i], moves);
			}
		}
	} 
	return result;
}
