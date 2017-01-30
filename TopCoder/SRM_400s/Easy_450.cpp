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

class OrderedNim {
public:
	string winner(vector <int>);
};

string OrderedNim::winner(vector <int> layout) {
	int N = layout.size();
	int count = 0;
	for(int i = 0; i < N; i++) {
		if(layout[i] == 1) count++;
		else break;
	}
	return ( (count != N and count % 2 == 1) or (count == N and count % 2 == 0))  ? "Bob" : "Alice";
}
