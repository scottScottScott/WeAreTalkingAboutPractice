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

class OddEvenTree {
public:
	vector <int> getTree(vector <string>);
};

vector <int> OddEvenTree::getTree(vector <string> x) {
	int n = x.size();	
	vector<int> result;
	vector<int> bad {-1};
	vector<int> a, b;
	for(int i = 0; i < n; i++)
		if(x[i][i] == 'O') 
			return bad;
	for(int i = 1; i < n; i++) {
		if(x[0][i] != x[i][0])
			return bad;
			
		if(x[0][i] == 'O') a.push_back(i);			
		else b.push_back(i);
	}
	if(a.empty() and !b.empty()) 
		return bad;	
	for(int aa : a) {
		for(int bb : b)
			if(x[aa][bb] != 'O' or x[bb][aa] != 'O') return bad;
	}
	for(int aa : a) {
		for(int bb : a)
			if(x[aa][bb] != 'E') return bad;
	}
	for(int aa : b) {
		for(int bb : b)
			if(x[aa][bb] != 'E') return bad;
	}

	int root = 0; 
	for(int z : a) {
		result.push_back(root);
		result.push_back(z);
	}
	root = a.front();
	for(int z : b) {
		result.push_back(root);
		result.push_back(z);
	}
	return result;
}
