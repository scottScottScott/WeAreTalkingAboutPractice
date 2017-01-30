#include <iostream>

using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	int temp = (A + (B % N) + N) % N;
	cout << (temp != 0 ? temp : N) << endl;
}
