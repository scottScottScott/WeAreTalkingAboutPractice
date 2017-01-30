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

class GooseTattarrattatDiv1 {
public:
	int getmin(string);
};

int GooseTattarrattatDiv1::getmin(string S) {
	int N = S.size();
	vector<int> count(26);
	for(char X : S)
		count[X - 'a']++;

	vector<bool> visited(26);
	int result = 0;
	for(int i = 0; i < S.size() / 2; i++) {
		if(visited[S[i] - 'a'] == 1) continue;
		
		int other = N - 1 - i;	
		visited[S[i] - 'a'] = 1;
		visited[S[other] - 'a'] = 1;
		unordered_set<char> group{S[i], S[other]};
		for(int x = i + 1; x < S.size() / 2; x++) {
			for(int j = i + 1; j < S.size() / 2; j++) {
				char temp_1 = S[j];	
				char temp_2 = S[N - 1 - j];
				if(group.count(temp_1)) {
					group.insert(temp_2);
					visited[temp_2 - 'a'] = true;
				}
				if(group.count(temp_2)) {
					group.insert(temp_1);
					visited[temp_1 - 'a'] = true;
				}
			}
		}

		int total = 0;
		int maxVal = 0;	
		for(char X : group) {
			total += count[X - 'a'];
			maxVal = max(maxVal, count[X - 'a']);
		}
		result += total - maxVal;
	}

	return result;
}
