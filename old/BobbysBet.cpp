#include <iostream>
#include <cmath>

using namespace std;

int factorial(int X) {
	if(X == 0)
		return 1;
	return X * factorial(X - 1);
}

int choose(int Y, int X) {
	return factorial(Y) / (factorial(X) * factorial(Y - X));
}

int main() {
	int N;	
	cin >> N;
	while(N--) {
		double R, S, X, Y, W; 
		cin >> R >> S >> X >> Y >> W;
			
		double EV = 0;
		for( ; X <= Y; X ++) {
			EV += choose(Y, X) * pow((S - R + 1) / S, X) * pow((R - 1) / S, Y - X);
		}
		EV *= W;
		cout << (EV > 1 ? "yes" : "no") << endl;
	}
}
