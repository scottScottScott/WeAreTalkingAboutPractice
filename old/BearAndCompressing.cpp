#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int N, Q;	
	cin >> N >> Q;
	unordered_map<char, vector<string>> M;	
	for(int i = 0; i < Q; i++) {
		string first;
		char second;
		cin >> first >> second;
		reverse(first.begin(), first.end());
		M[second].push_back(first);
	}
	deque<string> A{"a"};
	while(!A.empty() and A[0].size() < N) {
		set<string> S;
		while(!A.empty()) {
			string curr = A.front();
			A.pop_front();
			for(string X : M[curr[curr.size() - 1]]) {
				string new_str = curr;
				new_str[new_str.size() - 1] = X[0];	
				new_str += X[1];
				S.insert(new_str);
			}
		}
		A.assign( S.begin(), S.end() );
	}
	cout << A.size() << endl;
}
