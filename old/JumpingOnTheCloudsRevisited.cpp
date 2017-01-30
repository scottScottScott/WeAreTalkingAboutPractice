#include <vector>
#include <iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<bool> C(N);
	for(int i = 0; i < N; i++)
		cin >> C[i];

	int E = 100;
	int visit = 1;	
	int curr = 0;		
	while( E > 0 and !(curr == 0 and visit == 2) ) {
		curr = (curr + K) % N;
		E--;
		if(C[curr] == 1)
			E -= 2;
		if(curr == 0) visit++;
	}

	cout << E << endl;
}
