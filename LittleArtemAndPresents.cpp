#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int answer = (N / 3) * 2;
	if(N % 3 == 1 or N % 3 == 2) 
		answer++;
	cout << answer << endl;
}
