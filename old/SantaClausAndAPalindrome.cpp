#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int k, n;
	cin >> k >> n;
	map<string, vector<int>> M;
	while(k--) {
		string S;
		int val;
		cin >> S >> val;	
		M[S].push_back(val);
	}
	int center = 0;
	ll result = 0;
	for(auto &P : M) {
		string S = P.first;
		vector<int> &V = P.second;
		sort(V.rbegin(), V.rend());
		string oS = S;
		reverse(oS.begin(), oS.end());
		int i = 0;
		if(oS == S) {
			while(i + 1 < V.size() and V[i] + V[i + 1] > 0) {
				result += V[i] + V[i + 1];
				center = max(center, -V[i + 1]);
				i += 2;
			}
			if(i < V.size())
				center = max(center, V[i]);
		}
		else if(S < oS) {
			vector<int> &W = M[oS];	
			sort(W.rbegin(), W.rend());
			while(i < V.size() and i < W.size() and V[i] + W[i] > 0) {
				result += V[i] + W[i];
				i++;
			}
		}
	}
	result += center;	
	cout << result << endl;
}
