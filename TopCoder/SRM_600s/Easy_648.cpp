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

class AB {
public:
	string createString(int, int);
};

string AB::createString(int N, int K) {
	string result;
	for(int a = 0; a < N; a++) {
		int max = (N - a) * a;
		if(K <= max) {
			deque<int> temp;
			while(K > 0) {
				int add = min(a, K);
				K -= add;
				temp.push_back(add);
			}
			sort(temp.begin(), temp.end());
			for(int i = 0; i < a; i++) {
				result += 'A';
				while(!temp.empty() and temp.front() == i + 1) {
					temp.pop_front();
					result += 'B';
				}
			}
			while(result.size() < N) 
				result += 'A';
			return result;
		}
	}
	return result;
}
