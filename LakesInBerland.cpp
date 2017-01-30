#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m, k;
bool water[50][50];
vector<vector<bool>> V;

int visit(int r, int c) {
	if(!water[r][c] or V[r][c])
		return 0;
	int count = 0;
	deque<pii> Q{make_pair(r, c)};
	V[r][c] = 1;
	while(!Q.empty()) {
		pii curr = Q.front();
		Q.pop_front();
		count++;
		for(pii shift : vector<pii> {pii{1, 0}, pii{-1, 0}, pii{0, -1}, pii{0, 1}}) {
			pii next{curr.first + shift.first, curr.second + shift.second};
			if(next.first < 0 or next.first >= n or next.second < 0 or next.second >= m 
				or V[next.first][next.second] or !water[next.first][next.second])
				continue;
			Q.push_back(next);
			V[next.first][next.second] = 1;
		}	
	}
	return count;
}

void erase(int r, int c) {
	deque<pii> Q{make_pair(r, c)};
	water[r][c] = 0;
	while(!Q.empty()) {
		pii curr = Q.front();
		Q.pop_front();
		for(pii shift : vector<pii> {pii{1, 0}, pii{-1, 0}, pii{0, 1}, pii{0, -1}}) {
			pii next{curr.first + shift.first, curr.second + shift.second};
			if(next.first < 0 or next.first >= n or next.second < 0 or next.second >= m or !water[next.first][next.second])
				continue;
			Q.push_back(next);
			water[next.first][next.second] = 0;
		}
	}
}


int main() {
	cin >> n >> m >> k;
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++) {
			char temp;
			cin >> temp;
			water[r][c] = (temp == '.');
		}
	}
	V.resize(n, vector<bool>(m));
	for(int c = 0; c < m; c++) {
		for(int r : vector<int> {0, n - 1})
			visit(r, c);
	}
	for(int r = 0; r < n; r++) {
		for(int c : vector<int> {0, m - 1})
			visit(r, c);
	}
	vector<vector<int>> islands;
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++) {
			int size = visit(r, c);
			if(size > 0)
				islands.push_back(vector<int> {size, r, c});
		}
	}

	int remove = islands.size() - k;
	sort(islands.rbegin(), islands.rend());	
	int result = 0;
	while(remove--) {
		vector<int> temp = islands.back();
		islands.pop_back();
		result += temp[0];
		erase(temp[1], temp[2]);
	}

	cout << result << endl;
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++)
			cout << (water[r][c] ? '.' : '*');
		cout << endl;
	}
}
