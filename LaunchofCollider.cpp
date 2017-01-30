#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	string eat;	
	getline(cin, eat);
	string move;
	getline(cin, move);
	vector<int> position(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &position[i]);
	int prevR = -1;
	int result = INT_MAX;
	for(int i = 0; i < n; i++) {
		if(move[i] == 'R') prevR = position[i];	
		else {
			if(prevR == -1) continue;
			else {
				result = min(result, (position[i] - prevR) / 2);
				prevR = -1;
			}
		}
	}
	cout << (result == INT_MAX ? -1 : result) << endl;
}
