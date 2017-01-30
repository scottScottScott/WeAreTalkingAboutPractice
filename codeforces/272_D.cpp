#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	cout << k * (n * 6 - 1) << endl;
	for(int i = 0; i < n; i++) {
		int base = i * 6;
		printf("%d %d %d %d\n", k * (base + 1), k * (base + 2), k * (base + 3), k * (base + 5) );
	}
}
