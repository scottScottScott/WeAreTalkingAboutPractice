#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
	map<pll, ll> M; 	
	int q;
	cin >> q;
	while(q--) {
		int type;
		ll v, u;
		cin >> type >> v >> u;
		if(type == 1) {
			int w;
			cin >> w;
			vector<ll> temp{u, v};
			sort(temp.begin(), temp.end());
			while(temp[0] != temp[1]) {
				ll next = temp[1] / 2;	
				M[make_pair(temp[1], next)] += w;
				temp[1] = next;
				sort(temp.begin(), temp.end());
			}
		}
		else {
			ll result = 0;
			vector<ll> temp{u, v};
			sort(temp.begin(), temp.end());
			while(temp[0] != temp[1]) {
				ll next = temp[1] / 2;	
				result += M[make_pair(temp[1], next)];
				temp[1] = next;
				sort(temp.begin(), temp.end());
			}
			cout << result << endl;
		}
	}
}
