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

vector<int> curr {0};
vector<vector<int>> permutations;
vector<bool> used(8);

void generate(int N) {
	if(curr.size() == N + 1) {
		permutations.push_back(curr);
		return;
	}
	
	for(int i = 1; i <= N; i++) {
		if(used[i] == 0) {
			used[i] = 1;
			curr.push_back(i);
			generate(N);
			used[i] = 0;
			curr.pop_back();
		}
	}
}

class SymmetricPie {
public:
	int getLines(vector <int>);
};

int SymmetricPie::getLines(vector<int> dogs) {
	int N = dogs.size();
	generate(N - 1);
	int result = 0;	
	for(vector<int> &P : permutations) {
		int total = 0;
		for(int i = 0; i < N; i++) {
			int temp = 0;
			for(int j = i; j < i + N; j++) {
				temp += dogs[P[j % N]];
				if(temp == 50) {
					total++;
					break;
				}
			}
		}
		result = max(result, total / 2);
	}
	return result;	
}
