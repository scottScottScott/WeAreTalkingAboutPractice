#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265
#define EPS 1e-7

int main() {
	int n, R, r;
	cin >> n >> R >> r;

	if(n == 1) {
		cout << (r <= R ? "YES" : "NO") << endl;
		return 0;
	}
	if(n == 2) {
		cout << (2 * r <= R ? "YES" : "NO") << endl;
		return 0;
	}

	double angle = (2 * PI) / n;
	int A = R - r;
	double side3 = sqrt((2 * A * A) * (1 - cos(angle)));
	
	if(2 * r > side3 + EPS)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}
