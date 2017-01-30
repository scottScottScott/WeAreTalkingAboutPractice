#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string getBest(int j, string A) {
	for(int i = j; i < A.size(); i++)
		if(A[i] == '?') A[i] = '0';
	return A;
}

int main() {
	int n;	
	cin >> n;
	vector<string> result;
	string curr;
	cin >> curr;
	for(int i = 0; i < curr.size(); i++) {
		if(curr[i] == '?') 
			curr[i] = (i == 0 ? '1' : '0');
	}
	result.push_back(curr);
	for(int i = 1; i < n; i++) {
		curr = result.back();
		bool valid = true;
		string next;
		cin >> next;
		if(next.size() < curr.size())
			valid = false;
		else if(next.size() == curr.size()) {
			string best;
			for(int j = 0; j < next.size(); j++) {
				if(next[j] == curr[j]) 
					continue;
				else if(next[j] == '?') {
					if(curr[j] != '9') {
						next[j] = curr[j] + 1;
						best = getBest(j + 1, next);
					}
					next[j] = curr[j];
				}
				else if(next[j] > curr[j]) {
					best = getBest(j + 1, next);	
					break;
				}
				else if(next[j] < curr[j])
					break;
			}
			if(best.empty())
				valid = false;
			next = best;
		}
		else {
			for(int j = 0; j < next.size(); j++) {
				if(next[j] == '?')
					next[j] = (j == 0 ? '1' : '0');
			}
		}
		if(valid == false) {
			cout << "NO" << endl;
			return 0;
		}
		result.push_back(next);
	}

	cout << "YES" << endl;
	for(string x : result)
		cout << x << endl;
}
