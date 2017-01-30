#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

#define million 1000000

using namespace std;

void addBig(vector<int> &a, vector<int> &b) {
	int maxSize = max(a.size(), b.size());
	bool carryOver = false;

	for(int i = 0; i < maxSize; i++) {
		if(i >= a.size() || i >= b.size()) {
			if(i >= a.size()) 
				a.push_back(b[i]);
			if(carryOver) {
				a[i] += 1;
				carryOver = false;
			}
			if(a[i] > million) {
				carryOver = true;
				a[i] -= million;
			}
		}
		else {
			int sum = a[i] + b[i];
			if(carryOver) {
				sum += 1;
				carryOver = false;
			}
			if(sum > million) {
				carryOver = true;
				sum -= million;
			}
			a[i] = sum;
		}
	}

	if(carryOver) {
		a.push_back(1);
	}
}

int main() {
	ifstream fin("buylow.in");
	ofstream fout("buylow.out");

	int N;
	fin >> N;

	vector<int> prices(N);
	vector<int> memo(N);
	vector< vector<int> > occur(N);

	for(int i = 0; i < N; i++) {
		fin >> prices[i];
	}

	for(int i = N - 1; i >= 0; i--) {
		int maxLength = 0;
		for(int j = i + 1; j < N; j++) {
			if(prices[i] > prices[j]) {
				maxLength = max(maxLength, memo[j]);
			}
		}
		set<int> distinct;
		for(int j = i + 1; j < N; j++) {
			if(prices[i] > prices[j] and memo[j] == maxLength) {
				if(!distinct.count(prices[j])) {
					addBig(occur[i], occur[j]);
					distinct.insert(prices[j]);
				}
			}
		}
		memo[i] = maxLength + 1;
		if(occur[i].size() == 0) {
			occur[i].push_back(1);
		}
	}

	int maxLength = 0;
	for(int j = 0; j < N; j++) {
		maxLength = max(maxLength, memo[j]);
	}

	set<int> distinct;
	vector<int> totalSum;
	for(int j = 0; j < N; j++) {
		if(memo[j] == maxLength) {
			if(!distinct.count(prices[j])) {
				addBig(totalSum, occur[j]);
				distinct.insert(prices[j]);
			}
		}
	}

	fout << maxLength << " "; 
	for(int i = totalSum.size() - 1; i >= 0; i--) {
		string temp = to_string(totalSum[i]);
		if(i != totalSum.size() - 1) {
			int numZeros = 6 - temp.size();
			for(int j = 0; j < numZeros; j++) {
				fout << 0;
			}
		}
		fout << temp;
	}
	fout << endl;
}
