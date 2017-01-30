#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll countSquares(ll n, ll m) {
	ll result = 3 * (n + 1) * n * m;
	result -= n * n * n;
	result += n;
	return result / 6;
}

int main() {
	ll x;
	cin >> x;
	vector<pll> result;
	for(int n = 1; n < 3e6; n++) {
		ll low = n;
		ll high = (ll) 3e18 / (n + 1) / n;	
		while(low <= high) {
			ll m = low + (high - low) / 2;
			ll val = countSquares(n, m);
			if(val == x) {
				result.emplace_back(n, m);	
				if(n != m) result.emplace_back(m, n);
				break;
			}
			else if(val > x) high = m - 1;
			else low = m + 1;
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for(pll curr : result)
		cout << curr.first << " " << curr.second << endl;
}
