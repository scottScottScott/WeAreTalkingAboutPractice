#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int minA, maxA, minB;
	for(int i = 0; i < N; i++) {
		int A;
		cin >> A;
		if(i == 0) minA = maxA = A;
		else {
			minA = min(minA, A);
			maxA = max(maxA, A);	
		}
	}	
	for(int i = 0; i < M; i++) {
		int B;
		cin >> B;
		if(i == 0) minB = B;
		else minB = min(minB, B);
	}
	
	int V = max(maxA, minA * 2);		
	cout << (V >= minB ? -1 : V) << endl;
}
