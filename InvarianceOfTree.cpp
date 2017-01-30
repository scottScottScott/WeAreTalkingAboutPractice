#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int n;
	cin >> n;
	vector<int> P(n + 1);
	for(int i = 1; i <= n; i++)
		scanf("%d", &P[i]);
	vector<pii> C;
	vector<bool> S(n + 1);
	for(int i = 1; i <= n; i++) {
		if(S[i]) continue;
		int length = 1;
		int next = i;
		S[next] = 1;
		while(P[next] != i) {
			length++;
			next = P[next];
			S[next] = 1;
		}
		C.emplace_back(length, i);	
	}
	sort(C.begin(), C.end());
	
	if(C[0].first == 1) {
		cout << "YES" << endl;
		int pivot = C[0].second;
		for(int i = 1; i <= n; i++) {
			if(i == pivot) continue;
			printf("%d %d\n", i, pivot);
		}
		return 0;
	}
	if(C[0].first == 2) {
		bool valid = true;
		for(int i = 1; i < C.size(); i++) {
			if(C[i].first % 2 == 0)
				continue;
			else
				valid = false;
		}
		if(valid) {
			cout << "YES" << endl;
			cout << C[0].second << " " << P[C[0].second] << endl;
			for(int i = 1; i < C.size(); i++) {
				int A = C[0].second;
				int B = C[i].second;
				cout << A << " " << B << endl;
				A = P[A], B = P[B];
				while(!(A == C[0].second and B == C[i].second)) {
					printf("%d %d\n", A, B);
					A = P[A], B = P[B];
				}
			}	
			return 0;
		}
	}
	cout << "NO" << endl;
}
