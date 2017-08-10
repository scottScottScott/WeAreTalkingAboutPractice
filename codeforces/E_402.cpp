#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string line;
	getline(cin, line);
	map<string, int> M {{"?", 0}};
	vector<vector<string>> info(n + 1); 
	for(int i = 1; i <= n; i++) {
		getline(cin, line);
		istringstream iss(line);	
		string first, eat, second, op, third;
		iss >> first >> eat >> second >> op >> third;
		M[first] = i;
		if(op.empty())
			info[i].push_back(second);
		else {
			info[i].push_back(to_string(M[second]));
			info[i].push_back(op);
			info[i].push_back(to_string(M[third]));
		}
	}
	string minS, maxS;
	for(int place = 0; place < m; place++) {
		vector<int> val(n + 1);
		vector<int> total(2);
		for(int x : {0, 1}) {
			val[0] = x;
			for(int i = 1; i <= n; i++) {
				if(info[i].size() == 1)
					val[i] = info[i][0][place] - '0';
				else {
					int first = val[stoi(info[i][0])];
					string op = info[i][1];
					int second = val[stoi(info[i][2])];
					if(op == "AND") val[i] = first & second;
					else if(op == "OR") val[i] = first | second;
					else val[i] = first ^ second;
				}
				total[x] += val[i];
			}
		}

		if(total[0] == total[1]) {
			minS += "0";
			maxS += "0";
		}
		else if(total[0] > total[1]){
			maxS += "0";
			minS += "1";	
		}
		else {
			maxS += "1";
			minS += "0";
		}
	} 
	cout << minS << endl;
	cout << maxS << endl;
}
