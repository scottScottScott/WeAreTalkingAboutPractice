#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A(n), B(n), V;
	for(int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		int x = A[i];
		int idx = lower_bound(V.begin(), V.end(), x) - V.begin();
		if(V.empty() or x > V.back())
			V.push_back(x);
		else if(idx < V.size())
			V[idx] = x;
		B[i] = lower_bound(V.begin(), V.end(), x) - V.begin() + 1;
	}
	vector<int> result(n, 1);
	int maxVal = *max_element(B.begin(), B.end());
	vector<vector<int>> info(maxVal + 2);
	for(int i = 0; i < n; i++)
		info[B[i]].push_back(i);
	for(int i = maxVal; i > 0; i--) {
		vector<int> &prev = info[i + 1];
		vector<int> &temp = info[i];
		vector<int> valid;
		set<int> S;
		int idx = prev.size() - 1;
		for(int j = temp.size() - 1; j >= 0; j--) {
			int x = temp[j];
			if(i == maxVal) {
				valid.push_back(x);
				continue;
			}
			while(idx >= 0 and prev[idx] > x)
				S.insert(A[prev[idx--]]);
			auto itr = S.upper_bound(A[x]);
			if(itr != S.end())
				valid.push_back(x);
		}
		reverse(valid.begin(), valid.end());
		info[i] = valid;
		for(int x : valid) 		
			result[x] = (valid.size() == 1 ? 3 : 2);
	}
	for(int i = 0; i < n; i++)
		cout << result[i];
	cout << endl;
}
