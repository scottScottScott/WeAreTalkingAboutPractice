#include <iostream>

using namespace std;

int main() {
	int n, b, d;
	cin >> n >> b >> d;
	int result = 0;
	int curr = 0;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if(a > b) continue;
		curr += a;
		if(curr > d) {
			curr = 0;
			result++;
		}
	}
	cout << result << endl;
}
