#nclude <vector>
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

class SubrectanglesOfTable {
public:
	vector<long long> getQuantity(vector <string>);
};

vector<long long> SubrectanglesOfTable::getQuantity(vector <string> table) {
	for(string &x : table) x += x;
	int M = table.size();
	for(int i = 0; i < M; i++)
		table.push_back(table[i]);
	vector<long long> result(26);	
	M = table.size();
	int N = table[0].size();
	for(int r = 0; r < M; r++) {
		for(int c = 0; c < N; c++)
			result[table[r][c] - 'A'] += (r + 1) * (c + 1) * (M - r) * (N - c);
	}
	return result;
}
