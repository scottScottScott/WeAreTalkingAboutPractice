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

double result = 0;
bool visited[30 + 1][30 + 1];
int N;
vector<pii> Next { {1, 0}, {-1, 0}, {0, -1}, {0, 1} }; 

class CrazyBot {
public:
	double getProbability(int, int, int, int, int);
};

void r_visit(int n, int x, int y, vector<double> &P, double currProb) {
	if(n == N) {
		result += currProb;
		return;
	}

	visited[x][y] = 1;	

	for(int i = 0; i < Next.size(); i++) {
		int new_x = x + Next[i].first;
		int new_y = y + Next[i].second;
		if(!visited[new_x][new_y])
			r_visit(n + 1, new_x, new_y, P, currProb * P[i]);
	}

	visited[x][y] = 0;
}


double CrazyBot::getProbability(int n, int east, int west, int south, int north) {
	N = n;
	vector<double> P {east / 100.0, west / 100.0, south / 100.0, north / 100.0};	
	r_visit(0, 15, 15, P, 1);
	return result;
}
