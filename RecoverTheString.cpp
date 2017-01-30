#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int bsearch(int a) {
	if(a == 0) return 0;
	int lo = 0;
	int hi = 1e9;
	while(lo <= hi) {
		ll mid = lo + (hi - lo) / 2;
		ll val = mid * (mid - 1) / 2;
		if(val == a) 
			return mid;
		else if(val < a)
			lo = mid + 1;	
		else
			hi = mid - 1;
	}
	return -1;
}

bool possible(ll num_zero, ll num_one, ll a, ll b, ll c, ll d) {
	int n = num_zero + num_one;
	ll all = (ll) n * (n - 1) / 2;
	ll max = num_zero * num_one;
	if(b > max or (a + b + c + d != all) )
		return false;
	string solution;
	for(int i = 0; i < n; i++) {
		if(b >= num_one) {
			solution += '0';
			b -= num_one;	
			num_zero--;
		}
		else if(num_one > 0) {
			solution += '1';
			num_one--;	
		}
		else {
			solution += '0';
			num_zero--;
		}
	}
	if(solution.empty()) return false;
	else {
		cout << solution << endl;
		return true;
	}
}

int main() {
	string bad = "Impossible";
	ll a, b, c, d;	
	cin >> a >> b >> c >> d;
	int num_zero = bsearch(a);
	int num_one = bsearch(d);
	// cout << num_zero << " " << num_one << endl;
	if(num_zero == -1 or num_one == -1) {
		cout << bad << endl;
		return 0;
	}

	vector<int> first{num_zero};
	if(num_zero == 0) first.push_back(1);
	vector<int> second{num_one};
	if(num_one == 0) second.push_back(1);
	for(int x : first) {
		for(int y : second) {
			if(possible(x, y, a, b, c, d))
				return 0;
		}
	}
	cout << bad << endl;
}
