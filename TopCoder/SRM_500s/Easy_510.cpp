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

class TheAlmostLuckyNumbersDivOne {
public:
	long long find(long long, long long);
};

bool isLessEqual(string& str, string& A) {
	for(int i = 0; i < str.size(); i++) {
		if(str[i] < A[i]) return true;
		else if(str[i] == A[i]) continue;
		else return false;
	}
	return true;
}

// count # lucky numbers <= A
long long countLucky(string& str, string& A, bool used) {
	long long count = 0;
	if(A == "0") return count; 

	str += " ";
	int N = str.size();
	for(char x = '0'; x <= '9'; x++) {
		str[N - 1] = x; 	
		if(N == A.size()) {
			if(str[0] != '0' and (!used or x == '4' or x == '7') and isLessEqual(str, A))
				count++;
			continue;
		}
		
		if(str[0] != '0' and (!used or x == '4' or x == '7')) count++;
		
		if(x == '4' or x == '7') count += countLucky(str, A, used); 
		else if(used == false) count += countLucky(str, A, true);
	}
	str.pop_back();
	return count;
}

long long TheAlmostLuckyNumbersDivOne::find(long long a, long long b) {
	string null_str = "";
	string a_str = to_string(a - 1);
	string b_str = to_string(b);
	return countLucky(null_str, b_str, false) - countLucky(null_str, a_str, false);	
}
