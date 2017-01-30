#include <iostream>
#include <utility>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> pii;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;
	ll total = 1;
	map<int, int> M;
	for(int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		M[temp]++;
		total = (total * temp) % MOD;
	}

	bool isSquare = true;
	bool divide = false;
	ll power = 1;
	int B = (MOD / 2) + 1;
	int key = -1;
	for(pii X : M) {
		if(X.second % 2 == 1) {
			if(key == -1) key = X.first;
			isSquare = false;
		}
	}

	if(isSquare) {
		total = 1;
		for(pii X : M) {
			for(int i = 0; i < X.second / 2; i++)
				total = (total * X.first) % MOD;
		}
	}

	for(pii X : M) {
		int curr = X.second + 1;
		if(X.first == key) curr /= 2;
		power = (power * curr) % (MOD - 1);
	}

	ll currPower = 1;	
	ll currVal = total;
	vector<ll> P{currVal};
	while(currPower * 2 <= power) {
		currPower *= 2;
		currVal = (currVal * currVal) % MOD;
		P.push_back(currVal);
	}
	
	total = 1;
	for(int i = P.size() - 1; i >= 0; i--) {
		int temp = power / currPower;
		assert(temp == 0 or temp == 1);
		if(temp == 1) {
			total = (P[i] * total) % MOD;
			power -= currPower;
		}
		currPower /= 2;
	}

	cout << total << endl;
}
