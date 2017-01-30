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

class Undo {
public:
	string getText(vector <string>, vector <int>);
};

string Undo::getText(vector <string> commands, vector <int> time) {
	string result;
	int N = commands.size();
	int lastValid = INT_MIN;
	for(int i = N - 1; i >= 0; i--) {
		if(lastValid != INT_MIN and time[i] >= lastValid) continue;
		istringstream iss(commands[i]);	
		string Type;
		iss >> Type;
		if(Type == "type") {
			char C;
			iss >> C;
			result += C;
		}
		else {
			int change;
			iss >> change; 
			if(lastValid == INT_MIN)
				lastValid = time[i] - change;
			else
				lastValid = min(lastValid, time[i] - change);
		}
	}

	reverse(result.begin(), result.end());
	return result;
}
