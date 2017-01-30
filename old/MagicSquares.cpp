#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;

int main() {
	ifstream fin("msquare.in"); 	
	ofstream fout("msquare.out"); 	

	string target;
	char c;
	while(fin >> c) {
		target += c;
	}
	cout << target << endl;
	string init = "12345678";
	unordered_map<string, string> seen;
	unordered_map<string, char> path;
	deque<string> toVisit;
	toVisit.push_back(init);
	seen[init] = "00000000";
	while(!toVisit.empty()) {
		string curr = toVisit.front();
		toVisit.pop_front();

		if(curr == target) {
				string ret;
				while(curr != "12345678") {
					ret = path[curr] + ret;
					curr = seen[curr];
				}
				fout << ret.length() << endl;
				int i = 0;
				while(i < ret.length()) {
					if(i % 60 == 0 && i != 0)
						fout << endl;
					fout << ret[i];
					i++;
				}
				fout << endl;
				return 0;
			}

		vector<string> next(3, string(8, '0'));
		for(int i = 0; i < 8; i++) {
			next[0][i] = curr[8 - 1 - i];

			if(i == 0)
				next[1][0] = curr[3];
			else if(i < 4)
				next[1][i] = curr[i - 1];
			else if( i < 7)
				next[1][i] = curr[i + 1];
			else
				next[1][7] = curr[4];

			if(i == 0 || i == 3 || i == 4 || i == 7)
				next[2][i] = curr[i];
			else if(i == 1)
				next[2][1] = curr[6];
			else if(i == 2)
				next[2][2] = curr[1];
			else if(i == 5)
				next[2][5] = curr[2];
			else if(i == 6)
				next[2][6] = curr[5];
		}

		for(int i = 0; i < 3; i++) {
			if(!seen.count(next[i])) {
				seen[next[i]] = curr;	
				path[next[i]] = 'A' + i;	
				toVisit.push_back(next[i]);
			}
		}
	}
	return 0;
}
