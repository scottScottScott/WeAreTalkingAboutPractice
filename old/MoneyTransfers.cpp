#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll> banks(n);
	for(int i = 0; i < n; i++)
		scanf("%I64d", &banks[i]);
	map<ll, int> M;	
	int result = 0;
	for(int i = 0; i < n; i++) {
		if(i != 0) banks[i] += banks[i - 1];	
		result = max(result, ++M[banks[i]]);
	}
	cout << n - result << endl;	
}
