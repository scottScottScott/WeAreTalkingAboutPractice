#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> a_count(2);
	vector<int> b_count(2);
	vector<ll> result(2);
	for(int i = 0; i < n; i++) {
		if(s[i] == 'a') a_count[i % 2]++;
		else b_count[i % 2]++;
	}
	for(int i = 0; i < n; i++) {
		if(s[i] == 'a') {
			result[1] += a_count[i % 2];
			result[0] += a_count[(i + 1) % 2];
			a_count[i % 2]--;
		}
		else {
			result[1] += b_count[i % 2];
			result[0] += b_count[(i + 1) % 2];
			b_count[i % 2]--;
		}
	}

	cout << result[0] << " " << result[1] << endl;
	return 0;
}
