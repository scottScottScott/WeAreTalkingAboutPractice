#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector<int> R, P, S;
ll p, k;

const int MOD = 1e9 + 7;

int getP(int i) {
	if(P[i] != i)
		P[i] = getP(P[i]);
	return P[i];
}

void merge(int x, int y) { 
	if(R[x] > R[y]) {
		P[y] = x;
		S[x] += S[y];
	}
	else {
		P[x] = y;
		S[y] += S[x];
		if(R[x] == R[y])
			R[y]++;
	}
}

int r_count(vector<int> &count, vector<bool> &V, int curr, int init, int length) {
	int next = (k * curr) % p;
	if(next == init) {
		count[length]++;	
		V[curr] = 1;
		return length;
	}
	else {
		int new_length = r_count(count, V, next, init, length + 1);
		V[curr] = 1;
		count[new_length]++;
		return new_length;
	}
}

int main() {
	cin >> p >> k;
	if(k == 0) {
		ll result = 1;
		for(int i = 1; i < p; i++) {
			result *= p;
			result %= MOD;
		}
		cout << result << endl;
		return 0;
	}
	R.resize(p);
	P.resize(p);
	S.resize(p, 1);
	for(int i = 0; i < p; i++)
		P[i] = i;
	for(int i = 0; i < p; i++) {
		int val = (k * i) % p;
		if(getP(val) != getP(i))
			merge(getP(val), getP(i));
	}
	vector<int> count(p);
	vector<bool> V(p);
	for(int i = 0; i < p; i++) {
		if(!V[i])
			r_count(count, V, i, i, 1);
	}
	ll result = 1;
	for(int i = 0; i < p; i++) {
		if(getP(i) != i) continue;
		if(S[i] == 1) {
			if(k == 1)
				result *= p;
		}
		else 
			result *= count[S[i]] + 1;
		result = result % MOD;
	}
	cout << result << endl;
}
