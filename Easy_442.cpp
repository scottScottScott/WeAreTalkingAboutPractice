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

const int MAX = 100000;

class Underprimes {
public:
	int howMany(int, int);
};

int Underprimes::howMany(int A, int B) {
	vector<int> count(MAX + 1);
	vector<int> val(MAX + 1);
	for(i = 1; i <= MAX; i++)
		val[i] = i;
	for(int i = 2; i <= MAX; i++) {
		if(count[i] != 0) continue;
		count[i] = 1;
		for(int j = i + i; j <= MAX; j += i) {
			while(val[j] % i == 0) {
				val[j] /= i;
				count[j]++;
			}
		}
	}

	int result = 0;
	for(int i = A; i <= B; i++) {
		if(count[count[i]] == 1)
			result++;
	}
	return result;
}



