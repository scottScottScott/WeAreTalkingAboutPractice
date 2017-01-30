#include <iostream>
#include <vector>

using namespace std;

int n, m, q;
int total;
vector<vector<bool>> state(1000, vector<bool>(1000));
vector<int> memo;
vector<vector<int>> info, Next;

void dfs(int i) {
	for(int y : Next[i]) {
		vector<int> temp = info[y];
		bool moved = false;
		int r, c;
		r = c = -1;
		switch(temp[0]) {
			case 1: {
				r = temp[1];
				c = temp[2];
				if(state[r][c] == 0) {
					state[r][c] = 1;
					total++;
					moved = true;
				}
				break;
			}
			case 2: {
				r = temp[1];
				c = temp[2];
				if(state[r][c] == 1) {
					state[r][c] = 0;
					total--;
					moved = true;
				}
				break;
			}
			case 3: {
				r = temp[1];
				for(int j = 0; j < m; j++) {
					if(state[r][j] == 1) {
						state[r][j] = 0;
						total--;
					}
					else if(state[r][j] == 0) {
						state[r][j] = 1;
						total++;
					}
				}
				break;
			}
		}
		memo[y] = total;
		dfs(y);
		switch(temp[0]) {
			case 1: {
				if(moved) {
					state[r][c] = 0;
					total--;
				}
				break;
			}
			case 2: {
				if(moved) {
					state[r][c] = 1;
					total++;
				}
				break;
			}
			case 3: {
				for(int j = 0; j < m; j++) {
					if(state[r][j] == 1) {
						state[r][j] = 0;
						total--;
					}
					else if(state[r][j] == 0) {
						state[r][j] = 1;
						total++;
					}
				}
				break;
			}
		}
	}
}

int main() {
	cin >> n >> m >> q;
	info.resize(q + 1);
	Next.resize(q + 1);
	memo.resize(q + 1);
	info[0].push_back(0);
	int curr = 0;
	for(int i = 1; i <= q; i++) {
		vector<int> temp;
		int type;
		cin >> type;
		if(type == 1 or type == 2) {
			int r, c;
			cin >> r >> c;
			r--, c--;
			vector<int> temp{type, r, c};	
			info[i] = temp;
			Next[curr].push_back(i);
		}
		else if(type == 3) {
			int r;
			cin >> r;
			r--;
			vector<int> temp{type, r};
			info[i] = temp;
			Next[curr].push_back(i);			
		}	
		else {
			int k;
			cin >> k;
			vector<int> temp{type, k};
			info[i] = temp;
			Next[k].push_back(i);
		}
		curr = i;
	}
	dfs(0);
	for(int i = 1; i <= q; i++)
		cout << memo[i] << endl;
}
