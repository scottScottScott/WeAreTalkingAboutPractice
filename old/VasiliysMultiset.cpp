#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
	set<int> S;
	map<int, int> M;
	int q;
	cin >> q;
	string eat;
	getline(cin, eat);
	for(int i = 0; i < q; i++) {
		char type;
		int x;
		scanf("%c %d\n", &type, &x);
		if(type == '+') {
			M[x]++;
			S.insert(x);
		}	
		else if(type == '-') {
			M[x]--;
			if(M[x] == 0)
				S.erase(x);
		}
		else if(type == '?') {
			if(S.empty()) {
				cout << x << endl;
				continue;
			}

			int low = 0;
			int high = INT_MAX;
			int result = x;
			for(int j = 30; j >= 0; j--) {
				int temp = 1 << j;	
				if( (x & temp) != 0 ) {
					high -= temp;
					if(*S.lower_bound(low) > high) {
						low += temp;
						high += temp;
					}
				}
				else {
					low += temp;
					if(S.lower_bound(low) == S.end() or *S.lower_bound(low) > high) {
						low -= temp;
						high -= temp;
					}
				}
			}
			result = max(result, x ^ high);
			cout << result << endl;
		}
	}
}
