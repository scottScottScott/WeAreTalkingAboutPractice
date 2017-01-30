#include <iostream>
#include <string>

using namespace std;

string simplify(string x) {
	string result;
	int n = x.size();
	if(n % 2 == 0) {
		string a = simplify(x.substr(0, n / 2));
		string b = simplify(x.substr(n / 2, n / 2));
		if(a < b) result = a + b;
		else result = b + a;
	}
	else
		result = x;
	return result;
}

int main() {
	string a, b;
	cin >> a >> b;
	string x = simplify(a);
	cout << (simplify(b) == x ? "YES" : "NO") << endl;
}
