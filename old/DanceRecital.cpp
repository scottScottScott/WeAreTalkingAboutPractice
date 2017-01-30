#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	int R;
	cin >> R;

	vector< vector<bool> > routines(R);
	string line;
	getline(cin, line);
	for(int i = 0; i < R; i++) {
		vector<bool> currDancers(26);
		getline(cin, line);	
		for(int j = 0; j < line.size(); j++) {
			currDancers[line[j] - 'A'] = 1;
		}	
		routines[i] = currDancers;
	}

	vector<vector<int>> cntChanges(R, vector<int> (R));

	for(int i = 0; i < R; i++) {
		for(int j = i + 1; j < R; j++) {
			int changesNeeded = 0;	
			for(int k = 0; k < 26; k++) {
				if(routines[i][k] && routines[j][k])
					changesNeeded++;
			}
			cntChanges[i][j] = changesNeeded;	
			cntChanges[j][i] = changesNeeded;	
		}
	}

	vector<int> numberOrder(R);
	for(int i = 0; i < R; i++) {
		numberOrder[i] = i;
	}

	int minChanges = 1000000;
	do {
		int changesNeeded = 0;
		for(int i = 0; i < R - 1; i++) {
			int currIndex = numberOrder[i];
			int nextIndex = numberOrder[i + 1];
			changesNeeded += cntChanges[currIndex][nextIndex];
		}
		if(changesNeeded < minChanges)
			minChanges = changesNeeded;
	} while(next_permutation(numberOrder.begin(), numberOrder.end()));	

	cout << minChanges << endl;
}
