#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
	string n;
	int m;
	cin >> n >> m;
	vector<map<ll, ll>> memo(m);
	memo[0][0] = 1;
	ll result = 0;
	int size = n.size();
	sort(n.begin(), n.end());
	int mod_base = 1;
	for(int i = size - 1; i >= 0; i--) {
		vector<map<ll, ll>> n_memo(m);
		for(int R = 0; R < m; R++) {
			for(pll curr : memo[R]) {
				ll val = curr.first;
				ll count = curr.second;
				for(int j = 0; j < size; j++) {
					if(i == 0 and n[j] == '0') continue;
					ll check = 1ll << j;
					if(val & check) continue;
					if(j != 0 and n[j - 1] == n[j] and !(val & (1ll << (j - 1)))) continue;
					ll n_val = val | check;
					int mod = (R + mod_base * (n[j] - '0')) % m;
					n_memo[mod][n_val] += count;
					if(i == 0 and mod == 0)
						result += count;
				}
			}
		}
		memo = move(n_memo);
		mod_base = (mod_base * 10) % m;
	}	
	cout << result << endl;
}
