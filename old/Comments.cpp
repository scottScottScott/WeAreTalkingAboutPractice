#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	string S;	
	cin >> S;
	vector<vector<string>> layers;
	int currL = 0;
	vector<int> levels;	
	int i = 0;
	while(i < S.size()) {
		string temp;
		while(S[i] != ',') {
			temp += S[i];
			i++;
		}
		i++;
		int cdrn = 0;
		while(i < S.size() and S[i] != ',') {
			cdrn *= 10;
			cdrn += S[i] - '0';
			i++;
		}
		i++;

		if(currL >= layers.size())
			layers.push_back(vector<string> {});
		layers[currL].push_back(temp);

		if(cdrn > 0)
			levels.push_back(cdrn);
		else {
			while(levels.size() > 0) {
				levels.back()--;
				if(levels.back() == 0)
					levels.pop_back();
				else
					break;
			}
		}
		currL = levels.size();
	} 

	cout << layers.size() << endl;
	for(vector<string> &V : layers) {
		int n = V.size();
		for(int i = 0; i < n; i++)
			cout << V[i] << (i + 1 == n ? "\n" : " ");
	}
}
