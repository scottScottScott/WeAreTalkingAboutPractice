#include <iostream>
#include <string>

using namespace std;

int main() {
	string S;
	cin >> S;
	int n = S.size();
	int result = 0;
	int i = 0;
	int prevM = 0;
	while(i < n) {
		if(S[i] == 'F')
			i++;
		else {
			int prep = 0;
			int real = 0;
			while(i < n and S[i] == 'M') {
				prep++;
				i++;
			}
			while(i < n and S[i] == 'F') {
				real++;		
				i++;
			}
			if(real == 0) break;

			if(result == 0) {
				result = prep + real - 1;
				prevM += prep;
				continue;
			}
			else if(result < prep + prevM - 1)
				result = prep + prevM - 1;
			result += real;
			prevM += prep;
		}
	}
	cout << result << endl;
}
