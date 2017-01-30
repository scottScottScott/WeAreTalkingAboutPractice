#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX = 1 << 18;
int n, m, k;
vector<int> s;
vector<vector<ll>> memo(MAX, vector<ll>(18, -1));
vector<vector<int>> adjmat(18, vector<int> (18));

ll r_calc(int x, int last) {
	if(memo[x][last] != -1) return memo[x][last];
	ll &result = memo[x][last];
	result = 0;
	x ^= (1 << last);
	for(int i = 0; i < n; i++) {
		if( (x >> i) & 1)
			result = max( result, r_calc(x, i) + adjmat[i][last] );
	}
	result += s[last];
	return result;
}

int main() {
	cin >> n >> m >> k;
	s.resize(n);
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < k; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		x--; y--;
		adjmat[x][y] = c;
	}
	
	ll result = 0;
	for(int x = 1; x < (1 << n); x++) {
		int count = 0;
		for(int i = 0; i < n; i++) {
			if( (x >> i) & 1) 
				count++;
		}
		if(count == m) {
			for(int i = 0; i < n; i++) {
				if( (x >> i) & 1 )
					result = max(result, r_calc(x, i));
			}
		}
	}
	cout << result << endl;
}
