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

int n;
vector<int> p;

int getP(int a) {
	if(p[a] != a)
		p[a] = getP(p[a]);
	return p[a];
}

void merge(int a, int b) {
	p[b] = a;
}

class ChristmasTreeDecoration {
public:
	int solve(vector <int>, vector <int>, vector <int>);
};

int ChristmasTreeDecoration::solve(vector <int> col, vector <int> x, vector <int> y) {
	n = col.size();
	p.resize(n);
	for(int i = 0; i < n; i++) p[i] = i;
	for(int i = 0; i < x.size(); i++) {
		if(col[x[i] - 1] != col[y[i] - 1])
			merge(getP(x[i] - 1), getP(y[i] - 1));
	} 
	vector<bool> v(n);
	int result = 0;
	for(int i = 0; i < n; i++) {
		if(v[i] == 1) continue;
		v[i] = 1;
		result++;
		for(int j = i + 1; j < n; j++) {
			if(getP(i) == getP(j)) 
				v[j] = 1;
		}
	}
	return result - 1;
}
