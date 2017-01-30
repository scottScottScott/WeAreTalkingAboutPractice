#include <iostream>

using namespace std;

int main() {
	int t, s, x;
	cin >> t >> s >> x;

	if(x < t) {
		cout << "NO" << endl;
		return 0;
	}
	x -= t;
	cout << (x % s == 0 or (x != 1 and x % s == 1) ? "YES" : "NO") << endl;
}
