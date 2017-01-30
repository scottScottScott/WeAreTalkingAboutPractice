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

class MyLongCake {
public:
	int cut(int);
};

const int MAX = 100000;
	

int MyLongCake::cut(int n) {
	vector<bool> P(MAX + 1, 1);	
	P[1] = P[0] = 0;
	for(int i = 2; i <= MAX; i++) {
		if(P[i] == 0) continue;
		for(int j = i + i; j <= MAX; j += i)
			P[j] = 0;
	}
	vector<int> F;
	for(int i = 2; i <= n; i++) {
		if(n % i == 0 and P[i])
			F.push_back(i);		
	}
	int segments = 0;
	for(int i = 1; i <= n; i++) {
		for(int x : F) {
			if(i % x == 0) {
				segments++;
				break;
			}
		}
	}
	return segments;
}
