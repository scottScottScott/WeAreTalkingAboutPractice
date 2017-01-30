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

class TheConsecutiveIntegersDivOne {
public:
	int find(vector <int>, int);
};

int TheConsecutiveIntegersDivOne::find(vector <int> numbers, int k) {
	int result = INT_MAX;
	sort(numbers.begin(), numbers.end());
	for(int i = 0; i + k <= numbers.size(); i++) {
			
			int middle = i + k / 2;
			int total = 0;	
			for(int a = i; a < i + k; a++) {
				int need = numbers[middle] - (middle - a);
				total += abs(numbers[a] - need);				
			}
			result = min(result, total);

			total = 0;
			for(int a = i; a < i + k; a++) {
				int need = numbers[middle] - (a - middle);
				total += abs(numbers[a] - need);				
			}
			result = min(result, total);

	}
	return result;
}
