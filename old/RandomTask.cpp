#include <iostream>
#include <bitset>
#include <string>

using namespace std;

typedef long long ll;

ll choose[64 + 1][64 + 1];

ll count(ll N, ll K) {
	string S = bitset<64>(N).to_string();	
	int set = K;
	ll result = 0;
	for(int i = 0; i < S.size(); i++) {
		if(S[i] == '1') {
			int length = S.size() - i - 1;
			if(length >= set)
				result += choose[length][set];	
			set--;
		}
		if(set < 0)
			break;
	}	
	return result;
}

int main() {
	choose[0][0] = 1;
	for(int r = 1; r <= 64; r++) {
		choose[r][0] = 1; 
		for(int c = 1; c <= r; c++)
			choose[r][c] = choose[r - 1][c - 1] + choose[r - 1][c];
	}
	ll m;
	int k;
	cin >> m >> k;
	ll lo = 1;
	ll hi = 1e18;
	while(lo <= hi) {
		ll curr = lo + (hi - lo) / 2;
		ll val = count(2 * curr + 1, k) - count(curr + 1, k);
		if(val == m) {
			cout << curr << endl;
			return 0;
		}
		else if(val < m)
			lo = curr + 1;
		else
			hi = curr - 1;
	}
}
