#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> P, R;

int parent(int i) {
	if(i == -1) return -1;
	if(P[i] != i)
		P[i] = parent(P[i]);
	return P[i];
}

void merge(int A, int B) {
	if(A == -1 or B == -1) return;
	if(R[A] >= R[B]) {
		P[B] = A;
		if(R[A] == R[B])
			R[A]++;
	}
	else
		P[A] = B;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m, q;	
	cin >> n >> m >> q;
	unordered_map<string, int> M;
	for(int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		M[temp] = i;
	}
	vector<int> B(n, -1);
	P.resize(n);
	R.resize(n, 1);
	for(int i = 0; i < n; i++) P[i] = i;
	for(int i = 0; i < m; i++) {
		int t;
		string w1, w2;
		cin >> t >> w1 >> w2;
		int i1 = parent(M[w1]); 
		int j1 = B[i1];
		int i2 = parent(M[w2]);
		int j2 = B[i2];
		bool valid = true;
		if(t == 1) {
			if(i2 == B[i1])
				valid = false;
			else {
				merge(i1, i2);
				merge(j1, j2);
				i1 = parent(i1);
				j1 = parent(j1);
				if(j1 == -1) j1 = j2;
				if(j1 != -1) {
					B[i1] = j1;
					B[j1] = i1;
				}
			}
		}	
		else {
			if(i1 == i2)
				valid = false;
			else {
				merge(i1, j2);
				merge(i2, j1);
				i1 = parent(i1);
				i2 = parent(i2);
				B[i1] = i2;
				B[i2] = i1;
			}
		}
		printf("%s\n", valid ? "YES" : "NO");
	}
	for(int i = 0; i < q; i++) {
		string w1, w2;
		cin >> w1 >> w2;
		int i1 = parent(M[w1]);
		int i2 = parent(M[w2]);
		int result = 3;
		if(i1 == i2)
			result = 1;	
		else if(i1 == B[i2])
			result = 2;
		printf("%d\n", result);
	}
}
