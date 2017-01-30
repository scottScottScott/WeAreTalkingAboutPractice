#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	bool good = false;
	while(N--) {
		string name;
		int A, B;
		cin >> name >> A >> B;
		if(A >= 2400 and B - A > 0)
			good = true;
	}
	cout << (good ? "YES" : "NO") << endl;
}
