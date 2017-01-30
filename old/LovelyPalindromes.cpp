#include <iostream>
#include <string>

using namespace std;

int main() {
	string S;
	cin >> S;
	int N = S.size();
	for(int i = N - 1; i >= 0; i--) 
		S += S[i];
	cout << S << endl;
}
