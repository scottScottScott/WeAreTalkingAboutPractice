#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
const ll MAX = 1e18;

int main() {
	ll n;
	string k;
	cin >> n >> k;
	ll result = 0;	
	
	ll pos = 1;
	ll curr = 0;
	ll P = 1;
	int i = 0;
	reverse(k.begin(), k.end());
	while(i < k.size()) {
		int j = i;
		ll next = curr + (k[j] - '0') * P;
		while(k[j] == '0' and j + 1 < k.size()) {
			j++;
			P *= 10;
			next += (k[j] - '0') * P;
			if(P >= MAX) break;
		}

		if(next < n and k[j] != '0') {
			curr = next;
			P *= 10;
			i = j + 1;
		}
		else {
			if(curr == 0) i++;
			result += curr * pos;
			curr = 0;
			P = 1;
			pos *= n;
		}
	}
	result += curr * pos;
	cout << result << endl;
}
