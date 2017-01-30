#include <iostream>

using namespace std;

int main() {
	int n, T;
	cin >> n >> T;
	
	int count = 0;
	while(n--) {
		int temp;
		cin >> temp;
		if( (T-=temp) >= 0) {
			count++;	
		}
		else 
			break;
	}

	cout << count << endl;
}
