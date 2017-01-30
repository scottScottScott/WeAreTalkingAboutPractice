#include <iostream>

using namespace std;

int main() {
	int N, H;
	cin >> N >> H;
	int width = 0;
	for(int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		width++;
		if(temp > H) width++;
	}
	cout << width << endl;
}
