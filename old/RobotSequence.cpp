#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<char> commands(N);
	for(int i = 0; i < N; i++) {
		cin >> commands[i];
	}	

	int count = 0;
	
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {

			int Y = 0;
			int X = 0;
			
			for(int k = i; k <= j; k++) {
				switch(commands[k]) {
					case 'U':
						Y++;	
						break;
					case 'D':
						Y--;
						break;
					case 'R':
						X++;
						break;
					case 'L':
						X--;
						break;
				}
			}

			if(Y == 0 and X == 0)
				count++;
		}
	}

	cout << count << endl;
}
