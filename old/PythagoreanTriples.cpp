#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
	ll n;
	cin >> n;

	if(n <= 2) 
		cout << -1 << endl;
	else if (n % 2 == 0) {
		ll a = n / 2;
		cout << a * a - 1 << " " << a * a + 1 << endl;		
	}
	else {
		ll a = (n * n - 1) / 2;
		ll b = (n * n + 1) / 2;
		cout << a << " " << b << endl;
	}
}
