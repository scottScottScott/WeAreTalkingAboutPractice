#include <iostream>
#include <deque>
#include <utility>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N;
	cin >> N;
	vector<deque<int>> P(2);
	for(int i = 0; i < 2; i++) {
		int size;
		cin >> size;
		P[i].resize(size);
		for(int j = 0; j < P[i].size(); j++)
			cin >> P[i][j];
	}

	set<string> S;
	int count = 0;
	int winner = 0;
	while(true) {
		if(P[0].empty()) {
			winner = 2;
			break;
		}
		if(P[1].empty()) {
			winner = 1;
			break;
		}

		string temp;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < P[i].size(); j++) {
				temp += P[i][j] - 1 + '0';	
			}
			if(i == 0) temp += '|';
		}
		if(S.count(temp)) break;
		S.insert(temp);
		count++;

		for(pii curr : { make_pair(0, 1), make_pair(1, 0) }) {	
			int a = curr.first;
			int b = curr.second;
			if(P[a].front() > P[b].front()) {
				P[a].push_back(P[b].front());
				P[a].push_back(P[a].front());
				P[b].pop_front();
				P[a].pop_front();
				break;		
			}
		}
	}

	if(winner == 0) cout << -1 << endl;
	else cout << count << " " << winner << endl;
}
