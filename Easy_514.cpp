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

class MinimumSquare {
public:
	long long minArea(vector <int>, vector <int>, int);
};

long long MinimumSquare::minArea(vector <int> x, vector <int> y, int K) {
	int result = INT_MAX;
	vector<pii> points;
	for(int i = 0; i < x.size(); i++)
		points.emplace_back(x[i], y[i]);
	sort(points.begin(), points.end());
	for(int i = 0; i < points.size(); i++) {
		for(int j = i; j < points.size(); j++) {
			int left, right, up, down;
			left = points[i].first - 1;
			right = points[j].first + 1;	
			up = max(points[i].second, points[j].second) + 1;
			down = min(points[i].second, points[j].second) - 1;
			int width = right - left;
			int height = up - down;
			int count = 0;
			vector<int> special;
			for(pii curr : points) {
				if(curr.first > left and curr.first < right) {
					if(curr.second > down and curr.second < up)
						count++;
					else if(curr.second >= up)
						special.push_back(curr.second + 1);	
					else if(curr.second <= down)
						special.push_back(curr.second - 1);
				}
			}
			if(count >= K) {
				result = min(result, max(width, height));
				continue;
			}

			sort(special.rbegin(), special.rend());
			int need = K - count;
			for(int i = 0; i + need - 1 < special.size(); i++) {
				if(special[i + need - 1] > up)
					height = special[i] - down;				
				else if(special[i] < down)
					height = up - special[i + need - 1];
				else 
					height = special[i] - special[i + need - 1];
				result = min(result, max(width, height));
			}
		}
	}
	return (long long) result * result;
}
