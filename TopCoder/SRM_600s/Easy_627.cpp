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

class HappyLetterDiv1 {
public:
	string getHappyLetters(string);
};

string HappyLetterDiv1::getHappyLetters(string letters) {
	string result;
	vector<int> count(26);	
	for(char x : letters)
		count[x - 'a']++;
	for(int i = 0; i < 26; i++) {
		int curr = count[i];
		if(curr == 0) continue;
		deque<int> temp;
		for(int j = 0; j < 26; j++) {
			if(count[j] != 0 and j != i)
				temp.push_back(count[j]);
		}
		while(temp.size() > 1) {
			sort(temp.rbegin(), temp.rend());
			temp[0]--;
			temp[1]--;
			sort(temp.begin(), temp.end());
			while(!temp.empty() and temp.front() == 0)
				temp.pop_front();	
		}
		if(temp.empty() or curr > temp[0])
			result += i + 'a';
	}
	sort(result.begin(), result.end());	
	return result;
}
