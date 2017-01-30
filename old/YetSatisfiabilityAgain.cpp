#include <iostream>
#include <cctype>
#include <string>
#include <cmath>
#include <utility>
#include <fstream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N;
	cin >> N;

	while(N--) {
		int n, m;	
		cin >> n >> m;

		string line;
		getline(cin, line);

		vector<pii> comp;
		for(int i = 0; i < m; i++) {
			getline(cin, line);
				
			bool isComplement = false;
			int A = 0;
			int B = 0;

			for(int j = 0; j < line.size(); j++) {
				char temp = line[j];
				if(temp == '~')
					isComplement = true;
				else if(temp == 'v')
					isComplement = false;
				else if(isdigit(temp)) {
					int curr = temp - '0';
					if(j + 1 < line.size() and isdigit(line[j + 1])) {
						curr *= 10;
						curr += line[j + 1] - '0';
						j++;
					}

					if(isComplement)
						B |= 1 << curr - 1;
					else 
						A |= 1 << curr - 1;	
				}

			}
			comp.emplace_back(A, B);
		}

		bool found = false;
		int maxVal = pow(2, n);
		for(int j = 0; j < maxVal; j++) {
			int k;
			for(k = 0; k < comp.size(); k++) {
				if(j & comp[k].first or ~j & comp[k].second)
					continue;
				else
					break;
			}
			if(k == comp.size()) {
				found = true;
				break;
			}
		}
		if(found == true)
			cout << "satisfiable" << endl;
		else
			cout << "unsatisfiable" << endl;
	}
}
