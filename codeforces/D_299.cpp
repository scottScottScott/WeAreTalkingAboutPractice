#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;

vector<int> z_algorithm(string &S, string &P) {
	string A = P + "$" + S;
	vector<int> Z(A.size());
	Z[0] = A.size();
	int l, r;
	l = r = 0;
	for(int i = 1; i < A.size(); i++) {
		if(i > r) {
			if(A[i] == A[0]) {
				r = l = i;
				while(r + 1 < A.size() and A[r + 1] == A[r + 1 - l])
					r++;
				Z[i] = r - l + 1;
			}
			else 
				Z[i] = 0;
		}	
		else {
			if(i + Z[i - l] - 1 < r)
				Z[i] = Z[i - l];
			else {
				l = i;
				while(r + 1 < A.size() and A[r + 1] == A[r + 1 - l])
					r++;
				Z[i] =  r - l + 1;
			}
		}
	}
	return Z;
}

int main() {
	int n, m;	
	string P;
	cin >> n >> m >> P;
	vector<int> start(m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &start[i]);
		start[i]--;
	}
	string S;
	for(int x : start) {
		if(x < S.size()) {
			int curr = S.size() - x;
			while(curr < P.size())
				S += P[curr++];
		}
		else {
			while(x > S.size()) 
				S += '$'; 
			for(char C : P)
				S += C;
		}
	}	
	while(S.size() < n) S += '$';
		
	ll result = 1;	
	vector<int> scores = z_algorithm(S, P);	
	for(int x : start) {
		if(scores[x + P.size() + 1] < P.size())
			result = 0;
	}
	for(char x : S) {
		if(x == '$')
			result = (result * 26) % MOD;
	}
	cout << result << endl;
				
}
