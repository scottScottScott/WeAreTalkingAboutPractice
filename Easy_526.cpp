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

class DucksAlignment {
public:
	int minimumTime(vector <string>);
};

int DucksAlignment::minimumTime(vector <string> grid) {	
	vector<pii> points;
	for(int r = 0; r < grid.size(); r++) {
		for(int c = 0; c < grid[0].size(); c++) {
			if(grid[r][c] == 'o') points.emplace_back(r, c);
		}
	}
	
	int minMoves = INT_MAX;

	sort(points.begin(), points.end());
	for(int y = 0; y + points.size() <= grid.size(); y++) {
		for(int x = 0; x < grid[0].size(); x++) {
			int moves = 0;
			int y_temp = y;
			for(pii p : points) {
				moves += abs(p.second - x);
				moves += abs(p.first - y_temp);
				y_temp++;
			}
			minMoves = min(moves, minMoves);
		}		
	}

	for(pii& p : points) {
		int temp = p.first;
		p.first = p.second;	
		p.second = temp;
	}
	sort(points.begin(), points.end());

	for(int y = 0; y < grid.size(); y++) {
		for(int x = 0; x + points.size() <= grid[0].size(); x++) {
			int moves = 0;
			int x_temp = x;
			for(pii p : points) {
				moves += abs(p.second - y);
				moves += abs(p.first - x_temp);
				x_temp++;
			}
			minMoves = min(moves, minMoves);
		}		
	}

	return minMoves;
}
