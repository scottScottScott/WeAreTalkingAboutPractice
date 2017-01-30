#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int BASE = 1e9 + 7;
typedef long long ll;

bool same(string &A, string &B) {
	if(A.size() != B.size()) return false;
	int diff = 0;
	for(int i = 0; i < A.size(); i++)
		if(A[i] != B[i])
			diff++;
	return diff == 1;
}

int hash_it(string &temp) {
	int N = temp.size();
	ll val = 0;
	ll mult = 1;
	for(int i = 0; i < N; i++) {
		int z = temp[i] - 'a';
		val += mult * z;
		val %= BASE;
		mult *= 10;
		mult %= BASE;
	}
	return val;
}

int main() {
	int n, m;
	cin >> n >> m;
	map<int, vector<string>> M;
	for(int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		int val = hash_it(temp);
		M[val].push_back(temp);	
	}	
	for(int i = 0; i < m; i++) {
		string temp;	
		cin >> temp;	
		int N = temp.size();
		ll total = 0;
		ll curr = 1;		
		vector<int> A(N);
		for(int j = 0; j < N; j++) {
			int z = temp[j] - 'a';
			total += curr * z;
			total %= BASE;
			A[j] = curr;
			curr *= 10;
			curr %= BASE;
		}
		bool found = false;
		for(int j = 0; j < N; j++) {
			int z = temp[j] - 'a';
			for(int k = 0; k < 3; k++) {
				if(z == k) continue;
				ll val = total - (A[j] * z) % BASE + (A[j] * k) % BASE;
				val = (val + BASE) % BASE;
				for(string &w : M[val]) {
					if(same(temp, w)) {
						found = true;
						break;
					}
				}
				if(found) break;
			}
			if(found) break;
		}
		printf(found ? "YES\n" : "NO\n");
	}
}
