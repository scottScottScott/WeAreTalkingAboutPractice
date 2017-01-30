#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, w;
	cin >> n >> w;
	vector<int> A(n);
	vector<int> B(w);
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for(int i = 0; i < w; i++)
		scanf("%d", &B[i]);

	if(w == 1) {
		cout << n << endl;
		return 0;
	}

	vector<int> z;	
	for(int i = 1; i < w; i++)
		z.push_back(B[i] - B[i - 1]);		
	z.push_back(2e9);
	for(int i = 1; i < n; i++)
		z.push_back(A[i] - A[i - 1]);

	int z_size = z.size();
	vector<int> memo(z_size);
	memo[0] = z_size;
	int l, r;
	l = r = -1;
	for(int i = 1; i < z_size; i++) {
		if(i >= r) {
			r = l = i;
			while(r < z_size and z[r] == z[r - l])
				r++;
			memo[i] = r - l;	
		}
		else {
			int val = memo[i - l];
			if(i + val >= r) {
				l = i;
				while(r < z_size and z[r] == z[r- l])
					r++;
				memo[i] = r - l;
			}
			else
				memo[i] = val;
		}
	}

	int result = 0;
	for(int i = 1; i < z_size; i++) {
		if(memo[i] == w - 1)
			result++;
	}
	cout << result << endl;
}
