#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>

using namespace std;

typedef pair<int, int> pii;

pii lookup(string S, int i) {
	int curr = S[i] - '0';
	if(curr == 0) return make_pair(3, 1);
	pii result { (curr - 1) / 3, (curr - 1) % 3 };
	return result;
}

int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	
	bool hasSame = false;

	for(int r = 0; r < 4; r++) {
		for(int c = 0; c < 3; c++) {
			if(r == 3 and c != 1) continue;

			bool valid = true;
			pii start {r, c};
			if(start == lookup(S, 0)) continue;
			for(int i = 1; i < N; i++) {
				pii curr = lookup(S, i - 1);
				pii next = lookup(S, i);

				start.first += next.first - curr.first;
				start.second += next.second - curr.second;
				if(start.second >= 0 and start.second < 3 and 
					( (start.first >= 0 and start.first < 3) or (start.first == 3 and start.second == 1)))
					continue;
				else valid = false;
			}	
			if(valid) hasSame = true;

		}
	}

	cout << (hasSame ? "NO" : "YES") << endl;
}
