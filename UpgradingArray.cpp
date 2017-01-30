#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>

using namespace std;

void getGCD(int i, vector<int> &prev, vector<int> &curr, vector<int> &d) {
	int k = 0;
	for(int j = 0; j < prev.size(); j++) {
		while(k < d.size() and d[k] < prev[j]) k++;
		if(k < d.size() and d[k] == prev[j]) {
			k++;
			curr.push_back(prev[j]);
		}
	}
} 

int main() {
	int n, m;	
	cin >> n >> m;
	vector<int> A(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	unordered_set<int> B;
	for(int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		B.insert(temp);
	}

	vector<vector<int>> D1(n), D2(n);
	int result = 0;
	for(int i = 0; i < n; i++) {
		int temp = A[i];
		int root = sqrt(temp);
		for(int j = 2; j <= root; j++) {
			while(temp % j == 0) {
				temp /= j;	
				if(B.count(j)) D2[i].push_back(j);
				else D1[i].push_back(j);
				root = sqrt(temp);
			}
		}
		if(temp != 1) {
			if(B.count(temp)) D2[i].push_back(temp);
			else D1[i].push_back(temp);
		}
		result += D1[i].size() - D2[i].size();
	}

	vector<vector<int>> gcd1(n), gcd2(n);
	for(int i = 0; i < n; i++) {
		if(i == 0) {
			gcd1[i] = D1[i];
			gcd2[i] = D2[i];
		}
		else {
			getGCD(i, gcd1[i - 1], gcd1[i], D1[i]);
			getGCD(i, gcd2[i - 1], gcd2[i], D2[i]);
		}
	}
	int seen1 = 0, seen2 = 0;
	for(int i = n - 1; i >= 0; i--) {
		int s1 = gcd1[i].size() - seen1;
		int s2 = gcd2[i].size() - seen2;
		if(s2 - s1 > 0) {
			result += (s2 - s1) * (i + 1);
			seen1 += s1;
			seen2 += s2;
		}
	}
	cout << result << endl;
}
