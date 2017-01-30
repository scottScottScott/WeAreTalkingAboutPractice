#include <iostream>
#include <set>
#include <utility>
#include <deque>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<vector<char>> board;
vector<vector<int>> memo;

int dfs(int r, int c) {
	if(memo[r][c] != -1)	
		return memo[r][c];
	memo[r][c] = -2;
	int temp = 0;
	char C = board[r][c];
	if(C == '^')
		temp = dfs(r - 1, c);
	else if(C == '>')
		temp = dfs(r, c + 1);
	else if(C == 'v')
		temp = dfs(r + 1, c);
	else if(C == '<')
		temp = dfs(r, c - 1);
	memo[r][c] = temp == -2 ? temp : 1 + temp;
	return memo[r][c];
}

int main() {
	cin >> n >> m;
	board.resize(n, vector<char>(m));
	memo.resize(n, vector<int>(m, -1));
	string eat;
	getline(cin, eat);
	for(int r = 0; r < n; r++) {
		string curr_line;
		getline(cin, curr_line);
		for(int c = 0; c < m; c++) {
			board[r][c] = curr_line[c];
			if(board[r][c] == '#')
				memo[r][c] = 0;
		}
	}
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++) {
			dfs(r, c);
			if(memo[r][c] == -2) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	
	int maxVal = 0;	
	vector<pii> best;
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++) {
			if(memo[r][c] > maxVal) {
				maxVal = memo[r][c];
				best.clear();
				best.emplace_back(r, c);
			}
			else if(memo[r][c] == maxVal)
				best.emplace_back(r, c);
		}
	}

	if(maxVal == 0) {
		cout << 0 << endl;
		return 0;
	}

	for(int i = 0; i < maxVal - 1; i++) {
		set<pii> S;	
		for(pii temp : best) {
			char C = board[temp.first][temp.second];
			if(C == '^')
				S.emplace(temp.first - 1, temp.second);	
			else if(C == '>')
				S.emplace(temp.first, temp.second + 1);
			else if(C == 'v')
				S.emplace(temp.first + 1, temp.second);
			else
				S.emplace(temp.first, temp.second - 1);
		}
		best.assign(S.begin(), S.end());
	}

	cout << (best.size() == 1 ? maxVal * 2 - 1 : maxVal * 2) << endl;
}
