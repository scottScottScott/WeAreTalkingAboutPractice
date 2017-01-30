#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> getFactors(int x) {
	vector<int> result;
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			result.push_back(i);
			while(x % i == 0) 
				x /= i;
		}	
	}
	if(x != 1) result.push_back(x);
	return result;
}

int main() {
	int n;
	cin >> n;
	vector<int> l(n);
	vector<int> c(n);
	vector<vector<int>> factors(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &l[i]);
		factors[i] = getFactors(l[i]);
	}
	for(int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	int result = -1; 
	for(int i = 0; i < n; i++) {
		map<int, int> memo;			
		map<int, int> M;
		int init = 0;
		for(int j = 0; j < factors[i].size(); j++) {
			M[factors[i][j]] = j;
			init |= (1 << j);
		}
		memo[init] = c[i];
		for(int j = 0; j < n; j++) {
			int curr = 0;
			for(int x : factors[j])
				if(M.count(x)) curr |= 1 << M[x];
			for(pair<int, int> x : memo) {
				int next = x.first & curr;
				if(memo.count(next)) memo[next] = min(memo[next], x.second + c[j]);
				else memo[next] = x.second + c[j];
			}
		}
		if(!memo.count(0)) continue;
		result = (result == -1 ? memo[0] : min(result, memo[0]));
	}
	cout << result << endl;
}
