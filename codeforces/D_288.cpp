#include <string>
#include <deque>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

int toI(string s) {
	return (s[0] - '0') * 256 + (s[1] - '0');
}

string toS(int i) {
	string result(1, '0' + i / 256);
	result += (char) ('0' + i % 256);
	return result;
}

pii getNodes(string s) {
	return pii{toI(s.substr(0, 2)), toI(s.substr(1, 2))};
}

int main() {
	int n;
	cin >> n;
	string temp;
	getline(cin, temp);
	vvi aL(256 * 256);
	map<int, int> C;
	set<int> V;
	for(int i = 0; i < n; i++) {
		getline(cin, temp);
		pii nodes = getNodes(temp);
		aL[nodes.first].push_back(nodes.second);
		C[nodes.second]++;
	}
	
	int start = -1;	
	vector<int> cType(3);
	bool valid = true;
	for(int i = 0; i < aL.size(); i++) {
		if(aL[i].empty()) continue;
		if(start == -1 or aL[i].size() - C[i] == 1)
			start = i;
		int diff = aL[i].size() - C[i];
		if(diff < -1 or diff > 1) {
			valid = false;
			break;
		}
		cType[diff + 1]++;
	}	
	if(cType[0] > 1 or cType[2] > 1) 
		valid = false;

	deque<int> Q{start};	
	V.insert(start);
	while(!Q.empty()) {
		int curr = Q.front();
		Q.pop_front();
		for(int j : aL[curr]) {
			if(V.count(j)) continue;
			V.insert(j);
			Q.push_back(j);
		}
	}
	for(int i = 0; i < aL.size(); i++) {
		if(!aL[i].empty() and !V.count(i))
			valid = false;
	}

	if(!valid) {
		cout << "NO" << endl;
		return 0;
	}

	vector<int> P, revP;	
	P.push_back(start);
	while(!P.empty()) {
		int curr = P.back();
		if(!aL[curr].empty()) {
			int next = aL[curr].back();	
			aL[curr].pop_back();
			P.push_back(next);
		}
		else {
			revP.push_back(curr);
			P.pop_back();
		}
	}
	reverse(revP.begin(), revP.end());
	cout << "YES" << endl;
	string result = toS(revP[0]);
	for(int i = 1; i < revP.size(); i++)
		result += toS(revP[i])[1];
	cout << result << endl;
}
