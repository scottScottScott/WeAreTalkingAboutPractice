#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	int result = 0;
	for(int i = 0; i < n; i++) scanf("%d", &A[i]);
	ll curr, diff;
	bool cSet, dSet;
	cSet = dSet = false;
	int i = 0;
	while(i < n) {
		if(A[i] == -1) {
			int start, end;
			start = end = i;
			while(end + 1 < n and A[end + 1] == -1) end++;
			ll length = end - start + 1;
			i = end + 1;
			if(cSet and dSet) {
				if(curr + length * diff > 0) 
					curr += diff * length;
				else {
					diff *= -1;
					length -= curr / diff;
					length += (curr % diff == 0);
					cSet = dSet = false;
				}
			}

			if(cSet and !dSet) {
				dSet = true;
				if(i != n and (A[i] - curr) % (length + 1) == 0) { 
					diff = (A[i] - curr) / (length + 1);
					curr = A[i] - diff;
				}
				else diff = 0;
			}
			else if(!cSet and !dSet) {
				result++;
				cSet = dSet = true;
				int j = i + 1;
				while(j < n and A[j] == -1) j++;
				if(j >= n) break;
				diff = (A[j] - A[i]) / (j - i);
				if( ((A[j] - A[i]) % (j - i)) == 0 and A[i] - diff * length > 0)
					curr = A[i] - diff;
				else {
					curr = A[i];
					diff = 0;
				}
			}
		}
		else if(!cSet or curr + diff != A[i]) {
			curr = A[i++];
			result++;
			dSet = false;
			cSet = true;
			if(i < n and A[i] != -1) {
				diff = A[i] - A[i - 1];
				curr = A[i++];
				dSet = true;
			}
		}
		else curr = A[i++];
	}
	cout << result << endl;
}
