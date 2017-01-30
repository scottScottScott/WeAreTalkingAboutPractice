#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 5e5;

vector<vector<int>> C(MAX);
vector<vector<vector<int>>> memo(MAX);
vector<vector<int>> lvlIdx(MAX);
vector<int> letters(MAX), toI(MAX), toH(MAX);
int idx = 0;

void r_precompute(int oldIdx, int height) {
	vector<int> temp(26);
	if(!memo[height].empty()) {
		int last = memo[height].size() - 1;
		temp = memo[height][last];
	}
	int letter = letters[oldIdx];
	temp[letter]++;
	memo[height].push_back(temp);
	lvlIdx[height].push_back(idx);	
	toI[oldIdx] = idx;
	toH[oldIdx] = height;
	for(int x : C[oldIdx]) {
		idx++;
		r_precompute(x, height + 1);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i < n; i++) {
		int p;
		scanf("%d", &p);
		C[--p].push_back(i);
	}
	string temp;
	while(temp.empty())
		getline(cin, temp);
	for(int i = 0; i < n; i++)
		letters[i] = temp[i] - 'a';
	r_precompute(0, 0);
	while(m--) {
		int v, h;
		scanf("%d %d", &v, &h);
		v--; h--;
		int currIdx = toI[v];
		int H = toH[v];
		auto itr = upper_bound(lvlIdx[H].begin(), lvlIdx[H].end(), currIdx);
		int nxtIdx = itr != lvlIdx[H].end() ? *itr : idx + 1;

		int first = lower_bound(lvlIdx[h].begin(), lvlIdx[h].end(), currIdx) - lvlIdx[h].begin() - 1;
		int last = lower_bound(lvlIdx[h].begin(), lvlIdx[h].end(), nxtIdx) - lvlIdx[h].begin() - 1;
		if(lvlIdx[h].empty() or last == -1 or h < H) {
			printf("Yes\n");
			continue;
		}
		int valid = 0;
		for(int i = 0; i < 26; i++) {
			int val = memo[h][last][i] - (first == -1 ? 0 : memo[h][first][i]);	
			valid += val % 2;	
		}
		printf(valid <= 1 ? "Yes\n" : "No\n");
	}
}
