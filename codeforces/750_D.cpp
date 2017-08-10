#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n;
vector<int> level;
bool grid[300][300];

int main() {
	cin >> n;
	level.resize(n);
	for(int i = 0; i < n; i++)
		cin >> level[i];
	vector<int> temp{150, 150, 0};
	deque<vector<int>> Q{temp};
	grid[150][150] = 1;
	int result = 1;
	for(int l = 0; l < level.size(); l++){
		for(int j = 0; j < level[l]; j++) {
			if(j == 0) {
				if(l == 0) continue;
				int qS = Q.size();	
				while(qS--) {
					vector<int> curr = Q.front();
					Q.pop_front();
					int t = curr[2];

					curr[2] = (t + 1) % 8;				
					Q.push_back(curr);
					curr[2] = (t + 8 - 1) % 8;
					Q.push_back(curr);
				}
			}
			for(int i = 0; i < Q.size(); i++) {
				vector<int> &temp = Q[i];				
				int &x = temp[0], &y = temp[1], &t = temp[2];

				if(t >= 7 or t <= 1) y++;
				else if(t >= 3 and t <= 5) y--;

				if(t >= 1 and t <= 3) x++;
				else if(t >= 5 and t <= 7) x--;

				if(!grid[x][y]) {
					grid[x][y] = 1;
					result++;
				}
			}
			if(j == 0) {
				sort(Q.begin(), Q.end());
				deque<vector<int>> newQ;
				while(!Q.empty()) {
					vector<int> &temp = Q.front();
					if(newQ.empty() or newQ.back() != temp)
						newQ.push_back(temp);
					Q.pop_front();
				}
				Q = move(newQ);
			}
		}
	}
	cout << result << endl;
}
