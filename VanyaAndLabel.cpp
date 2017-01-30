#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lookup(char X) {
	if(X >= '0' and X <= '9')
		return X - '0';
	if(X >= 'A' and X <= 'Z') 
		return X - 'A' + 10;
	if(X >= 'a' and X <= 'z')
		return X - 'a' + 36;

	return X == '-' ? 62 : 63;
}

int main() {
	vector<int> memo(64);
	for(int i = 0; i < 64; i++) {
		for(int j = 0; j < 64; j++) {
			memo[i & j]++;
		}
	}
	const int MOD = 1e9 + 7;

	string S;	
	cin >> S;
	int N = S.size();
	long long retVal = memo[lookup(S[0])];	
	for(int i = 1; i < N; i++)
		retVal = (retVal * memo[lookup(S[i])]) % MOD;

	cout << retVal << endl;
}
