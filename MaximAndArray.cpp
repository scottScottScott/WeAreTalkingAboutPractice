#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <deque>

using namespace std;

typedef long long ll;

int main() {
	int n, k, x;	
	cin >> n >> k >> x;
	map<ll, deque<int>> M;
	vector<bool> isNeg(n);
	bool oddNeg = 0;
	for(int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if(temp < 0) {
			oddNeg = !oddNeg;
			isNeg[i] = 1;
			temp *= -1;
		}
		M[temp].push_back(i);
	}
	while(!oddNeg and k > 0) {
		k--;
		auto &p = *M.begin();
		ll val = p.first;
		int currIdx = p.second.front();
		p.second.pop_front();
		if(p.second.empty())
			M.erase(val);
		val -= x;
		if(val < 0) {
			val *= -1;
			isNeg[currIdx] = !isNeg[currIdx];
			oddNeg = !oddNeg;
			M[val].push_back(currIdx);
		}
		else
			M[val].push_back(currIdx);
	}
	while(k-- > 0) {
		auto &p = *M.begin();
		ll val = p.first;
		int currIdx = p.second.front();
		p.second.pop_front();
		if(p.second.empty())
			M.erase(val);
		val += x;
		M[val].push_back(currIdx);
	}
	
	vector<ll> A(n);
	for(auto p : M) {
		for(int idx : p.second) {
			A[idx] = p.first;
			if(isNeg[idx])
				A[idx] *= -1;
		}
	}

	for(int i = 0; i < n; i++) {
		printf("%I64d", A[i]);
		printf(i + 1 != n ? " " : "\n");
	}
}
