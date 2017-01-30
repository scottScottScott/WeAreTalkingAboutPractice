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

long long memo[31][31];

class FIELDDiagrams {
public:
	long long countDiagrams(int);
};

long long FIELDDiagrams::countDiagrams(int fieldOrder) {
	long long result = 0;

	memo[0][0] = 1;
	for(int col = 1; col <= fieldOrder; col++) {
		memo[0][col] = 1;
		for(int row = 1; row <= col; row++) {
			
			for(int past = 0; past <= min(row, col - 1); past++)
				memo[row][col] += memo[past][col - 1];
			
			if(col == fieldOrder) result += memo[row][col];
		}
	}
	
	return result;
}



