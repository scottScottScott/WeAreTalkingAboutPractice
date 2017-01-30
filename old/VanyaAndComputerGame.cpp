#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	int n;
	ll x, y;
	cin >> n >> x >> y;
	ll total = x + y;
	while(n--) {
		ll curr;
		cin >> curr;
		curr = curr % total;
		if(curr == 0) {
			printf("Both\n");
			continue;
		}
		ll low = 1;
		ll high = x * y; 
		while(low <= high) {
			ll mid = low + (high - low) / 2;
			ll count = (mid / y) + (mid / x);
			if(count == curr or (count == curr + 1 and mid % x == 0 and mid % y == 0)) {
				ll last_1 = (mid / y) * y;
				ll last_2 = (mid / x) * x;
				if(last_1 == last_2) printf("Both\n");
				else if(last_1 > last_2) printf("Vanya\n");
				else printf("Vova\n");
				break;
			}
			else if(count > curr)
				high = mid - 1;
			else 
				low = mid + 1;
		}
	}
}
