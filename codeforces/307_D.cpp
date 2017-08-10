#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

map<pll, int> M;
map<int, vector<int> > F;

ll m;

ll getPow(int x, ll n) {
	if(n == 0) return 1;
	if(n == 1) return x; 	
	pll curr{x, n};
	if(M.count(curr)) return M[curr];
	if(n % 2 == 0)
		M[curr] = getPow(x, n / 2) * getPow(x, n / 2) % m;
	else
		M[curr] = x * getPow(x, n - 1) % m;
	return M[curr];
}

void r_fib(ll n) {
	if(F.count(n)) return;
	vector<int> temp(4);
	r_fib(n / 2);
	vector<int> A, B;
	if(n % 2 == 0) {
		r_fib(n / 2);
		A = B = F[n / 2];
	}
	else {
		r_fib(n - 1);
		A = F[n - 1];
		B = F[1];
	}
	temp[0] = ((ll) A[0] * B[0] + (ll) A[1] * B[2]) % m;
	temp[1] = ((ll) A[0] * B[1] + (ll) A[1] * B[3]) % m;
	temp[2] = ((ll) A[2] * B[0] + (ll) A[3] * B[2]) % m;
	temp[3] = ((ll) A[2] * B[1] + (ll) A[3] * B[3]) % m;
	F[n] = temp;
}

int calc_fib(ll n) {
	F[1] = vector<int> {1, 1, 1, 0};
	r_fib(n);
	return ((ll) F[n][0] + F[n][1]) % m;
}

int main() {
	ll n, k, l; 
	cin >> n >> k >> l >> m;
	ll half_n = n / 2;	
	ll zeroC, oneC;
	zeroC = oneC = 1;
	ll totalC = getPow(2, n); 
	zeroC = calc_fib(n);
	oneC = (totalC - zeroC + m) % m;
	ll total = 1 % m;
	for(int b = 63; b >= 0; b--) {
		ll temp;
		if(k >> b & 1) {
			if(b >= l) total = 0;
			temp = oneC;
		}	
		else if(b >= l)
			continue;
		else
			temp = zeroC;
		total = total * temp % m;	
	}
	cout << total << endl;
}
