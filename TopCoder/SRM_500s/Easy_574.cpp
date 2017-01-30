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

class TheNumberGame {
public:
	string determineOutcome(int, int);
};

string TheNumberGame::determineOutcome(int A, int B) {
	string A_str = to_string(A);
	string B_str = to_string(B);
	for(int x = 0; x < 2; x++) {
		for(int i = 0; i < A_str.size(); i++) {
			for(int j = 0; j < B_str.size(); j++) {
				if(i + j < A_str.size() and A_str[i + j] == B_str[j]) {}
				else break;
			
				if(j == B_str.size() - 1) return "Manao wins";
			}
		}
		reverse(A_str.begin(), A_str.end());
	}
	return "Manao loses";
}
