#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long L, R, K;
	cin >> L >> R >> K;
	long long upperBound = R / K;
	long long curr = 1;
	bool first = true;
	while(true) {
		if(curr >= L) {
			if(!first) cout << " ";
			first = false;
			cout << curr;
		}
		if(curr > upperBound) break;
		curr *= K;
	}
	if(first) cout << -1;
	cout << endl;
}
