#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int gcd(int A, int B) {
	if(B == 0) return A;
	return gcd(B, A % B);
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N * N);
	for(int i = 0; i < N * N; i++)
		scanf("%d", &A[i]);
	map<int, int> M;
	sort(A.begin(), A.end());
	vector<int> result;
	while(result.size() != N) {
		int temp;
		while(!A.empty()) {
			temp = A.back();
			A.pop_back();	
			if(M[temp] == 0) break;
			else M[temp]--;
		}
		for(int x : result)
			M[gcd(x, temp)] += 2;	
		result.push_back(temp);
	}
	
	for(int i = 0; i < N; i++) {
		cout << result[i];
		if(i + 1 != N) cout << " ";
		else cout << endl;	
	}
}
