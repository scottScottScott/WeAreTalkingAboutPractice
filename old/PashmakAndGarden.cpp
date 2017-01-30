#include <iostream>

using namespace std;

int main() {
	int X1, Y1, X2, Y2;
	cin >> X1 >> Y1 >> X2 >> Y2;

	if(X1 == X2) {
		int diff = abs(Y2 - Y1);
		int X3 = X1 + diff;
		printf("%d %d %d %d\n", X3, Y1, X3, Y2);
	}
	else if(Y1 == Y2) {
		int diff = abs(X2 - X1);	
		int Y3 = Y1 + diff;
		printf("%d %d %d %d\n", X1, Y3, X2, Y3);
	}
	else {
		int diff1 = abs(X1 - X2);
		int diff2 = abs(Y1 - Y2);

		if(diff1 != diff2) cout << -1 << endl;
		else printf("%d %d %d %d\n", X1, Y2, X2, Y1);
	}
}
