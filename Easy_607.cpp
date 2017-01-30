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

class PalindromicSubstringsDiv1 {
public:
	double expectedPalindromes(vector <string>, vector <string>);
};

double PalindromicSubstringsDiv1::expectedPalindromes(vector <string> S1, vector <string> S2) {
	string S;	
	for(string temp : S1)
		S += temp;
	for(string temp : S2)
		S += temp;
	int N = S.size();
	vector<int> count(N + 1);
	for(int i = 0; i < N; i++) {
		int P = 0;
		count[P]++;
		for(int size = 1; size <= min(N - 1 - i, i); size++) {
			if(S[i + size] == S[i - size] and S[i + size] != '?')
				count[P]++;
			else if(S[i + size] == '?' or S[i - size] == '?') {
				P++;
				count[P]++;
			}
			else break;
		}
	}
	for(int i = 0; i + 1 < N; i++) {
		int j = i + 1;
		int P = 0;
		for(int size = 0; size <= min(N - 1 - j, i); size++) {
			if(S[i - size] == S[j + size] and S[i - size] != '?')
				count[P]++;
			else if(S[j + size] == '?' or S[i - size] == '?') {
				P++;
				count[P]++;
			}
			else break;
		}
	}

	double result = 0;
	for(int i = count.size() - 1; i >= 0; i--) {
		result /= 26;
		result += count[i];	
	}
	return result;
}
