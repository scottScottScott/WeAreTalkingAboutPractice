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

class EvenRoute {
public:
	string isItPossible(vector <int>, vector <int>, int);
};

string EvenRoute::isItPossible(vector <int> x, vector <int> y, int wantedParity) {
	int numEven = 0;
	int numOdd = 0;
	
	for(int i = 0; i < x.size(); i++) {
		if(abs(x[i]) % 2 == abs(y[i]) % 2) numEven++;
		else numOdd++;
	}
	
	if(wantedParity == 1 and numOdd >= 1) return "CAN";
	else if(wantedParity == 0 and numEven >= 1) return "CAN"; 
	
	return "CANNOT";
}
