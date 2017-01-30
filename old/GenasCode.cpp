#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	string S = "1"; 
	int count = 0;
	while(N--) {
		string X;
		cin >> X;

		if(X == "0") {
			cout << 0 << endl;
			return 0;
		}

		bool isSpecial = false;	
		for(int i = 0; i < X.size(); i++) {
			if(i == 0 and X[i] != '1') isSpecial = true;
			else if(i != 0 and X[i] != '0') isSpecial = true;
		}

		if(isSpecial) S = X;
		else count += X.size() - 1;
	}
	
	for(int i = 0; i < count; i++) S += "0";	
	cout << S << endl;	
}
