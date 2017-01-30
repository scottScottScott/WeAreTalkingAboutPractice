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

double dist(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool isInside(int x, int y, int X, int Y, int R) {
	double D = dist(x, y, X, Y);
	return D < R;
}

class CirclesCountry {
public:
	int leastBorders(vector <int>, vector <int>, vector <int>, int, int, int, int);
};

int CirclesCountry::leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2) {
	int N = X.size();
	vector<vector<int>> surfaces(2);	
	vector<pii> P { {x1, y1}, {x2, y2} };
	for(int a = 0; a < 2; a++) {
		pii curr = P[a];
		vector<bool> visited(N);
		for(int i = 0; i < N; i++) {
			int best = INT_MAX;
			for(int j = 0; j < N; j++) {
				if(visited[j]) continue;
				if(isInside(curr.first, curr.second, X[j], Y[j], R[j])) {
					if(best == INT_MAX or R[j] < R[best])
						best = j;
				}
			}
			if(best != INT_MAX) {
				visited[best] = true;
				surfaces[a].push_back(best);
			}
		}
	}

	for(int i = 0; i < surfaces[0].size(); i++) {
		for(int j = 0; j < surfaces[1].size(); j++) {
			if(surfaces[0][i] == surfaces[1][j])
				return i + j;
		}
	}
	return surfaces[0].size() + surfaces[1].size();
}



