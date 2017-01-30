#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int N;
	ll X;
	cin >> N >> X;
	int unhappy = 0;
	while(N--) {
		char C;
		ll D;
		cin >> C >> D;
		if(C == '+') X += D;
		else if(C == '-') {
			if(X < D) unhappy++;
			else X -= D;
		}
	}	
	cout << X << " " << unhappy << endl;
}
