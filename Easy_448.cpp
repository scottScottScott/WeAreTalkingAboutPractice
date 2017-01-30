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

vector<bool> visited(52);	
vector<int> val(52);
double result;

void r_calculate(int curr, double prob, int numCards) {
	if(curr >= 21) {
		result += numCards * prob;
		return;
	}
	int choices = 0;
	for(int i = 0; i < 52; i++)
		if(visited[i] == 0)
			choices++;
	for(int i = 0; i < 52; i++) {
		if(visited[i] == 0) {
			visited[i] = 1;
			r_calculate(curr + val[i], prob / choices, numCards + 1);
			visited[i] = 0;
		}
	}
}


class TheBlackJackDivOne {
public:
	double expected(vector <string>);
};

double TheBlackJackDivOne::expected(vector <string> cards) {
	int curr = 0;
	for(int i = 2; i <= 10; i++) {
		for(int j = 0; j < 4; j++)
			val[curr++] = i;
	}
	while(curr < 48) val[curr++] = 10;
	while(curr < 52) val[curr++] = 11;

	int currVal = 0;
	for(string x : cards) {
		char A = x[0];
		char B = x[1];
		int index = 0;
		if(A == 'T') index = 8;
		else if(A == 'J') index = 9;
		else if(A == 'Q') index = 10;
		else if(A == 'K') index = 11;
		else if(A == 'A') index = 12;
		else index = A - '2';
		index *= 4;
		if(B == 'C') index += 1;	
		else if(B == 'D') index += 2;
		else if(B == 'H') index += 3;
		visited[index] = true;
		currVal += val[index];
	}
	if(currVal >= 21) return 0;
	r_calculate(currVal, 1, 0);
	return result;
}



