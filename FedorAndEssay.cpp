#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
#include <tuple>
#include <sstream>
#include <vector>

using namespace std;

typedef tuple<int, int, int> tpl;
typedef pair<int, int> pii;

int M, N;
string str, X, Y;
long long rCnt, totCnt;

void to_lower(string &S) {
	for(char &C : S)
		if(C >= 'A' and C <= 'Z') C = C - 'A' + 'a';
}

int count_r(string &S) {
	int result = 0;
	for(char C : S)
		if(C == 'r') result++;
	return result;
}

int main() {
	cin >> M;
	getline(cin, str);
	getline(cin, str);
	stringstream S(str);

	map<string, int> toIndex;
	vector<tpl> info;
	vector<pii> I;
	vector<string> words;
	int curr_I = 0;
	while(M--) {
		string word;
		S >> word;	
		to_lower(word);
		words.push_back(word);
		if(!toIndex.count(word)) {
			toIndex[word] = curr_I;
			int numR = count_r(word);
			info.emplace_back(numR, (int) word.size(), curr_I);
			I.emplace_back(numR, (int) word.size());
			curr_I++;
		}
	}
	cin >> N;
	vector<vector<int>> adjList(curr_I);
	for(int i = 0; i < N; i++) {
		cin >> X >> Y;
		to_lower(X);
		to_lower(Y);
		for(string Z : {X, Y}) {
			if(!toIndex.count(Z)) {
				toIndex[Z] = curr_I;	
				int numR = count_r(Z);
				info.emplace_back(numR, (int) Z.size(), curr_I);
				I.emplace_back(numR, (int) Z.size());
				curr_I++;
			}
		}
		if(curr_I >= adjList.size()) adjList.resize(curr_I);
		adjList[toIndex[Y]].push_back(toIndex[X]);
	}

	sort(info.begin(), info.end());	
	vector<bool> visited(curr_I);
	map<int, int> toBest;	
	for(tpl curr : info) {
		int numR = get<0>(curr);	
		int length = get<1>(curr);
		int i = get<2>(curr);
		if(visited[i]) continue;
		visited[i] = true;
		toBest[i] = i;
		vector<int> toVisit {i};
		while(!toVisit.empty()) {
			int curr = toVisit.back();
			toVisit.pop_back();
			for(int next : adjList[curr]) {
				if(visited[next] == 0) {
					visited[next] = 1;
					toBest[next] = i;
					toVisit.push_back(next);
				}
			}
		}
	}

	for(string Z : words) {
		rCnt += I[toBest[toIndex[Z]]].first;
		totCnt += I[toBest[toIndex[Z]]].second;	
	}
	cout << rCnt << " " << totCnt << endl;
}
