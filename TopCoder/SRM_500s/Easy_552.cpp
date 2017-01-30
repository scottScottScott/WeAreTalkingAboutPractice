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

class FoxPaintingBalls {
public:
	long long theMax(long long, long long, long long, int);
};

long long FoxPaintingBalls::theMax(long long R, long long G, long long B, int N) {
	if(N == 1) return R + G + B;

	long long count = 0;

	long long total = (long long) (N + 1) * N / 2;		
	bool extra = (total % 3 == 1);
	long long part = total / 3;

	vector<long long> colors {R, G, B};
	sort(colors.rbegin(), colors.rend());
	while(extra and colors[0] > colors[2] and colors[2] >= part) {
		long long diff = colors[0] - colors[2];
		long long times = min(diff, colors[2] / part);	
		for(long long& X : colors)
			X -= times * part;
		colors[0] -= times * extra;
		count += times;
		sort(colors.rbegin(), colors.rend());
	}

	long long times = colors[2] / total;
	for(long long& X : colors)
		X -= times * total;
	count += times * 3;
	sort(colors.rbegin(), colors.rend());

	while(colors[0] >= part + extra and colors[2] >= part) {
		for(long long& X : colors) 
			X -= part;
		colors[0] -= extra;
		count++;
		sort(colors.rbegin(), colors.rend());
	}
	
	return count;
}
