#include <iostream>
#include <string>

using namespace std;

int main() {
	int N, D;
	cin >> N >> D;
	int result = 0;
	int count = 0;
	for(int i = 0; i < D; i++) {
		string S;
		cin >> S;
		int j = 0;
		for( ; j < N; j++)
			if(S[j] == '0') break;

		if(j == N)
			count = 0;
		else {
			count++;
			result = max(result, count);
		}
	}
	cout << result << endl;
}
