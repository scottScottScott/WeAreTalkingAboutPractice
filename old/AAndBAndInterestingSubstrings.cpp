#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int toInt(char x) {
	return x - 'a';
}

int main() {
	vector<int> X(26);
	for(int i = 0; i < 26; i++)
		cin >> X[i];
	string S;
	cin >> S;
	int n = S.size();	
	vector<ll> A(n);
	map<ll, vector<int>> M;
	for(int i = 0; i < n; i++) {
		A[i] = (i == 0 ? 0 : A[i - 1]) + X[toInt(S[i])];
		M[A[i]].push_back(i);
	}
	ll result = 0;
	for(int i = 0; i + 1 < n; i++) {
		if(S[i] == S[i + 1])
			result++;
	}
	for(auto temp : M) {
		vector<int> &V = temp.second;
		vector<int> memo(26);
		for(int i = 1; i < V.size(); i++) {
			int idx = V[i];
			if(idx + 1 >= n)
				continue;
			memo[toInt(S[idx + 1])]++;
		}
		for(int i = 0; i < V.size(); i++) {
			int idx = V[i];
			if(i != 0 and idx + 1 < n)
				memo[toInt(S[idx + 1])]--;
			result += memo[toInt(S[idx])];
		}
	}
	cout << result << endl;
}
