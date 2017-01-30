#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll d, k, a, b, t;
	cin >> d >> k >> a >> b >> t;
	ll time = 0;
	time += a * min(k, d);
	d -= min(k, d);
	if(t + a * k <= b * k) {
		ll repeat = d / k;
		time += (t + a * k) * repeat;
		d -= repeat * k;
		if(t + a * d <= b * d) {
			time += (t + a * d);
			d -= d;
		}
	}
	time += d * b;
	cout << time << endl;
}
