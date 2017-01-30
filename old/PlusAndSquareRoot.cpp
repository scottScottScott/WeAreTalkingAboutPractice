#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	
	for(ll k = 1; k <= n; k++) {
		if(k == 1) {	
			cout << 2 << endl;
			continue;
		}
		ll goal = (k + 1) * (k + 1) * k;	
		ll result = goal - (k - 1);	
		cout << result << endl;
	}
}
