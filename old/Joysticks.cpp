#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int minutes = 0;
	while(a > 0 and b > 0 and !(a == 1 and b == 1)) {
		if(a < b) {
			a += 1;	
			b -= 2;
		}	
		else {
			b += 1;
			a -= 2;
		}
		minutes++;
	}
	cout << minutes << endl;
}
