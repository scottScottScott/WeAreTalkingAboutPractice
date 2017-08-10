#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
	vector<pii> p(3);
	cin >> p[0].first >> p[0].second >> p[1].first >> p[1].second >> p[2].first >> p[2].second;
	if(p[0].first == p[1].first and p[1].first == p[2].first) {
		cout << 1 << endl;
		return 0;
	}
	if(p[0].second == p[1].second and p[1].second == p[2].second) {
		cout << 1 << endl;
		return 0;
	}
	for(int i = 0; i < 3; i++) {	
		for(int j = 0; j < 3; j++) {
			if(i == j) continue;
			int k = 0;
			while(k == i or k == j) k++;
			vector<vector<int>> temp;
			temp.push_back(vector<int> {p[i].first, p[j].first, p[k].first});
			temp.push_back(vector<int> {p[i].second, p[j].second, p[k].second});
			for(int a : {0, 1}) {
				int b = !a;
				if(temp[a][0] == temp[a][1]) {
					int lo = min(temp[b][0], temp[b][1]); 
					int hi = max(temp[b][0], temp[b][1]);
					if(temp[b][2] <= lo or temp[b][2] >= hi) {
						cout << 2 << endl;
						return 0;	
					}
				}
			}
		}
	}
	cout << 3 << endl;
}
