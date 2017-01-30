#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int n, m;
	ll k;
	cin >> n >> m >> k;
	ll lo = 1;
	ll hi = (ll) n * m;
	while(lo <= hi) {
		ll mid = lo + (hi - lo) / 2;
		ll below = 0;
		ll same = 0;
		for(int i = 1; i <= m; i++) {
			below += min( (ll) n, mid / i);	
			if(mid % i == 0 and (mid / i) <= n) {
				same++;
				below--;
			}
		}
		if(below < k and below + same >= k) {
			cout << mid << endl;
			return 0;
		}
		else if(below >= k) hi = mid - 1;
		else lo = mid + 1;
	}
}
