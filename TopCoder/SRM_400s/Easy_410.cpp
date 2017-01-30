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

class AddElectricalWires {
public:
	int maxNewWires(vector <string>, vector <int>);
};

int AddElectricalWires::maxNewWires(vector<string> wires, vector<int> gridConnections) {
	int N = wires.size();

	int edges = 0;
	for(int r = 0; r < N; r++) {
		for(int c = r + 1; c < N; c++)
			edges += (wires[r][c] == '1');
	}	
	
	int maxN = 0;
	int result = 0;
	vector<bool> V(N);
	for(int X : gridConnections) {
		V[X] = 1;	
		deque<int> Q{X};
		int count = 1;
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop_front();
			for(int i = 0; i < N; i++) {
				if(wires[curr][i] == '1' and !V[i]) {
					count++;
					Q.push_back(i);
					V[i] = 1;
				}
			}
		}
		if(count > maxN) maxN = count;
		result += count * (count - 1) / 2;
	}

	int remain = 0;	
	for(int i = 0; i < N; i++)
		if(!V[i]) remain++;
	result -= maxN * (maxN - 1) / 2;	
	maxN += remain;
	result += maxN * (maxN - 1) / 2;	

	return result - edges;
}
