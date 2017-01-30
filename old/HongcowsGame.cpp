#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n;
void query(vector<int> &Q, vector<int> &A) {
	int nQ = Q.size();
	cout << nQ << endl;	
	for(int i = 0; i < nQ; i++)	cout << Q[i] << (i + 1 == nQ ? "\n" : " ");
	cout << flush;

	A.clear();	
	A.resize(n);
	for(int i = 0; i < n; i++) scanf("%d", &A[i]);
}

int main() {
	cin >> n;
	int Q = 0;	
	while(pow(2, Q) < n) Q++;		
	vector<int> M(n, 2e9);
	for(int q = 0; q < Q; q++) {
		int bSize = pow(2, q);
		vector<int> t1, t2, inB(n), a1(n), a2(n);
		bool isB = true;
		int count = 0;
		for(int i = 0; i < n; i++) {
			if(count == bSize) {
				count = 0;
				isB = !isB;
			}
			if(isB) t1.push_back(i + 1);	
			else t2.push_back(i + 1);
			inB[i] = isB;
			count++;
		}
		query(t1, a1); 
		query(t2, a2);
		for(int i = 0; i < n; i++) M[i] = min(M[i], inB[i] ? a2[i] : a1[i]); 	
	}
	cout << -1 << endl;
	for(int i = 0; i < n; i++)
		 cout << M[i] << (i + 1 == n ? "\n" : " ");
	cout << flush;
}
