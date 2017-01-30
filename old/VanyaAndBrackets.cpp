#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	string s;
	cin >> s;
	int n = s.size();	
	int m = (n + 1) / 2;
	vector<vector<ll>> sum(2, vector<ll>(m));
	vector<vector<ll>> last(2, vector<ll>(m));
	vector<int> start{0, m - 1}; 
	vector<int> inc{1, -1};
	for(int a = 0; a < 2; a++) {
		ll total = 0;
		for(int i = start[a]; i >= 0 and i <= m - 1; i += inc[a]) {
			int j = i * 2;
			if(i == start[a] or s[j - inc[a]] == '+') {
				total += (i != start[a] ? last[a][i - inc[a]] : 0);
				last[a][i] = s[j] - '0';
			}
			else
				last[a][i] = last[a][i - inc[a]] * (s[j] - '0');
			sum[a][i] = total;
		}
	}
	ll result = sum[0][m - 1] + last[0][m - 1];

	for(int i = 0; i < n; i++) {
		if(s[i] == '*') {
			int next = (i + 1) / 2;
			vector<int> start{i + 1, i - 1};
			vector<int> other{next - 1, next};
			for(int a = 0; a < 2; a++) {
				ll mid = 0;
				ll l = 0;
				for(int j = start[a]; j < n and j >= 0; j += inc[a]) {
					if(j % 2 == 0) {
						if(j == start[a] or s[j - inc[a]] == '+') {
							l = s[j] - '0';
							mid += l;
						}
						else {
							mid -= l;
							l *= s[j] - '0';
							mid += l;
						}
					}
					if(s[j] == '*') {
						ll currval = sum[!a][(j + !a) / 2];
						ll currlast = last[!a][(j + !a) / 2];
						result = max(result, sum[a][other[a]] + last[a][other[a]] * mid * currlast + currval);
					}
				}
				result = max(result, sum[a][other[a]] + last[a][other[a]] * mid);
			}
		}
	}
	cout << result << endl;
}
