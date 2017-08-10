#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
	int n, k, m;
	cin >> n >> k >> m;
	vvi memo(n, vi(k));
	vector<ll> prefix(n);
	for(int i = n - 1; i >= 0; i--) {
		if(i == n - 1) 
			prefix[i] = 1;
		else if(i == n - 2) 
			prefix[i] = 9;
		else 
			prefix[i] = prefix[i + 1] * 10 % m;
	}
	int base = 1;
	ll result = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 1; j <= 9; j++) {
			int temp = (base * j) % k;
			if(i == 0) 
				memo[0][temp]++;
			else {
				for(int a = 0; a < k; a++) { 
					memo[i][(temp + a) % k] += memo[i - 1][a];
					memo[i][(temp + a) % k] %= m;
				}
			}
		}
		result = (result + memo[i][0] * prefix[i]) % m;
		memo[i][0] = 0;
		if(i == 0)
			memo[i][0] = 1;
		else {
			for(int a = 0; a < k; a++) { 
				memo[i][a] += memo[i - 1][a];
				memo[i][a] %= m;
			}
		}
		base = (10 * base) % k; 		
	}
	cout << result << endl;
}
