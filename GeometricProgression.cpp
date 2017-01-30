#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, K;
vector<int> A;

int main() {
	cin >> N >> K;
	A.resize(N);	
	for(int i = 0; i < N; i++)
		cin >> A[i];
	map<long long, int> F, B;	
	for(int i = 0; i < N; i++)
		B[A[i]]++;
	long long count = 0;
	for(int i = 0; i < N - 1; i++) {
		B[A[i]]--;
		long long curr = A[i];
		long long fst = F[curr / K];
		long long snd = B[curr * K];
		F[A[i]]++;
		if(curr % K != 0) continue;
		count += fst * snd;
	}
	cout << count << endl;
}
