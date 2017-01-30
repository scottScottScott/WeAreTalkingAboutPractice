#include <iostream>
#include <string>

using namespace std;

int main() {
	int N, K;
	string S;
	cin >> N >> K >> S;
	
	int maxL = 0;
	for(int t = 0; t < 2; t++) {
		int changes = 0;
		int fst_change = 0;
		int tempL = 0;
		for(int i = 0; i < N; i++) {
			if(S[i] == 'b') {
				tempL++;
				if(changes < K) {
					changes++;	
				}
				else if(changes == K) {
					while(S[fst_change] != 'b') {
						fst_change++;
						tempL--;
					}
					fst_change++;
					tempL--;
				}
			}
			else if(S[i] == 'a') tempL++; 	
			maxL = max(maxL, tempL);
		}

		for(char &X : S) {
			if(X == 'b') 
				X = 'a';	
			else if(X == 'a') 
				X = 'b';
		}
	}

	cout << maxL << endl;
}
