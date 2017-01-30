#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
	string S;
	cin >> S;
	int N = S.size();
	set<string> suffixes;	

	vector<vector<bool>> valid(N, vector<bool> (2));
	for(int n = N - 3; n >= 4; n--) {
		string temp;
		temp += S[n + 1];
		temp += S[n + 2];
		if(n + 3 == N or (valid[n + 3][0] and S.substr(n + 3, 2) != temp) or valid[n + 3][1]) {
			valid[n + 1][0] = true;
			suffixes.insert(temp);
		}
		
		if(n + 3 == N) continue;

		temp += S[n + 3];
		if(n + 4 == N or valid[n + 4][0] or (valid[n + 4][1] and S.substr(n + 4, 3) != temp)) {
			valid[n + 1][1] = true;
			suffixes.insert(temp);	
		}
	}

	cout << suffixes.size() << endl;
	for(string X : suffixes)
		cout << X << endl;
}
