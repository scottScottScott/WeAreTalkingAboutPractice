#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	set<char> V {'I', 'E', 'A', 'O', 'U', 'Y'};
	string S;	
	cin >> S;
	int n = S.size();
	vector<int> sum(n);
	for(int i = 0; i < n; i++) {
		if(i != 0) 
			sum[i] = sum[i - 1];
		char curr = S[i];
		if(V.count(curr)) 
			sum[i]++; 
	}
	double total = 0;
	ll extra = 0;
	for(int length = 1; 2 * length <= n + 1; length++) {
		ll temp = sum[n - length] - (length - 2 >= 0 ? sum[length - 2] : 0);
		total += (double) (temp * length + extra) / length;	
		if(2 * length <= n)
			total += (double) (temp * length + extra) / (n - length + 1);
		extra += ( V.count(S[length - 1]) + V.count(S[n - length]) ) * length;
	}
	printf("%f\n", total);
}
