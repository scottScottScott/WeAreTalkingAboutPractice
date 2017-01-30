#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
	int n, l, x, y;
	cin >> n >> l >> x >> y;
	vector<int> A(n);
	unordered_set<int> S;
	for(int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		S.insert(A[i]);
	}
	int result = 0;	
	vector<int> P;
	bool xe = false, ye = false;
	for(int a : A) {
		if(S.count(a + x)) xe = true;
		if(S.count(a + y)) ye = true;
	}

	if(!xe and !ye) {
		bool found = false;
		for(int a : A) {
			for(int mark : vector<int> {a + x, a - x}) {
				if(mark >= 0 and mark <= l and (S.count(mark - y) or S.count(mark + y))) {
					result = 1;
					P.push_back(mark);
					found = true;
					break;
				}
			}
			if(found)
				break;
		}
		if(!found) {
			result = 2;
			P.push_back(x);
			P.push_back(y);
		}
	}
	else if(!xe or !ye) {
		result = 1;
		P.push_back(xe ? y : x);
	}
	cout << result << endl;
	for(int i = 0; i < P.size(); i++)
		cout << P[i] << (i + 1 != P.size() ? " " : "");
	cout << endl;
}
