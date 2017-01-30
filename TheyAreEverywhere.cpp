#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> M;
	int total = 0;
	for(char x : s) {
		if(M.count(x)) continue;	
		M[x] = total;
		total++;
	}
	int result = n;
	vector<int> count(total);
	int types = 0;
	int end = 0;
	for(int start = 0; start < n; start++) {
		while(types < total) {
			if(end == n) break;
			char curr = s[end];
			end++;
			if(count[M[curr]]++ == 0) types++;
		}
		if(types < total) break;
		result = min(result, end - start);
		char x = s[start];
		if(--count[M[x]] == 0) types--;
	}
	cout << result << endl; }
